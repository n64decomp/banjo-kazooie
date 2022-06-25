#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "n_synth.h"

#ifndef assert
#define assert(s) 
#endif

extern ALCmdHandler n_alAuxBusPull;
extern ALCmdHandler func_8025FE6C;
extern void alN_PVoiceNew(N_PVoice *mv, ALDMANew dmaNew, ALHeap *hp);


#ifdef AUD_PROFILE
#include <os.h>
extern u32 cnt_index, drvr_num, drvr_cnt, drvr_max, drvr_min, lastCnt[];
extern u32 client_num, client_cnt, client_max, client_min;
#endif

#ifndef MIN
#   define MIN(a,b) (((a)<(b))?(a):(b))
#endif

static s32 func_8025C370(ALPlayer **client);
static s32 _n_timeToSamplesNoRound(s32 micros);
/***********************************************************************
 * Synthesis driver public interfaces
 ***********************************************************************/
void n_alSynNew(ALSynConfig *c)
{
    s32         i;
    N_PVoice      *pv;
    N_PVoice      *pvoices;
    ALHeap      *hp = c->heap;
    ALFilter    *sources;
    ALParam     *params;
    ALParam     *paramPtr;
    
    n_syn->synth.head            = NULL;
    n_syn->synth.n_seqp1         = NULL;
    n_syn->synth.n_seqp2         = NULL;
    n_syn->unk5C                 = NULL;
    n_syn->unk60                 = NULL;
    n_syn->unk64                 = NULL;
    n_syn->unk68                 = NULL;
    n_syn->unk6C                 = NULL;
    n_syn->unk70                 = NULL;
    n_syn->synth.n_sndp          = NULL;
    n_syn->synth.numPVoices      = c->maxPVoices;
    n_syn->synth.curSamples      = 0;
    n_syn->synth.paramSamples    = 0;
    n_syn->synth.outputRate      = c->outputRate;
    n_syn->synth.maxOutSamples   = N_AL_MAX_RSP_SAMPLES;
    n_syn->synth.dma             = (ALDMANew) c->dmaproc;

    n_syn->synth.sv_dramout = 0;
    n_syn->synth.sv_first = 1;

    /*
     * allocate and initialize the auxilliary effects bus. at present
     * we only support 1 effects bus.
     */
    n_syn->synth.auxBus = alHeapAlloc(hp, 1, sizeof(N_ALAuxBus));
    n_syn->synth.auxBus->sourceCount = 0;
    n_syn->synth.auxBus->maxSources = c->maxPVoices;
    n_syn->synth.auxBus->sources = alHeapAlloc(hp, c->maxPVoices, sizeof(ALFilter *));

    /*
     * allocate and initialize the main bus.
     */
    n_syn->synth.mainBus = alHeapAlloc(hp, 1, sizeof(N_ALMainBus));

    if (c->fxType != AL_FX_NONE){
        /*
         * Allocate an effect and set parameters
         */
        n_syn->synth.auxBus->fx = n_alSynAllocFX(0, c, hp);
        n_syn->synth.mainBus->filter.handler = &func_8025FE6C;
    } else{
        /*
         * Connect the aux bus to the main bus
         */
        n_syn->synth.mainBus->filter.handler = &n_alAuxBusPull;
    }
    /*
     * Build the physical voice lists
     */
    n_syn->synth.pFreeList.next = 0;
    n_syn->synth.pFreeList.prev = 0;
    n_syn->synth.pLameList.next = 0;
    n_syn->synth.pLameList.prev = 0;
    n_syn->synth.pAllocList.next = 0;
    n_syn->synth.pAllocList.prev = 0;

    pvoices = alHeapAlloc(hp, c->maxPVoices, sizeof(N_PVoice));
    for (i = 0; i < c->maxPVoices; i++) {
        pv = &pvoices[i];
        alLink((ALLink *)pv, &n_syn->synth.pFreeList);
        pv->vvoice = 0;
        alN_PVoiceNew(pv, n_syn->synth.dma, hp);
        n_syn->synth.auxBus->sources[n_syn->synth.auxBus->sourceCount] = pv;
        n_syn->synth.auxBus->sourceCount++;
    }

    /*
     * build the parameter update list
     */
    params = alHeapAlloc(hp, c->maxUpdates, sizeof(ALParam));
    n_syn->synth.paramList = 0;
    for (i = 0; i < c->maxUpdates; i++) {
        paramPtr= &params[i];
        paramPtr->next = n_syn->synth.paramList;
        n_syn->synth.paramList = paramPtr;
    }
    
    n_syn->synth.heap = hp;
}

