#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "n_synth.h"
#include "seqp.h"
#include "file_and_line.h"

extern void func_8033F000(const char *, const char *, int);
void    n_alSynSetVol( N_ALVoice *v, s16 volume, ALMicroTime t);
s16             __n_vsVol(ALVoiceState *voice, ALSeqPlayer *seqp);
ALVoiceState    *__n_lookupVoice(ALSeqPlayer *, u8, u8);
ALVoiceState    *__n_mapVoice(ALSeqPlayer *, u8, u8, u8);
ALSound         *__n_lookupSoundQuick(ALSeqPlayer *, u8, u8, u8);
void		__n_seqpReleaseVoice(ALSeqPlayer *seqp, ALVoice *voice, ALMicroTime deltaTime);

/*====================================================================
 * csplayer.c
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*
 * Notes:
 *
 * Controller Numbers:
 *      1       Modulation
 *      7       Volume
 *      10      Pan
 *      11      Expression
 *      64      Sustain
 *      121     Reset All Controllers
 *      123     All Notes Off
 *
 * Registered Parameters
 *      0       Pitch Bend Sensitivity
 *      1       Fine Tuning
 *      2       Coarse Tuning
 */
void func_8025D7C0(ALCSPlayer *seqp);

static ALMicroTime      __n_CSPVoiceHandler(void *node);
static void		__CSPHandleNextSeqEvent(ALCSPlayer *seqp);
static void             __n_CSPHandleMIDIMsg(N_ALCSPlayer *seqp, ALEvent *event);
static void             __CSPHandleMetaMsg(ALCSPlayer *seqp, ALEvent *event);
static void             __CSPRepostEvent(ALEventQueue *evtq, ALEventListItem *item);
static void		__setUsptFromTempo(ALCSPlayer *seqp, f32 tempo);		/* sct 1/8/96 */


/*
 * Sequence Player public functions
 */
void n_alCSPNew(N_ALCSPlayer *seqp, ALSeqpConfig *c)
{
    s32                 i;
    ALEventListItem     *items;
    ALVoiceState        *vs;
    ALVoiceState        *voices;
    
    ALHeap *hp = c->heap;    

    /*
     * initialize member variables
     */
    seqp->bank          = 0;
    seqp->target        = NULL;
    seqp->drvr          = n_syn;
    seqp->chanMask      = -1;
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
    __n_initChanState((ALSeqPlayer*)seqp);	/* sct 11/6/95 */
    
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
    n_alSynAddSeqPlayer(&seqp->node);  
}

/*************************************************************
 * private routines or driver callback routines
 *************************************************************/
