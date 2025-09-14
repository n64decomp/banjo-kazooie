#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "version.h"

#include "musicplayer.h"

#include "core1/core1.h"

extern func_8024FDDC(u8, s32);

void func_8025AE50(s32, f32);

bool func_80250074(u8);
void musicTrack_setVolume(u8, s32);
void func_8024FC1C(u8, s32);
void func_8025AC20(enum comusic_e, s32, s32, f32, char*, s32);
void func_8025AC7C(enum comusic_e, s32, s32, f32, s32 *, char*, s32);
void coMusicPlayer_free(void);
void func_8025A55C(s32, s32, s32);
void func_8025A7DC(enum comusic_e);
void func_8025ABB8(enum comusic_e, s32, s32, s32);
void *freelist_next(FLA **, s32*);

CoMusic *musicTracks = NULL; // Pointer to the first CoMusic struct. Additional are saved after in memory. The first track is the primary track.
int D_80276E34 = 0;

/**
 * @brief returns a pointer to the CoMusic struct with the corresponding trackId
 * if it exists OR the first free CoMusic struct. This also skips the first CoMusic in the search.
 * 
 * @param trackId
 * @return CoMusic* 
 */
CoMusic *findTrack(enum comusic_e trackId) {
    CoMusic *music_track;
    CoMusic *free_music_track;

    free_music_track = NULL;

    for (music_track = musicTracks + 1; music_track < musicTracks + MAX_MUSIC_STRUCT_COUNT - 1; music_track++) {
        if (trackId == music_track->track_id) {
            return music_track;
        }

        if (free_music_track == NULL && (s32) music_track->track_id < 0) {
            free_music_track = music_track;
        }
    }

    return free_music_track;
}

void func_80259914(CoMusic *this, s32 arg1, s32 arg2) {
    s32 sp2C;
    s32 i;
    struct12s *tmp;

    freelist_clear(this->unk18);

    for (i = 0; i < 0xE; i++) {
        this->unk1C[i] = 0;
    }

    tmp = (struct12s *)freelist_next(&this->unk18, &sp2C);
    tmp->unk0 = arg1;
    tmp->unk1 = arg2;
}

void func_80259994(CoMusic *this, s32 arg1){
    func_80259914(this, arg1, arg1);
}

void func_802599B4(CoMusic *this){
    func_80259994(this, gcMusic_getDefaultVolumeForTrack(this->track_id));

    this->track_id = -1;
    this->unk14 = 0;
    this->unk15 = 0;

    func_8024FC1C(this - musicTracks, -1);
}

void coMusicPlayer_init(void) {
    CoMusic * iPtr;
    s32 i;
    
    if (musicTracks != NULL) {
        coMusicPlayer_free();
    }

    musicTracks = (CoMusic *) malloc(MAX_MUSIC_STRUCT_COUNT * sizeof(CoMusic));
    for (iPtr = musicTracks; iPtr < musicTracks + MAX_MUSIC_STRUCT_COUNT; iPtr++) {
        iPtr->track_id = -1;
        iPtr->volume = 0;
        iPtr->unk12 = 0;
        iPtr->unkC = 0;
        iPtr->unk4 = 0.0f;
        iPtr->unk14 = 0;
        iPtr->unk15 = 0;
        iPtr->unk0 = 0.0f;
        iPtr->unk18 = (FREE_LIST(struct12s) *)freelist_new(sizeof(struct12s),4);

        for (i = 0; i < 0xE; i++) {
            iPtr->unk1C[i] = 0;
        }
    }
}

void coMusicPlayer_free(void){
    CoMusic *iPtr;

    func_8024FB8C();
    func_8024F83C();

    for (iPtr = musicTracks; iPtr < musicTracks + MAX_MUSIC_STRUCT_COUNT; iPtr++) {
        freelist_free(iPtr->unk18);
    }

    free(musicTracks);
    musicTracks = NULL;
}

s32 coMusicPlayer_getTrackCount(void) {
    CoMusic *track;
    s32 count = 0;

    for (track = musicTracks; track < musicTracks + MAX_MUSIC_STRUCT_COUNT; track++) {
        if (track->track_id >= 0) {
            count++;
        }
    }

    return count;
}

