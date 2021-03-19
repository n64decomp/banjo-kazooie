#include <ultra64.h>
#include "n_synth.h"
#include <assert.h>

#include "seqp.h"
#include "n_cseqp.h"
#include "cseq.h"

#ifndef assert
#define assert(s) 
#endif

static ALMicroTime      __n_CSPVoiceHandler(void *node);
static void		__n_CSPHandleNextSeqEvent(N_ALCSPlayer *seqp);
static void             __n_CSPHandleMIDIMsg(N_ALCSPlayer *seqp, N_ALEvent *event);
static void             __n_CSPHandleMetaMsg(N_ALCSPlayer *seqp, N_ALEvent *event);
static void             __n_CSPRepostEvent(ALEventQueue *evtq, N_ALEventListItem *item);
static void		__n_setUsptFromTempo(N_ALCSPlayer *seqp, ALCSeq *target, f32 tempo);		/* sct 1/8/96 */


/*
 * Sequence Player public functions
 */
/*done*/
void n_alCSPNew(N_ALCSPlayer *seqp, ALSeqpConfig *c)
{
    s32                 i;
    N_ALEventListItem     *items;
    N_ALVoiceState        *vs;
    N_ALVoiceState        *voices;
    
    ALHeap *hp = c->heap;    

    /*
     * initialize member variables
     */
    seqp->bank          = 0;
    seqp->target        = NULL;
    seqp->drvr          = D_80276E84;
    seqp->chanMask      = 0xffff;
    seqp->uspt          = 488;
    seqp->nextDelta     = 0;
    seqp->state         = AL_STOPPED;
    seqp->vol           = 0x7FFF;              /* full volume  */
    seqp->debugFlags    = c->debugFlags;
    seqp->frameTime     = AL_USEC_PER_FRAME; /* should get this from driver */
    seqp->curTime       = 0;
    seqp->initOsc       = c->initOsc;
    seqp->updateOsc     = c->updateOsc;
    seqp->stopOsc       = c->stopOsc;
    
    seqp->nextEvent.type = AL_SEQP_API_EVT;	/* this will start the voice handler "spinning" */
    
    /*
     * init the channel state
     */
    seqp->maxChannels = c->maxChannels;
    seqp->chanState = alHeapAlloc(hp, c->maxChannels, sizeof(ALChanState) );
    __initChanState((ALSeqPlayer*)seqp);	/* sct 11/6/95 */
    
    /*
     * init the voice state array
     */
    voices = alHeapAlloc(hp, c->maxVoices, sizeof(ALVoiceState));
    seqp->vFreeList = 0;
    for (i = 0; i < c->maxVoices; i++) {
        vs = &voices[i];
        vs->next = seqp->vFreeList;
        seqp->vFreeList = vs;        
    }
    
    seqp->vAllocHead = 0;
    seqp->vAllocTail = 0;    
        
    /*
     * init the event queue
     */
    items = alHeapAlloc(hp, c->maxEvents, sizeof(ALEventListItem));
    alEvtqNew(&seqp->evtq, items, c->maxEvents);

    
    /*
     * add ourselves to the driver
     */
    seqp->node.next       = NULL;
    seqp->node.handler    = __n_CSPVoiceHandler;
    seqp->node.clientData = seqp;
    n_alSynAddPlayer(&seqp->node);  
}

/*************************************************************
 * private routines or driver callback routines
 *************************************************************/