/*
 * slAudioFrame() is called every video frame, and is based on the video
 * frame interrupt. It is assumed to be an accurate time source for the
 * clients.
 */
Acmd *n_alAudioFrame(Acmd *cmdList, s32 *cmdLen, s16 *outBuf, s32 outLen)
{
    ALPlayer    *client;
    ALFilter    *output;
    s16         tmp;        /* Starting buffer in DMEM */
    Acmd        *cmdlEnd = cmdList;
    Acmd        *cmdPtr;
    s32         nOut;
    s16         *lOutBuf = outBuf;

#ifdef AUD_PROFILE
    lastCnt[++cnt_index] = osGetCount();
#endif
    
    if (n_syn->synth.head == 0) {
	    *cmdLen = 0;
        return cmdList;         /* nothing to do */
    }    

    /*
     * run down list of clients and execute callback if needed this
     * subframe. Here we do all the work for the frame at the
     * start. Time offsets that occur before the next frame are
     * executed "early".
     */

#ifdef AUD_PROFILE
    lastCnt[++cnt_index] = osGetCount();
#endif

    /*
     * paramSamples = time of next parameter change.
     * curSamples = current sample time.
     * so paramSamples - curSamples is the time until the next parameter change.
     * if the next parameter change occurs within this frame time (outLen),
     * then call back the client that contains the parameter change.
     * Note, paramSamples must be rounded down to 16 sample boundary for use
     * during the client handler.
     */

    for (n_syn->synth.paramSamples = func_8025C370(&client);
	 n_syn->synth.paramSamples - n_syn->synth.curSamples < outLen;
	 n_syn->synth.paramSamples = func_8025C370(&client))
    {
	n_syn->synth.paramSamples &= ~0xf;
	client->samplesLeft += _n_timeToSamplesNoRound((*client->handler)(client));
    }

    /* for safety's sake, always store paramSamples aligned to 16 sample boundary.
     * this way, if an voice handler routine gets called outside the ALVoiceHandler
     * routine (alSynAllocVoice) it will get timestamped with an aligned value and
     * will be processed immediately next audio frame.
     */
    n_syn->synth.paramSamples &= ~0xf;


#ifdef AUD_PROFILE
    PROFILE_AUD(client_num, client_cnt, client_max, client_min);
#endif

    /*
     * Now build the command list in small chunks
     */
    while (outLen > 0){
        nOut = MIN(n_syn->synth.maxOutSamples, outLen);

        /*
         * construct the command list for each physical voice by calling
         * the head of the filter chain.
         */
        n_syn->synth.sv_dramout = (s32) lOutBuf;
        cmdlEnd = n_alSavePull(n_syn->synth.curSamples, cmdlEnd);
        outLen -= nOut;
        lOutBuf += nOut<<1;     /* For Stereo */
        n_syn->synth.curSamples += nOut;
                
    }
    *cmdLen = (s32) (cmdlEnd - cmdList);

    _n_collectPVoices(); /* collect free physical voices */
    
#ifdef AUD_PROFILE
    PROFILE_AUD(drvr_num, drvr_cnt, drvr_max, drvr_min);
#endif
    return cmdlEnd;
}

/***********************************************************************
 * Synthesis driver private interfaces
 ***********************************************************************/

ALParam *__allocParam() 
{
    ALParam *update = 0;

    if (n_syn->synth.paramList) {        
        update = n_syn->synth.paramList;
        n_syn->synth.paramList =n_syn->synth.paramList->next;
        update->next = 0;
    }
    return update;
}

void __n_freeParam(ALParam *param) 
{
    param->next = n_syn->synth.paramList;
    n_syn->synth.paramList = param;
}