void coMusicPlayer_update(void) {
    s32 temp_lo;
    CoMusic *var_s0;
    f32 dt;

    dt = time_getDelta();

    for (var_s0 = musicTracks; var_s0 < &musicTracks[MAX_MUSIC_STRUCT_COUNT]; var_s0++) {
        if (var_s0->track_id >= 0) {
            temp_lo = var_s0 - musicTracks;
            var_s0->unk4 = ml_min_f(var_s0->unk4 + dt, 600.0f);

            if ((var_s0->unk4 > 1.0f) && func_80250074(temp_lo)) {
                func_8025A7DC(var_s0->track_id);
            }
        }
    }

    func_8024FF34();

    if (!D_80276E34) {
        return;
    }

    D_80276E34 = FALSE;

    for (var_s0 = musicTracks; var_s0 < &musicTracks[6]; var_s0++) {
        if (var_s0->track_id < 0) {
            continue;
        }

        if (var_s0->unk12 != 0) {
            temp_lo = var_s0 - musicTracks;

            if (var_s0->unk0 > 0.0f) {
                var_s0->unk0 -= time_getDelta();
                D_80276E34 = TRUE;
                continue;
            }

            if (var_s0->unk12 < 0) {
                var_s0->volume += var_s0->unk12;

                if (var_s0->unk15 && (var_s0->unkC == 0) && (var_s0->volume <= 0)) {
                    func_802599B4(var_s0);
                    continue;
                } else {
                    if (var_s0->unkC >= var_s0->volume) {
                        var_s0->volume = var_s0->unkC;
                        var_s0->unk12 = 0;
                    } else {
                        D_80276E34 = TRUE;
                    }
                    musicTrack_setVolume(temp_lo, (s16)var_s0->volume);
                }

                continue;
            }

            if (var_s0->volume < var_s0->unkC) {
                if (var_s0->volume == 0) {
                    var_s0->unk4 = 0.0f;
                }
                var_s0->volume += var_s0->unk12;
                if (var_s0->volume >= var_s0->unkC) {
                    var_s0->volume = var_s0->unkC;
                    var_s0->unk12 = 0;
                } else {
                    D_80276E34 = TRUE;
                }
                musicTrack_setVolume(temp_lo, (s16)var_s0->volume);

                continue;
            }

            var_s0->unk12 = 0;
        }
    }
}

void func_80259EA8(CoMusic *this, s32 *arg1, s32 *arg2){
    int i;
    int cnt = freelist_size(this->unk18);
    s32 tmp_s1 = 0x7FFF;
    s32 tmp_s2 = 0x40000000;
    struct12s *tmp_ptr;

    for (i = 1; i < cnt; i++) {
        if (freelist_elementIsAlive(this->unk18, i)) {
            tmp_ptr = (struct12s*)freelist_at(this->unk18, i);

            if (tmp_ptr->unk0 < tmp_s1 || (tmp_s1 == tmp_ptr->unk0 && tmp_ptr->unk1 < tmp_s2)) {
                tmp_s1 = tmp_ptr->unk0;
                tmp_s2 = tmp_ptr->unk1;
            }//L80259F40
        }
    }

    *arg1 = tmp_s1;
    *arg2 = tmp_s2;
}

void func_80259F7C(CoMusic *self, s32 *arg1, s32 *arg2, s32 *arg3) {
    struct12s *temp_v0;
    f32 pad;
    s32 sp34;
    s32 var_s2;

    var_s2 = *arg1;
    sp34 = *arg2;
    if ((*arg3 != 0) && !freelist_elementIsAlive(self->unk18, *arg3)) {
        *arg3 = 0;
    }

    if (var_s2 < 0) {
        temp_v0 = (struct12s *)freelist_at(self->unk18, 1);
        if (temp_v0->unk0 < gcMusic_getDefaultVolumeForTrack(self->track_id)) {
            var_s2 = gcMusic_getDefaultVolumeForTrack(self->track_id);
        } else {
            var_s2 = temp_v0->unk0;
        }

        if (*arg3 != 0) {
            temp_v0 = (struct12s *)freelist_at(self->unk18, *arg3);
            *arg2 = temp_v0->unk1;
            freelist_freeElement(self->unk18, *arg3);
            *arg3 = 0;
            func_80259EA8(self, arg1, &sp34);

            return;
        }
    }

    if (*arg3 == 0) {
        temp_v0 = (struct12s *)freelist_at(self->unk18, 1);
        if ((temp_v0->unk0 < var_s2) || ((var_s2 == temp_v0->unk0) && (sp34 >= temp_v0->unk1))) {
            func_80259914(self, var_s2, sp34);
        } else {
            freelist_next(&self->unk18, arg3);
        }
    }

    if (*arg3 != 0) {
        temp_v0 = (struct12s *)freelist_at(self->unk18, *arg3);
        temp_v0->unk0 = var_s2;
        temp_v0->unk1 = sp34;
    }

    func_80259EA8(self, arg1, arg2);
}