static ALMicroTime __n_CSPVoiceHandler(void *node)
{
    N_ALCSPlayer      *seqp = (N_ALCSPlayer *) node;
    N_ALEvent         evt;
    ALVoice         *voice;
    ALMicroTime     delta;
    ALVoiceState	*vs;
    void            *oscState;
    f32             oscValue;
    u8              chan;
    do {
        switch (seqp->nextEvent.type)
        {
        case (AL_SEQ_REF_EVT):
            __n_CSPHandleNextSeqEvent(seqp);
            break;

        case (AL_SEQP_API_EVT):
            evt.type = AL_SEQP_API_EVT;
            alEvtqPostEvent(&seqp->evtq, (ALEvent *)&evt, seqp->frameTime);
            break;

        case (AL_NOTE_END_EVT):
            voice = seqp->nextEvent.msg.note.voice;

            n_alSynStopVoice(voice);
            n_alSynFreeVoice(voice);
            vs = (ALVoiceState *)voice->clientPrivate;
            if(vs->flags)
            __seqpStopOsc((ALSeqPlayer*)seqp,vs);
            __unmapVoice((ALSeqPlayer*)seqp, voice); 
            break;

        case (AL_SEQP_ENV_EVT):
            voice = seqp->nextEvent.msg.vol.voice;
            vs = (ALVoiceState *)voice->clientPrivate;

            if(vs->envPhase == AL_PHASE_ATTACK)
            vs->envPhase = AL_PHASE_DECAY;

            delta = seqp->nextEvent.msg.vol.delta;
            vs->envEndTime = seqp->curTime + delta;
            vs->envGain = seqp->nextEvent.msg.vol.vol;
            n_alSynSetVol(voice, __vsVol(vs, (ALSeqPlayer*)seqp), delta);
            break;
                    
        case (AL_TREM_OSC_EVT):
            vs = seqp->nextEvent.msg.osc.vs;
            oscState = seqp->nextEvent.msg.osc.oscState;
            delta = (*seqp->updateOsc)(oscState,&oscValue);
            vs->tremelo = (u8)oscValue;
            n_alSynSetVol(&vs->voice, __vsVol(vs,(ALSeqPlayer*)seqp),
                __vsDelta(vs,seqp->curTime));
            evt.type = AL_TREM_OSC_EVT;
            evt.msg.osc.vs = vs;
            evt.msg.osc.oscState = oscState;
            alEvtqPostEvent(&seqp->evtq, &evt, delta);
            break;
                    
        case (AL_VIB_OSC_EVT):
            vs = seqp->nextEvent.msg.osc.vs;
            oscState = seqp->nextEvent.msg.osc.oscState;
            chan = seqp->nextEvent.msg.osc.chan;
            delta = (*seqp->updateOsc)(oscState,&oscValue);
            vs->vibrato = oscValue;
            n_alSynSetPitch(&vs->voice, vs->pitch * vs->vibrato
                * seqp->chanState[chan].pitchBend);
            evt.type = AL_VIB_OSC_EVT;
            evt.msg.osc.vs = vs;
            evt.msg.osc.oscState = oscState;
            evt.msg.osc.chan = chan;
            alEvtqPostEvent(&seqp->evtq, &evt, delta);
            break;

        case (AL_SEQP_MIDI_EVT):
        case (AL_CSP_NOTEOFF_EVT):			/* nextEvent is a note off midi message */
            __n_CSPHandleMIDIMsg(seqp, &seqp->nextEvent);
            break;

        case (AL_SEQP_META_EVT):
            __n_CSPHandleMetaMsg(seqp, &seqp->nextEvent);
            break;

        case (AL_SEQP_VOL_EVT):
            seqp->vol =  seqp->nextEvent.msg.spvol.vol;
            for (vs = seqp->vAllocHead; vs != 0; vs = vs->next)
            {
            n_alSynSetVol(&vs->voice,
                                __vsVol(vs, (ALSeqPlayer*)seqp),
                                __vsDelta(vs, seqp->curTime));
            }
            break;

        case (AL_SEQP_PLAY_EVT):
            if (seqp->state != AL_PLAYING)
            {
            seqp->state = AL_PLAYING;
            func_80250650();
            __n_CSPPostNextSeqEvent(seqp);	/* seqp must be AL_PLAYING before we call this routine. */
            }
            break;

        case (AL_SEQP_STOP_EVT):
            if ( seqp->state == AL_STOPPING )
            {
            for (vs = seqp->vAllocHead; vs != 0; vs = seqp->vAllocHead)
            {
    #ifdef _DEBUG
                        __osError(ERR_ALCSPVNOTFREE, 2, vs->channel, vs->key);
    #endif                    
		    n_alSynStopVoice(&vs->voice);
		    n_alSynFreeVoice(&vs->voice);
		    if(vs->flags)
			__seqpStopOsc((ALSeqPlayer*)seqp,vs);
		    __unmapVoice((ALSeqPlayer*)seqp, &vs->voice); 
		}
		seqp->state = AL_STOPPED;

		/* alEvtqFlush(&seqp->evtq); - Don't flush event queue
                   anymore. */
		/* sct 1/3/96 - Don't overwrite nextEvent with
		   AL_SEQP_API_EVT or set nextDelta to
		   AL_USEC_PER_FRAME since we're not stopping event
		   processing. */
		/* sct 1/3/96 - Don't return here since we keep
                   processing events as usual. */
	    }
	    break;

        case (AL_SEQP_STOPPING_EVT):
            if (seqp->state == AL_PLAYING)
            {
            /* sct 12/29/95 - Remove events associated with the
                    * stopping sequence.  For compact sequence player,
                    * also remove all queued note off events since they
                    * are not contained in a compact sequence but are
                    * generated in response to note ons.  Note that
                    * flushing AL_SEQP_MIDI_EVTs may flush events that
                    * were posted after the call to alSeqpStop, so the
                    * application must queue these events either when
                    * the player is fully stopped, or when it is
                    * playing. */
            alEvtqFlushType(&seqp->evtq, AL_SEQ_REF_EVT);
            alEvtqFlushType(&seqp->evtq, AL_CSP_NOTEOFF_EVT);
            alEvtqFlushType(&seqp->evtq, AL_SEQP_MIDI_EVT);

            /* sct 1/3/96 - Check to see which voices need to be
                    killed and release them. */
            /* Unkilled voices should have note end events
                    occurring prior to KILL_TIME. */
            for (vs = seqp->vAllocHead; vs != 0; vs = vs->next)
            {
                if (__voiceNeedsNoteKill ((ALSeqPlayer*)seqp, &vs->voice, KILL_TIME))
                __seqpReleaseVoice((ALSeqPlayer*)seqp, &vs->voice, KILL_TIME);
            }

            seqp->state = AL_STOPPING;
            evt.type = AL_SEQP_STOP_EVT;
            alEvtqPostEvent(&seqp->evtq, &evt, AL_EVTQ_END);
            }
            break;

        case (AL_SEQP_PRIORITY_EVT):
            chan = seqp->nextEvent.msg.sppriority.chan;
            seqp->chanState[chan].priority = seqp->nextEvent.msg.sppriority.priority;
            break;

        case (AL_SEQP_SEQ_EVT):
            //assert(seqp->state != AL_PLAYING);	/* Must be done playing to change sequences. */
            ((seqp->state != AL_PLAYING)?((void)0):func_8033F000("seqp->state != AL_PLAYING","n_csplayer.c", 272));

            seqp->target = seqp->nextEvent.msg.spseq.seq;
            seqp->chanMask = 0xFFFF;
            if (seqp->bank)
            __initFromBank((ALSeqPlayer *)seqp, seqp->bank);
            break;

        case (AL_SEQP_BANK_EVT):
            //assert(seqp->state == AL_STOPPED);	/* Must be fully stopped to change banks. */
            ((seqp->state == AL_STOPPED)?((void)0):func_8033F000("seqp->state == AL_STOPPED","n_csplayer.c", 283));
        
            seqp->bank = seqp->nextEvent.msg.spbank.bank;
            __initFromBank((ALSeqPlayer *)seqp, seqp->bank);
            break;

            /* sct 11/6/95 - these events should now be handled by __n_CSPHandleNextSeqEvent */
        case (AL_SEQ_END_EVT):
        case (AL_TEMPO_EVT):
        case (AL_SEQ_MIDI_EVT):
            //assert(FALSE);	
            ((FALSE)?((void)0):func_8033F000("FALSE","n_csplayer.c", 296));
            break;
            }
            seqp->nextDelta = alEvtqNextEvent(&seqp->evtq, &seqp->nextEvent); 
        
    } while (seqp->nextDelta == 0);

    /*
     * assume that next callback won't be more than half an
     * hour away
     */
    seqp->curTime += seqp->nextDelta;		/* sct 11/7/95 */
    return seqp->nextDelta;
}