void _n_collectPVoices() 
{
    ALLink       *dl;
    N_PVoice      *pv;

    while ((dl = n_syn->synth.pLameList.next) != 0) {
        pv = (N_PVoice *)dl;

        /* ### remove from mixer */

        alUnlink(dl);
        alLink(dl, &n_syn->synth.pFreeList);        
    }
}

void _n_freePVoice(N_PVoice *pvoice) 
{
    /*
     * move the voice from the allocated list to the lame list
     */
    alUnlink((ALLink *)pvoice);
    alLink((ALLink *)pvoice, &n_syn->synth.pLameList);
}


/*
  Add 0.5 to adjust the average affect of
  the truncation error produced by casting
  a float to an int.
*/
s32 _n_timeToSamplesNoRound(s32 micros)
{
    f32 tmp = ((f32)micros) * n_syn->synth.outputRate / 1000000.0 + 0.5;

    return (s32)tmp;
}

s32 _n_timeToSamples(s32 micros)
{
    return _n_timeToSamplesNoRound(micros) & ~0xf;
}

// static s32 __nextSampleTime(ALSynth *drvr, ALPlayer **client) 
// {
//     ALMicroTime delta = 0x7fffffff;     /* max delta for s32 */
//     ALPlayer *cl;

//     assert(drvr->head);
//     *client = 0;
    
//     for (cl = drvr->head; cl != 0; cl = cl->next) {
//         if ((cl->samplesLeft - drvr->curSamples) < delta) {
//             *client = cl;
//             delta = cl->samplesLeft - drvr->curSamples;
//         }
//     }

//     return (*client)->samplesLeft;
// }

static s32 func_8025C370(ALPlayer **client) 
{
    ALMicroTime delta = 0x7fffffff;     /* max delta for s32 */
    ALMicroTime idelta;
    ALPlayer *cl;

    *client = 0;
    
    cl = n_syn->synth.n_sndp;
    if(n_syn->synth.n_sndp != NULL){
        idelta = (cl->samplesLeft - n_syn->synth.curSamples);
        if (idelta < delta) {
            *client = cl;
            delta = idelta;
        }
    }

    cl = n_syn->synth.n_seqp1;
    if(cl != NULL){
        idelta = (cl->samplesLeft - n_syn->synth.curSamples);
        if (idelta < delta) {
            *client = cl;
            delta = idelta;
        }
    }

    cl = n_syn->synth.n_seqp2;
    if(cl != NULL){
        idelta = (cl->samplesLeft - n_syn->synth.curSamples);
        if (idelta < delta) {
            *client = cl;
            delta = idelta;
        }
    }

    cl = n_syn->unk5C;
    if(cl != NULL){
        idelta = (cl->samplesLeft - n_syn->synth.curSamples);
        if (idelta < delta) {
            *client = cl;
            delta = idelta;
        }
    }

    cl = n_syn->unk60;
    if(cl != NULL){
        idelta = (cl->samplesLeft - n_syn->synth.curSamples);
        if (idelta < delta) {
            *client = cl;
            delta = idelta;
        }
    }

    cl = n_syn->unk64;
    if(cl != NULL){
        idelta = (cl->samplesLeft - n_syn->synth.curSamples);
        if (idelta < delta) {
            *client = cl;
            delta = idelta;
        }
    }

    cl = n_syn->unk68;
    if(cl != NULL){
        idelta = (cl->samplesLeft - n_syn->synth.curSamples);
        if (idelta < delta) {
            *client = cl;
            delta = idelta;
        }
    }

    cl = n_syn->unk6C;
    if(cl != NULL){
        idelta = (cl->samplesLeft - n_syn->synth.curSamples);
        if (idelta < delta) {
            *client = cl;
            delta = idelta;
        }
    }

    cl = n_syn->unk70;
    if(cl != NULL){
        idelta = (cl->samplesLeft - n_syn->synth.curSamples);
        if (idelta < delta) {
            *client = cl;
            delta = idelta;
        }
    }

    return (*client)->samplesLeft;
}