void func_8025A104(enum comusic_e arg0, s32 arg1){
    if (arg0 != musicTracks[0].track_id){
        func_8024FC1C(0, arg0);
    }

    musicTrack_setVolume(0, (s16)arg1);
    musicTracks[0].track_id = (s16) arg0;
    musicTracks[0].volume = arg1;
    musicTracks[0].unk0 = 0.0f;
    musicTracks[0].unk12 = 0;
    musicTracks[0].unk4 = 0.0f;
    musicTracks[0].unk15 = 0;
    func_80259994(&musicTracks[0], arg1);
}

void func_8025A1A8(enum comusic_e arg0){
    if (arg0 == musicTracks[0].track_id) {
        return;
    }

    func_8024FC1C(0, arg0);

    musicTracks[0].track_id = (s16) arg0;
    musicTracks[0].volume = gcMusic_getDefaultVolumeForTrack(arg0);
    musicTracks[0].unk0 = 0.0f;
    musicTracks[0].unk12 = 0;
    musicTracks[0].unk4 = 0.0f;
    musicTracks[0].unk15 = 0;

    func_80259994(&musicTracks[0], musicTracks[0].volume);
}

void func_8025A23C(s32 arg0){
    CoMusic *music = &musicTracks[5];
    s32 temp_v0;

    if (arg0 == music->track_id){
        return;
    }

    func_8024FC1C(5, arg0);
    music->track_id = (s16) arg0;
    temp_v0 = gcMusic_getDefaultVolumeForTrack(arg0);
    music->volume = temp_v0;
    music->unk12 = 0;
    music->unk15 = 0;
    music->unk0 = 0.0f;
    music->unk4 = 0.0f;
    func_80259994(music, temp_v0);
}

void func_8025A2B0(void) {
    func_802599B4(&musicTracks[5]);
}

void func_8025A2D8(void) {
    func_802599B4(&musicTracks[0]);
}

void func_8025A2FC(s32 arg0, s32 arg1){
    s32 i;

    func_8025A55C(arg0, arg1, 1);
    for (i = 1; i < 5; i++){
        s16 val = (i + musicTracks)->track_id; // Doesn't match with musicTracks[i]
        if (val >= 0){
            func_8025ABB8(val, arg0, arg1, 1);
        }
    }
}

void func_8025A388(s32 arg0, s32 arg1) {
    s32 i;

    if (musicTracks->unk14 == 0){
        func_8025A55C(arg0, arg1, 1);
    }

    for (i = 1; i < 5; i++) {
        CoMusic *current = (i + musicTracks); // Doesn't match with musicTracks[i]

        if (current->track_id >= 0 && current->unk14 == 0) {
            func_8025ABB8(current->track_id, arg0, arg1, 1);
        }
    }
}

void func_8025A430(s32 arg0, s32 arg1, s32 arg2){
    s32 i;

    func_8025A55C(arg0, arg1, arg2);

    for (i = 1; i < 5; i++) {
        s16 val = (i + musicTracks)->track_id; // Doesn't match with musicTracks[i]

        if (val >= 0) {
            func_8025ABB8(val, arg0, arg1, arg2);
        }
    }
}

void func_8025A4C4(s32 arg0, s32 arg1, s32 *arg2) {
    if (musicTracks[0].track_id < 0) {
        return;
    }

    func_80259F7C(&musicTracks[0], &arg0, &arg1, arg2);

    if (arg0 != musicTracks[0].volume) {
        if (musicTracks[0].volume < arg0) {
            musicTracks[0].unk12 = arg1;
        } else {
            musicTracks[0].unk12 = -arg1;
        }

        musicTracks[0].unkC = arg0;
        D_80276E34 = 1;
    }
}

void func_8025A55C(s32 arg0, s32 arg1, s32 arg2) {
    func_8025A4C4(arg0, arg1, &musicTracks->unk1C[arg2]);
}

void func_8025A58C(s32 arg0, s32 arg1) {
    func_8025A55C(arg0, arg1, 0);
}

void playMusic(enum comusic_e comusic_id, s32 volume, s32 forceReInit) {
    CoMusic *track;
    s32 index;

    if (volume == -1) {
        volume = gcMusic_getDefaultVolumeForTrack(comusic_id);
    }

    track = findTrack(comusic_id);

    if (track == NULL) {
        return;
    }

    index = track - musicTracks;

    // Initialize the track if findTrack returned an empty
    if (track->track_id < 0 || forceReInit) {
        switch (comusic_id) {
            case COMUSIC_15_EXTRA_LIFE_COLLECTED:
                if (gsworld_get_map() == MAP_10_BGS_MR_VILE) {
                    break;
                }
            case COMUSIC_3B_MINIGAME_VICTORY:
            case COMUSIC_3C_MINIGAME_LOSS:
                func_8025AE50(4000, 2.0f);
        }

        track->track_id = comusic_id;
        track->unk12 = 0;
        track->unk15 = 0;
        track->unk4 = 0.0f;
        func_80259994(track, volume);
        func_8024FC1C(index, comusic_id);
    }

    musicTrack_setVolume(index, (s16) volume);
    track->volume = volume;
}