/*
 Calculates the delta time in ticks until the next sequence
 event and posts a sequence reference event with the time in usecs.
 Loops are handled automatically by the compact sequence.
 Does nothing if the sequence player is not playing or if there
 is no target sequence.
 sct 11/7/95
*/
/*DONE*/
void __n_CSPPostNextSeqEvent(N_ALCSPlayer *seqp) 
{
    ALEvent     evt;
    s32		deltaTicks;
    
    if (seqp->state != AL_PLAYING || seqp->target == NULL)
        return;
    
    /* Get the next event time in ticks. */
    /* If false is returned, then there is no next delta (ie. end of sequence reached). */
    if (!__alCSeqNextDelta(seqp->target, &deltaTicks))
	return;
        
    evt.type = AL_SEQ_REF_EVT;
    alEvtqPostEvent(&seqp->evtq, &evt, deltaTicks * seqp->uspt);                
}


/*
  Call this routine to handle the next event in the sequence.
  Assumes that the next sequence event is scheduled to be processed
  immediately since it does not check the event's tick time.
  sct 11/7/95
*/
static void
__n_CSPHandleNextSeqEvent(N_ALCSPlayer *seqp)
{
    ALEvent	evt;

    /* sct 1/5/96 - Do nothing if we don't have a target sequence. */
    if (seqp->target == NULL)
	return;

    alCSeqNextEvent(seqp->target, &evt);

    switch (evt.type)
    {
      case AL_SEQ_MIDI_EVT:
        __n_CSPHandleMIDIMsg(seqp, &evt);
	    __n_CSPPostNextSeqEvent(seqp);
	    break;

      case AL_TEMPO_EVT:
        __n_CSPHandleMetaMsg(seqp, &evt);
        __n_CSPPostNextSeqEvent(seqp);
        break;

      case AL_SEQ_END_EVT:
	  seqp->state = AL_STOPPING;      
	  evt.type    = AL_SEQP_STOP_EVT;
	  alEvtqPostEvent(&seqp->evtq, &evt, AL_EVTQ_END);
	  break;

      case AL_TRACK_END:
      case AL_CSP_LOOPSTART:
      case AL_CSP_LOOPEND:
	  __n_CSPPostNextSeqEvent(seqp);
	  break;
	  
      default:
	  //assert(FALSE);	/* Sequence event type not supported. */
      ((FALSE)?((void)0):func_8033F000("FALSE","n_csplayer.c", 353));
        break;
    }
}