static ALMicroTime __n_CSPVoiceHandler(void *node)
{
    ALCSPlayer      *seqp = (ALCSPlayer *) node;
    ALEvent         evt;
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
	    __CSPHandleNextSeqEvent(seqp);
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
		__n_seqpStopOsc((ALSeqPlayer*)seqp,vs);
	    __n_unmapVoice((ALSeqPlayer*)seqp, voice); 
	    break;

	case (AL_SEQP_ENV_EVT):
	    voice = seqp->nextEvent.msg.vol.voice;
	    vs = (ALVoiceState *)voice->clientPrivate;

	    if(vs->envPhase == AL_PHASE_ATTACK)
		vs->envPhase = AL_PHASE_DECAY;

	    delta = seqp->nextEvent.msg.vol.delta;
	    vs->envEndTime = seqp->curTime + delta;
	    vs->envGain = seqp->nextEvent.msg.vol.vol;
	    n_alSynSetVol(voice, __n_vsVol(vs, (ALSeqPlayer*)seqp), delta);
	    break;
                
	case (AL_TREM_OSC_EVT):
	    vs = seqp->nextEvent.msg.osc.vs;
	    oscState = seqp->nextEvent.msg.osc.oscState;
	    delta = (*seqp->updateOsc)(oscState,&oscValue);
	    vs->tremelo = (u8)oscValue;
	    n_alSynSetVol(&vs->voice, __n_vsVol(vs,(ALSeqPlayer*)seqp),
			__n_vsDelta(vs,seqp->curTime));
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
	    __CSPHandleMetaMsg(seqp, &seqp->nextEvent);
	    break;

	case (AL_SEQP_VOL_EVT):
	    seqp->vol =  seqp->nextEvent.msg.spvol.vol;
	    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next)
	    {
		n_alSynSetVol(&vs->voice,
                            __n_vsVol(vs, (ALSeqPlayer*)seqp),
                            __n_vsDelta(vs, seqp->curTime));
	    }
	    break;

	case (AL_SEQP_PLAY_EVT):
	    if (seqp->state != AL_PLAYING)
	    {
		seqp->state = AL_PLAYING;
        func_80250650();    
		func_8025D7C0(seqp);	/* seqp must be AL_PLAYING before we call this routine. */
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
			__n_seqpStopOsc((ALSeqPlayer*)seqp,vs);
		    __n_unmapVoice((ALSeqPlayer*)seqp, &vs->voice); 
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
		    if (__n_voiceNeedsNoteKill ((ALSeqPlayer*)seqp, &vs->voice, KILL_TIME))
			__n_seqpReleaseVoice((ALSeqPlayer*)seqp, &vs->voice, KILL_TIME);
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
        matching_assert(seqp->state != AL_PLAYING, n_csplayer.c, 0x110);/* Must be done playing to change sequences. */
    
	    seqp->target = seqp->nextEvent.msg.spseq.seq;
        seqp->chanMask = 0xffff;
	    // __setUsptFromTempo (seqp, 500000.0);
	    if (seqp->bank)
		__n_initFromBank((ALSeqPlayer *)seqp, seqp->bank);
	    break;

	case (AL_SEQP_BANK_EVT):
        matching_assert(seqp->state == AL_STOPPED, n_csplayer.c, 0x11b);
	    seqp->bank = seqp->nextEvent.msg.spbank.bank;
	    __n_initFromBank((ALSeqPlayer *)seqp, seqp->bank);
	    break;

	    /* sct 11/6/95 - these events should now be handled by __CSPHandleNextSeqEvent */
	case (AL_SEQ_END_EVT):
	case (AL_TEMPO_EVT):
	case (AL_SEQ_MIDI_EVT):
        matching_assert(FALSE, n_csplayer.c, 0x128);
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
void func_8025D7C0(ALCSPlayer *seqp) 
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
__CSPHandleNextSeqEvent(ALCSPlayer *seqp)
{
    ALEvent	evt;

    /* sct 1/5/96 - Do nothing if we don't have a target sequence. */
    if (seqp->target == NULL)
	return;

    n_alCSeqNextEvent(seqp->target, &evt);

    switch (evt.type)
    {
      case AL_SEQ_MIDI_EVT:
          __n_CSPHandleMIDIMsg(seqp, &evt);
	  func_8025D7C0(seqp);
	  break;

      case AL_TEMPO_EVT:
          __CSPHandleMetaMsg(seqp, &evt);
	  func_8025D7C0(seqp);
	  break;

      case AL_SEQ_END_EVT:
	  seqp->state = AL_STOPPING;      
	  evt.type    = AL_SEQP_STOP_EVT;
	  alEvtqPostEvent(&seqp->evtq, &evt, AL_EVTQ_END);
	  break;

      case AL_TRACK_END:
      case AL_CSP_LOOPSTART:
      case AL_CSP_LOOPEND:
	  func_8025D7C0(seqp);
	  break;
	  
      default:
	  matching_assert(FALSE, n_csplayer.c, 0x161);	/* Sequence event type not supported. */
    }
}

static void __n_CSPHandleMIDIMsg(N_ALCSPlayer *seqp, ALEvent *event)
{
    N_ALVoice             *voice;
    N_ALVoiceState        *vs;
    s32                 status;
    u8                  chan;
    u8                  byte1;
    u8                  new_var;
    u8                  byte2;    
    ALMIDIEvent         *midi = &event->msg.midi;
    s16                 vol;
    N_ALVoiceState        *vstate;
    ALEvent             evt;
    ALMicroTime         deltaTime;
    ALPan   		    pan;
    ALFxRef		        fxref;


    status = midi->status & AL_MIDI_StatusMask;
    new_var = midi->byte1;
    chan = midi->status & AL_MIDI_ChannelMask;
    byte1 = new_var;
    byte2 =  midi->byte2;
    if(status == AL_MIDI_ControlChange){
        if(byte1 == 0x7E) {
            N_ALVoiceState        *vstate2;
            // vs = seqp->vAllocHead;
            seqp->chanMask &= ~(1 << byte2);
            
            //vs NOT being initialied seems weird            
            for (vstate2 = seqp->vAllocHead; vs != 0; vs = vs->next)
    		{
    		    if (vstate2->channel == byte2)
    			    __n_seqpReleaseVoice((ALSeqPlayer*)seqp, &vstate2->voice, vstate2->sound->envelope->releaseTime);
    		}
            return;
        } else if(byte1 == 0x7F){
            seqp->chanMask |= 1 << byte2;
            return;
        }
    }
    if ((!((1 << chan) & seqp->chanMask) && (status == 0x90))) return;
    switch (status)
    {
        case (AL_MIDI_NoteOn):
            if (byte2 != 0)		/* a real note on */
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

                sound = __n_lookupSoundQuick((ALSeqPlayer*)seqp, byte1, byte2, chan);
                ALFlagFailIf(!sound, seqp->debugFlags & NO_SOUND_ERR_MASK,
			 ERR_ALSEQP_NO_SOUND); 
                
                config.priority = seqp->chanState[chan].priority;
                config.fxBus    = 0;
                config.unityPitch = 0;
                
                vstate = __n_mapVoice((ALSeqPlayer*)seqp, byte1, byte2, chan);
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
                
                cents = (byte1 - sound->keyMap->keyBase) * 100
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
                pan   = __n_vsPan(vstate, (ALSeqPlayer*)seqp);
                vol   = __n_vsVol(vstate, (ALSeqPlayer*)seqp);
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
                    evt.msg.midi.byte1  = byte1;
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
            vstate = __n_lookupVoice((ALSeqPlayer*)seqp, byte1, chan);
            ALFlagFailIf(!vstate, seqp->debugFlags & NOTE_OFF_ERR_MASK,
		     ERR_ALSEQP_OFF_VOICE );

            if (vstate->phase == AL_PHASE_SUSTAIN)
                vstate->phase = AL_PHASE_SUSTREL;
            else
            {
                vstate->phase = AL_PHASE_RELEASE;
                __n_seqpReleaseVoice((ALSeqPlayer*)seqp, &vstate->voice,
                              vstate->sound->envelope->releaseTime);
            }

            break;
            
        case (AL_MIDI_PolyKeyPressure):
            /*
             * Aftertouch per key (hardwired to volume). Note that
             * aftertouch affects only notes that are already
             * sounding.
             */
            vstate = __n_lookupVoice((ALSeqPlayer*)seqp, byte1, chan);
            ALFailIf(!vstate,  ERR_ALSEQP_POLY_VOICE );

            vstate->velocity = byte2;
            n_alSynSetVol(&vstate->voice,
                        __n_vsVol(vstate, (ALSeqPlayer*)seqp), 
                        __n_vsDelta(vstate,seqp->curTime));
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
                                __n_vsVol(vs, (ALSeqPlayer*)seqp),
                                __n_vsDelta(vs,seqp->curTime));
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
                            pan = __n_vsPan(vs, (ALSeqPlayer*)seqp);
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
                            vol = __n_vsVol(vs, (ALSeqPlayer*)seqp);
                            n_alSynSetVol(&vs->voice, vol,
                                        __n_vsDelta(vs,seqp->curTime));
                        }
                    }
                    break;
                
                case (0x7D):
                    seqp->chanState[chan].unkA = byte2;
                    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next)
                    {
                        if ((vs->channel == chan) && (vs->envPhase != AL_PHASE_RELEASE))
                        {
                            vol = __n_vsVol(vs, (ALSeqPlayer*)seqp);
                            n_alSynSetVol(&vs->voice, vol,
                                        __n_vsDelta(vs,seqp->curTime));
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
                                    __n_seqpReleaseVoice((ALSeqPlayer*)seqp,
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
                case 0x6A:                          /* switch 2 */
                case 0x6B:                          /* switch 2 */
                case 0x6C:                          /* switch 2 */
                case 0x6D:                          /* switch 2 */
                case 0x6E:                          /* switch 2 */
                case 0x6F:                          /* switch 2 */
                case 0x70:                          /* switch 2 */
                case 0x71:                          /* switch 2 */
                case 0x72:                          /* switch 2 */
                case 0x73:                          /* switch 2 */
                case 0x74:                          /* switch 2 */
                case 0x75:                          /* switch 2 */
                case 0x76:                          /* switch 2 */
                case 0x77:                          /* switch 2 */
                    func_80250104(seqp->target, byte1, chan);
                    break;
/*                case (AL_MIDI_FX_CTRL_0):
                case (AL_MIDI_FX_CTRL_1):
                case (AL_MIDI_FX_CTRL_2):
                case (AL_MIDI_FX_CTRL_3):
                case (AL_MIDI_FX_CTRL_4):
                case (AL_MIDI_FX_CTRL_5):
                case (AL_MIDI_FX_CTRL_6):
                case (AL_MIDI_FX_CTRL_7):
                    fxref = alSynGetFXRef(seqp->drvr, 0, 0);
                    if (fxref)
                        alSynSetFXParam(seqp->drvr, fxref, (s16)byte1, (void *)byte2);
                    break; 
                case (AL_MIDI_FX3_CTRL): */
                default:
                    break;
            }
            break;
        case (AL_MIDI_ProgramChange):
	    /* sct 1/16/96 - We must have a valid bank in order to process the program change. */
	    matching_assert(seqp->bank != NULL, n_csplayer.c, 0x2cb);

            if (byte1 < seqp->bank->instCount)
            {
                ALInstrument *inst = seqp->bank->instArray[byte1];
                __n_setInstChanState((ALSeqPlayer*)seqp, inst, chan);	/* sct 11/6/95 */               
            }
            else
            {
#ifdef _DEBUG
                __osError(ERR_ALSEQPINVALIDPROG, 2, byte1, seqp->bank->instCount);
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

static void __CSPHandleMetaMsg(ALCSPlayer *seqp, ALEvent *event)
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
	    __setUsptFromTempo (seqp, (f32)tempo);	/* sct 1/8/96 */

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
		__CSPRepostEvent(&seqp->evtq,thisNode);
		thisNode = nextNode;
	    }
        }
    }
}

static void  __CSPRepostEvent(ALEventQueue *evtq, ALEventListItem *item)
{
    OSIntMask           mask;
    ALLink              *node;
    ALEventListItem     *nextItem;
    
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
            nextItem = (ALEventListItem *)node->next;
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
static void __setUsptFromTempo (ALCSPlayer *seqp, f32 tempo)
{
    if (seqp->target)
	seqp->uspt = (s32)((f32)tempo * seqp->target->qnpt);
    else
	seqp->uspt = 488;		/* This is the initial value set by alSeqpNew. */
}