// If findTrack returns the track, then do not re-initialize; just adust the volume
void coMusicPlayer_playMusicWeak(enum comusic_e track_id, s32 volume) {
    playMusic(track_id, volume, FALSE);
}

// Plays the track and reinitializes it
void coMusicPlayer_playMusic(enum comusic_e track_id, s32 volume) {
    playMusic(track_id, volume, TRUE);
}

//comusic_queueTrack
void comusic_playTrack(enum comusic_e track_id) {
    CoMusic *trackPtr;
    s32 indx;

    trackPtr = findTrack(track_id);

    if (trackPtr == NULL) {
        return;
    }
    
    indx = trackPtr - musicTracks;

    if (trackPtr->track_id < 0) {
        trackPtr->track_id = track_id;
        trackPtr->unk12 = 0;
        trackPtr->unk4 = 0.0f;
        func_8024FC1C( indx, track_id);
        func_80259994(trackPtr, trackPtr->volume = gcMusic_getDefaultVolumeForTrack(track_id));
    }
}

void func_8025A788(enum comusic_e comusic_id, f32 delay1, f32 delay2) {
    timedFunc_set_1(delay1, (GenFunction_1) comusic_playTrack, comusic_id);
    timedFunc_set_1(delay1 + delay2, (GenFunction_1) func_8025A7DC, comusic_id);
}

void func_8025A7DC(enum comusic_e track_id) {
    CoMusic *trackPtr;

    trackPtr = findTrack(track_id);

    if (trackPtr != NULL && trackPtr->track_id >= 0){
        func_802599B4(trackPtr);
    }
}

s32 func_8025A818(void) {
    if (musicTracks[0].unkC == 0 && musicTracks[0].volume <= 0){
        func_802599B4(&musicTracks[0]);
        return 1;
    }

    return 0;
}

s32 func_8025A864(enum comusic_e track_id){
    CoMusic *trackPtr;

    trackPtr = findTrack(track_id);

    if (trackPtr != NULL && trackPtr->unkC == 0 && trackPtr->volume <= 0){
        func_802599B4(trackPtr);
        return 1;
    }

    return 0;
}

void func_8025A8B8(enum comusic_e track_id, s32 arg1){
    CoMusic *trackPtr;

    trackPtr = findTrack(track_id);

    if (trackPtr != NULL){
        trackPtr->unk14 = arg1;
    }
}

void func_8025A8E4(s32 arg0) {
    if (musicTracks[0].track_id < 0) {
        return;
    }

    musicTracks[0].unk14 = arg0;
}

void func_8025A904(void){
    CoMusic *trackPtr = &musicTracks[0];

    while (trackPtr < &musicTracks[6]) {
        if (trackPtr->track_id >= 0) {
            func_802599B4(trackPtr);
        }

        trackPtr++;
    }
}

//dequeue_allTracks
void func_8025A96C(void){
    CoMusic *iPtr;

    for (iPtr = &musicTracks[1]; iPtr < &musicTracks[MAX_MUSIC_STRUCT_COUNT]; iPtr++) {
        if (iPtr->track_id >= 0) {
            func_802599B4(iPtr);
        }
    }
}

//dequeue_allTracks
void func_8025A9D4(void){
    CoMusic *iPtr;

    for (iPtr = &musicTracks[0]; iPtr < &musicTracks[MAX_MUSIC_STRUCT_COUNT]; iPtr++) {
        if (iPtr->track_id >= 0 && !iPtr->unk14) {
            func_802599B4(iPtr);
        }
    }
}

//dequeue_nonmainTracks
void func_8025AA48(void){
    CoMusic *iPtr;

    for (iPtr = &musicTracks[1]; iPtr < &musicTracks[6]; iPtr++) {
        if (iPtr->track_id >= 0 && !iPtr->unk14) {
            func_802599B4(iPtr);
        }
    }
}

//dequeue_track?
void func_8025AABC(enum comusic_e track_id) {
    CoMusic *trackPtr;

    trackPtr = findTrack(track_id);

    if (!trackPtr) {
        return;
    }
    
    trackPtr->unk15 = 1;

    if (!trackPtr->volume) {
        func_802599B4(trackPtr);
    }
}