static void __n_CSPHandleMIDIMsg(N_ALCSPlayer *seqp, N_ALEvent *event)
{
    N_ALVoice             *voice;
    N_ALVoiceState        *vs;
    s32                 status;
    u8                  chan;
    u8                  key;
    u8                  vel;
    u8                  byte1;
    u8                  byte2;
    ALMIDIEvent         *midi = &event->msg.midi;
    s16                 vol;
    N_ALEvent             evt;
    ALMicroTime         deltaTime;
    N_ALVoiceState        *vstate;
    ALPan   		    pan;
    ALFxRef		        fxref;

    
    status = midi->status & AL_MIDI_StatusMask;
    chan = midi->status & AL_MIDI_ChannelMask;
    byte1 = key  = midi->byte1;
    byte2 = vel  = midi->byte2;

    if(status == AL_MIDI_ChannelModeSelect){
            if(byte1 == 0x7E){
                seqp->chanMask &= ~(1 << byte2);
                vstate = seqp->vAllocHead;
                while(vs){
                    if(vstate->channel == byte2){
                        __seqpReleaseVoice(seqp, &vstate->voice.node.next, vstate->sound->envelope->releaseTime);
                    }
                    vs = vs->next;
                }
                return;
            }else if(byte1 == 0x7F){
                seqp->chanMask |= (1 << byte2);
                return;
            }
    }

    if(!((seqp->chanMask & (1 << chan))  || status != AL_MIDI_NoteOn))
        return;
    
    //L8025DB08
    switch (status)
    {
        case (AL_MIDI_NoteOn):

            if (vel != 0)		/* a real note on */
            {
                ALVoiceConfig   config;
                ALSound         *sound;
                s16             cents;
                f32             pitch,oscValue;
                u8              fxmix;
                void            *oscState;
                ALInstrument    *inst;
                
                /* If we're not playing, don't process note ons. */
                if (seqp->state != AL_PLAYING)
                    break;

                sound = __lookupSoundQuick((ALSeqPlayer*)seqp, key, vel, chan);
                ALFlagFailIf(!sound, seqp->debugFlags & NO_SOUND_ERR_MASK,
                ERR_ALSEQP_NO_SOUND); 
                
                config.priority = seqp->chanState[chan].priority;
                config.fxBus    = 0;
                config.unityPitch = 0;
                
                vstate = __mapVoice((ALSeqPlayer*)seqp, key, vel, chan);
                ALFlagFailIf(!vstate, seqp->debugFlags & NO_VOICE_ERR_MASK,
            ERR_ALSEQP_NO_VOICE );

                voice = &vstate->voice;
                n_alSynAllocVoice(voice, &config);
                
                /*
                * set up the voice state structure
                */
                vstate->sound = sound;
                vstate->envPhase = AL_PHASE_ATTACK;
                if (seqp->chanState[chan].sustain > AL_SUSTAIN)
                    vstate->phase = AL_PHASE_SUSTAIN;
                else
                    vstate->phase = AL_PHASE_NOTEON;
                
                cents = (key - sound->keyMap->keyBase) * 100
                    + sound->keyMap->detune;
                
                vstate->pitch = alCents2Ratio(cents);
                vstate->envGain = sound->envelope->attackVolume;
                vstate->envEndTime = seqp->curTime +
                    sound->envelope->attackTime;

                /*
                * setup tremelo and vibrato if active
                */
                vstate->flags = 0;
                inst = seqp->chanState[chan].instrument;

                oscValue = (f32)AL_VOL_FULL; /* set this as a default */
                if(inst->tremType)
                {
                    if(seqp->initOsc)
                    {
                        deltaTime = (*seqp->initOsc)(&oscState,&oscValue,inst->tremType,
                                            inst->tremRate,inst->tremDepth,inst->tremDelay);

                        if(deltaTime) /* a deltaTime of zero means don't run osc */
                        {
                            evt.type = AL_TREM_OSC_EVT;
                            evt.msg.osc.vs = vstate;
                            evt.msg.osc.oscState = oscState;
                            alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);
                            vstate->flags |= 0x01; /* set tremelo flag bit */
                        }
                    }
                }
                vstate->tremelo = (u8)oscValue;  /* will default if not changed by initOsc */
                
                oscValue = 1.0f; /* set this as a default */
                if(inst->vibType)
                {
                    if(seqp->initOsc)
                    {
                        deltaTime = (*seqp->initOsc)(&oscState,&oscValue,inst->vibType,
                                            inst->vibRate,inst->vibDepth,inst->vibDelay);

                        if(deltaTime)  /* a deltaTime of zero means don't run osc. */
                        {
                            evt.type = AL_VIB_OSC_EVT;
                            evt.msg.osc.vs = vstate;
                            evt.msg.osc.oscState = oscState;
                            evt.msg.osc.chan = chan;
                            alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);
                            vstate->flags |= 0x02; /* set the vibrato flag bit */
                        }
                    }
                }
                vstate->vibrato = oscValue; /* will default if not changed by initOsc */
                
                /*
                * calculate the note on parameters
                */
                pitch = vstate->pitch * seqp->chanState[chan].pitchBend *
                    vstate->vibrato;
                fxmix = seqp->chanState[chan].fxmix;
                pan   = __vsPan(vstate, (ALSeqPlayer*)seqp);
                vol   = __vsVol(vstate, (ALSeqPlayer*)seqp);
                deltaTime  = sound->envelope->attackTime;
                
                n_alSynStartVoiceParams(voice, sound->wavetable,
                                    pitch, vol, pan, fxmix, deltaTime);
                /*
                * set up callbacks for envelope
                */
                evt.type          = AL_SEQP_ENV_EVT;
                evt.msg.vol.voice = voice;
                evt.msg.vol.vol   = sound->envelope->decayVolume;
                evt.msg.vol.delta = sound->envelope->decayTime;
                                    
                alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);

                if(midi->duration)
                {
                    /*
                    * set up note off evt. if no duration don't do this
                    */
                    evt.type            = AL_CSP_NOTEOFF_EVT;
                    evt.msg.midi.status = chan | AL_MIDI_NoteOff;
                    evt.msg.midi.byte1  = key;
                    evt.msg.midi.byte2  = 0;   /* not needed ? */
                    deltaTime = seqp->uspt * midi->duration;
                
                    /* max time would be about one hour ten minutes */
                    alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);
                }
                
                break;
            }

            /*
            * NOTE: intentional fall-through for note on with zero
            * velocity (Should never happen with compact midi sequence,
            * but could happen with real time midi.)
            */

        case (AL_MIDI_NoteOff):
            vstate = __lookupVoice((ALSeqPlayer*)seqp, key, chan);
            ALFlagFailIf(!vstate, seqp->debugFlags & NOTE_OFF_ERR_MASK,
            ERR_ALSEQP_OFF_VOICE );

            if (vstate->phase == AL_PHASE_SUSTAIN)
                vstate->phase = AL_PHASE_SUSTREL;
            else
            {
                vstate->phase = AL_PHASE_RELEASE;
                __seqpReleaseVoice((ALSeqPlayer*)seqp, &vstate->voice,
                            vstate->sound->envelope->releaseTime);
            }

            break;
            
        case (AL_MIDI_PolyKeyPressure):
            /*
            * Aftertouch per key (hardwired to volume). Note that
            * aftertouch affects only notes that are already
            * sounding.
            */
            vstate = __lookupVoice((ALSeqPlayer*)seqp, key, chan);
            ALFailIf(!vstate,  ERR_ALSEQP_POLY_VOICE );

            vstate->velocity = byte2;
            n_alSynSetVol(&vstate->voice,
                        __vsVol(vstate, (ALSeqPlayer*)seqp), 
                        __vsDelta(vstate,seqp->curTime));
            break;

        case (AL_MIDI_ChannelPressure):
            /*
            * Aftertouch per channel (hardwired to volume). Note that
            * aftertouch affects only notes that are already
            * sounding.
            */
            for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                if (vs->channel == chan) {
                    vs->velocity = byte1;
                    n_alSynSetVol(&vs->voice,
                                __vsVol(vs, (ALSeqPlayer*)seqp),
                                __vsDelta(vs,seqp->curTime));
                }
            }
            break;
            
        case (AL_MIDI_ControlChange):
            switch (byte1)
            {
                case (AL_MIDI_PAN_CTRL):
                    seqp->chanState[chan].pan = byte2;
                    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next)
                    {
                        if (vs->channel == chan)
                        {
                            pan = __vsPan(vs, (ALSeqPlayer*)seqp);
                            n_alSynSetPan(&vs->voice, pan);
                        }
                    }
                    break;
                
                case (AL_MIDI_VOLUME_CTRL):
                    seqp->chanState[chan].vol = byte2;
                    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next)
                    {
                        if ((vs->channel == chan) && (vs->envPhase != AL_PHASE_RELEASE))
                        {
                            vol = __vsVol(vs, (ALSeqPlayer*)seqp);
                            n_alSynSetVol(&vs->voice, vol,
                                        __vsDelta(vs,seqp->curTime));
                        }
                    }
                    break;
                case (0x7D):
                    seqp->chanState[chan].unk9 = byte2;
                    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next)
                    {
                        if ((vs->channel == chan) && (vs->envPhase != AL_PHASE_RELEASE))
                        {
                            vol = __vsVol(vs, (ALSeqPlayer*)seqp);
                            n_alSynSetVol(&vs->voice, vol,
                                        __vsDelta(vs,seqp->curTime));
                        }
                    }
                    break;
                case (AL_MIDI_PRIORITY_CTRL):
            /* leave current voices where they are */
                    seqp->chanState[chan].priority = byte2;
                    break;
                case (AL_MIDI_SUSTAIN_CTRL):
                    seqp->chanState[chan].sustain = byte2;
                    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next)
                    {
                        if ((vs->channel == chan) && (vs->phase != AL_PHASE_RELEASE))
                        {
                            if ( byte2 > AL_SUSTAIN )
                            {
                                /*
                                * sustain pedal down
                                */
                                if (vs->phase == AL_PHASE_NOTEON)
                                    vs->phase = AL_PHASE_SUSTAIN;
                            }
                            else
                            {
                                /*
                                * sustain pedal up
                                */
                                if (vs->phase == AL_PHASE_SUSTAIN)
                                    vs->phase = AL_PHASE_NOTEON;

                                else if(vs->phase == AL_PHASE_SUSTREL)
                                {
                                    vs->phase = AL_PHASE_RELEASE;
                                    __seqpReleaseVoice((ALSeqPlayer*)seqp,
                                                    &vs->voice,
                                                    vs->sound->envelope->releaseTime);
                                }
                            }
                        }
                    }
                    break;
                case (AL_MIDI_FX1_CTRL):
                    seqp->chanState[chan].fxmix = byte2;
                    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next)
                    {
                        if (vs->channel == chan)
                            n_alSynSetFXMix(&vs->voice, byte2);
                    }
                    break;
                case (0x6A):
                case (0x6B):
                case (0x6C):
                case (0x6D):
                case (0x6E):
                case (0x6F):
                case (0x70):
                case (0x71):
                case (0x72):
                case (0x73):
                case (0x74):
                case (0x75):
                case (0x76):
                case (0x77):
                    func_80250104(seqp->target,key, chan);
                    break;
                default:
                    break;
            }
            break;
        case (AL_MIDI_ProgramChange):
        /* sct 1/16/96 - We must have a valid bank in order to process the program change. */
            //assert(seqp->bank != NULL);
            ((seqp->bank != NULL)?((void)0):func_8033F000("seqp->bank != NULL", "n_csplayer.c", 715));
            if (key < seqp->bank->instCount)
            {
                ALInstrument *inst = seqp->bank->instArray[key];
                __setInstChanState((ALSeqPlayer*)seqp, inst, chan);	/* sct 11/6/95 */               
            }
            else
            {
#ifdef _DEBUG
                __osError(ERR_ALSEQPINVALIDPROG, 2, key, seqp->bank->instCount);
#endif                
            }
            break;            
        case (AL_MIDI_PitchBendChange):
            {
                s32 bendVal;
                f32 bendRatio;
                s32 cents;
                
                /* get 14-bit unsigned midi value */
                bendVal = ( (byte2 << 7) + byte1) - 8192;

                /* calculate pitch bend in cents */
                cents = (seqp->chanState[chan].bendRange * bendVal)/8192;

                /* calculate the corresponding ratio  */
                bendRatio = alCents2Ratio(cents);
                seqp->chanState[chan].pitchBend = bendRatio;
                
                for (vs = seqp->vAllocHead; vs != 0; vs = vs->next)
                    if (vs->channel == chan)
                        n_alSynSetPitch(&vs->voice,
                                    vs->pitch * bendRatio * vs->vibrato);

            }
            break;
            
        default:
