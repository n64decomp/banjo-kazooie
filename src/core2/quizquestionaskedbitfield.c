#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define FF_QUESTION_ASKED_BITFIELD_SIZE 0x33

/* .bss */
u8* quizQuestionAskedBitfield;

/* .code */
bool quizQuestionAskedBitfield_get(s32 index){
    return bitfield_get_bit(quizQuestionAskedBitfield, index);
}

void quizQuestionAskedBitfield_free(void){
    free(quizQuestionAskedBitfield);
    quizQuestionAskedBitfield = NULL;
}

void quizQuestionAskedBitfield_init(void){
    int i;
    quizQuestionAskedBitfield =(u8*) malloc(FF_QUESTION_ASKED_BITFIELD_SIZE);
    for(i = 0; i < FF_QUESTION_ASKED_BITFIELD_SIZE; i++){
        quizQuestionAskedBitfield[i] = 0;
    }
}

void quizQuestionAskedBitfield_set(s32 index, bool value){
    bitfield_set_bit(quizQuestionAskedBitfield, index, value);
}

void quizQuestionAskedBitfield_defrag(void){
    if(quizQuestionAskedBitfield != NULL)
        quizQuestionAskedBitfield = (u8*)defrag(quizQuestionAskedBitfield);
}