void func_8025AB00(void) {
    musicTracks[0].unk15 = 1;

    if (musicTracks[0].volume){
        return;
    }

    func_802599B4(&musicTracks[0]);
}

void comusic_8025AB44(enum comusic_e comusic_id, s32 arg1, s32 arg2){
    func_8025AC20(comusic_id, arg1, arg2, 0.0f, "comusic.c", VER_SELECT(0x39e, 0x39f, 0, 0));
}

void comusic_8025AB78(enum comusic_e comusic_id, s32 arg1, s32 arg2, s32 arg3){
    func_8025AC7C(comusic_id, arg1, arg2, 0.0f, arg3, "comusic.c", VER_SELECT(0x3a3, 0x3a4, 0, 0));
}

void func_8025ABB8(enum comusic_e comusic_id, s32 arg1, s32 arg2, s32 arg3){
    func_8025AC7C(comusic_id, arg1, arg2, 0.0f, (s32)&(findTrack(comusic_id)->unk1C[arg3]), "comusic.c", VER_SELECT(0x3aa, 0x3ab,0,0));
}

void func_8025AC20(enum comusic_e comusic_id, s32 arg1, s32 arg2, f32 arg3, char* arg4, s32 char5){
    func_8025AC7C(comusic_id, arg1, arg2, 0.0f, (s32) findTrack(comusic_id)->unk1C, "comusic.c", VER_SELECT(0x3b1, 0x3b2,0,0));
}

void func_8025AC7C(enum comusic_e comusic_id, s32 arg1, s32 arg2, f32 arg3, s32 *arg4, char* arg5, s32 arg6){
    CoMusic *trackPtr;
    u32 slot_index;

    //get track location
    trackPtr = findTrack(comusic_id);
    if(trackPtr == NULL)
        return;

    //check if track is loaded in slot
    if(trackPtr->track_id < 0){ //Track not loaded
        if(arg1 == 0)
            return;
        slot_index = (trackPtr - musicTracks);
        func_8024FC1C(slot_index, comusic_id);
        trackPtr->track_id = comusic_id;
        trackPtr->volume = 0;
        trackPtr->unk15 = 0;
        trackPtr->unk4 = 0.0f;
        func_80259994(trackPtr, 0);
        musicTrack_setVolume(slot_index, 0);
    }
    func_80259F7C(trackPtr,&arg1, &arg2, arg4);
    trackPtr->unk0 = arg3;
    trackPtr->unk12 = (trackPtr->volume < arg1)? arg2: -arg2;
    trackPtr->unkC = arg1;
    D_80276E34 = 1;
}

//comusic_trackQueued
int func_8025AD7C(enum comusic_e arg0) {
    CoMusic * trackPtr = findTrack(arg0);
    return (trackPtr == NULL || trackPtr->track_id == -1)? 0 : 1;
}

//comusic_isPrimaryTrack
int func_8025ADBC(enum comusic_e arg0) {
    return musicTracks[0].track_id == arg0;
}

s32 func_8025ADD4(enum comusic_e id) {
    CoMusic * ptr = findTrack(id);
    return ptr - musicTracks;
}

void func_8025AE0C(s32 arg0, f32 arg1) {
    func_8025A58C(0, arg0);
    timedFunc_set_2(arg1, (GenFunction_2)func_8025A58C, -1, arg0);
}

void func_8025AE50(s32 arg0, f32 arg1) {
    func_8025A430(0, arg0, 6);
    timedFunc_set_3(arg1, (GenFunction_3)func_8025A430, -1, arg0, 6);
}

void func_8025AEA0(enum comusic_e track_id, s32 arg1) {
    CoMusic *ptr = findTrack(track_id);
    
    if (!ptr) {
        return;
    }

    func_8024FDDC(ptr - musicTracks, arg1);
}

int func_8025AEEC(void) {
    s32 out = func_802501A0(0, 0x6A, 0);

    if (out) {
        func_80250170(0, 0x6A, 0);
    }

    return out;
}

void comusic_defrag(void) {
    CoMusic *iPtr;

    if (!musicTracks) {
        return;
    }

    for (iPtr = &musicTracks[0]; iPtr < &musicTracks[MAX_MUSIC_STRUCT_COUNT]; iPtr++) {
        iPtr->unk18 = (FREE_LIST(struct12s) *)freelist_defrag(iPtr->unk18);
    }

    musicTracks = (CoMusic *)defrag(musicTracks);
}