#ifdef _DEBUG
            __osError(ERR_ALSEQPUNKNOWNMIDI, 1, status);
#endif
            break;
    }
}

/*Done*/
static void __n_CSPHandleMetaMsg(N_ALCSPlayer *seqp, N_ALEvent *event)
{
    ALTempoEvent    *tevt = &event->msg.tempo;
    ALEvent         evt;
    s32             tempo;
    s32             oldUspt;
    u32             ticks;
    ALMicroTime         tempDelta,curDelta = 0;
    ALEventListItem     *thisNode,*nextNode,*firstTemp = 0;


    if (event->msg.tempo.status == AL_MIDI_Meta)
    {
        if (event->msg.tempo.type == AL_MIDI_META_TEMPO)
        {
	    oldUspt = seqp->uspt;
	    tempo = (tevt->byte1 << 16) | (tevt->byte2 <<  8) | (tevt->byte3 <<  0);
	    __n_setUsptFromTempo (seqp, seqp->target, (f32)tempo);	/* sct 1/8/96 */

	    thisNode = (ALEventListItem*)seqp->evtq.allocList.next;
	    while(thisNode)
	    {
		curDelta += thisNode->delta;
		nextNode = (ALEventListItem*)thisNode->node.next;
		if(thisNode->evt.type == AL_CSP_NOTEOFF_EVT)
		{
		    alUnlink((ALLink*)thisNode);

		    if(firstTemp)
			alLink((ALLink*)thisNode,(ALLink*)firstTemp);
		    else
		    {
			thisNode->node.next = 0;
			thisNode->node.prev = 0;
			firstTemp = thisNode;
		    }
		    tempDelta = curDelta;         /* record the current delta */
		    if(nextNode) /* don't do this if no nextNode */
		    {
			curDelta -= thisNode->delta;  /* subtract out this delta */
			nextNode->delta += thisNode->delta; /* add it to next event */
		    }
		    thisNode->delta = tempDelta; /* set this event delta from current */
		}
		thisNode = nextNode;
	    }

	    thisNode = firstTemp;
	    while(thisNode)
	    {
		nextNode = (ALEventListItem*)thisNode->node.next;
		ticks = thisNode->delta/oldUspt;
		thisNode->delta = ticks * seqp->uspt;
		__n_CSPRepostEvent(&seqp->evtq,thisNode);
		thisNode = nextNode;
	    }
        }
    }
}
/*Done*/
static void  __n_CSPRepostEvent(ALEventQueue *evtq, N_ALEventListItem *item)
{
    OSIntMask           mask;
    ALLink              *node;
    N_ALEventListItem     *nextItem;
    
    mask = osSetIntMask(OS_IM_NONE);

    for (node = &evtq->allocList; node != 0; node = node->next)
    {
        if (!node->next)  /* end of the list */
        {
            alLink((ALLink *)item, node);
            break;
        }
        else
        {
            nextItem = (N_ALEventListItem *)node->next;
            if (item->delta < nextItem->delta)
            {
                nextItem->delta -= item->delta;
                alLink((ALLink *)item, node);
                break;
            }
            item->delta -= nextItem->delta;
        }
    }
    osSetIntMask(mask);
}


/*
  This routine safely calculates the sequence player's
  uspt value based on the given tempo.  It does this safely
  by making sure that the player has a target sequence and
  therefore a qnpt value which is needed for the calculation.
  Compact sequence player needs its own version of this routine
  since the ALCSeq's qnpt field is at a different offset.
*/
/* DONE */
static void __n_setUsptFromTempo(N_ALCSPlayer *seqp, ALCSeq *target, f32 tempo)
{
    if (target)
	seqp->uspt = (s32)((f32)tempo * target->qnpt);
    else
	seqp->uspt = 488;		/* This is the initial value set by alSeqpNew. */
}
