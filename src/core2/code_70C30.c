#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern struct6s *D_80381030;
extern struct3s *D_80381034;

void func_802F7BC0(Gfx **gdl, Mtx **mptr, Vtx **vptr){
    if(D_80381030){
        func_802F8A90(D_80381030, gdl, mptr, vptr);
    }
    if(D_80381034){
        func_802F8110(D_80381034, gdl, mptr, vptr);
    }
    func_802F962C(gdl, mptr, vptr);
}

struct6s *func_802F7C38(void){
    if(D_80381030 == NULL){
        D_80381030 = func_802F8BE0(50); //new CCW weather
    }
    return D_80381030;
}

struct3s *func_802F7C7C(void){
    if(D_80381034 == NULL){
        D_80381034 = func_802F8264(30); //rain
    }
    return D_80381034;
}

void func_802F7CC0(void){
    func_802F9054();
}

void func_802F7CE0(void){
    if(D_80381030){
        func_802F8B8C(D_80381030);
    }

    if(D_80381034){
        func_802F8214(D_80381034);
    }
    func_802F8FFC();
}

void func_802F7D30(void){
    D_80381030 = NULL;
    ((void **)&D_80381030)[1] = NULL;
}

void func_802F7D44(void){
    if(D_80381030){
        func_802F8C90(D_80381030);
    }

    if(D_80381034){
        func_802F8338(D_80381034);
    }
    func_802F90F4();
}

void func_802F7D94(void){
    if(D_80381030){
        func_802F8CB0(D_80381030);
    }

    if(D_80381034){
        func_802F8358(D_80381034);
    }
    func_802F9114();
}

void func_802F7DE4(void){
    if(D_80381030){
        func_802F8A70(D_80381030);
        func_802F8CB0(D_80381030);
    }

    if(D_80381034){
        func_802F80F0(D_80381034);
        func_802F8358(D_80381034);
    }
    func_802F8FF0();
    func_802F9114();
}

void func_802F7E54(void){
    if(D_80381030){
        func_802F8CD0(D_80381030);
    }

    if(D_80381034){
        func_802F83AC(D_80381034);
    }
    func_802F919C();
}