#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/ba/timer.h"

void func_80291488(s32 arg0);
void func_802914CC(s32 arg0);

/* .bss */
u8 D_8037C060;
u8 D_8037C061;
u8 D_8037C062;
s32 D_8037C064;
s32 D_8037C068;
s32 D_8037C06C;
s32 D_8037C070;
s32 D_8037C074;
s32 D_8037C078;
s32 D_8037C07C;
s32 D_8037C080;
s32 D_8037C084;

/* .code */
void func_80290B60(s32 arg0){
    D_8037C061 = arg0;
}

void func_80290B6C(void){
    func_802BC5CC();
    func_80290220();
    D_8037C060 = 0;
    D_8037C062 = 0;
    func_80291488(2);
    func_80290B60(2);
    batimer_set(7, 0.5f);
}

void func_80290BC0(s32 arg0){
    func_802BC538(arg0, 
        &D_8037C064,&D_8037C068,&D_8037C06C,
        &D_8037C070,&D_8037C074,&D_8037C078,
        &D_8037C07C,&D_8037C080,&D_8037C084
    );
    
    if(D_8037C061 == 3 && D_8037C07C == 0){
        func_80290B60(2);
    }
    switch (D_8037C061)
    {
    case 1://L80290C8C
        func_802BD8A4(D_8037C064, D_8037C068, D_8037C06C);
        break;
    case 2: //L80290CC8
        func_802BD8A4(D_8037C070, D_8037C074, D_8037C078);
        break;
    case 3://L80290D04
        func_802BD8A4(D_8037C07C, D_8037C080, D_8037C084);
        break;
    }
}

int func_80290D48(void){
    int camera_node_index;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;


    camera_node_index = func_802903CC();
    if(camera_node_index == -1 || !ncCameraNodeList_nodeIsValid(camera_node_index)){
        func_80290BC0(0);
        return FALSE;
    }

    sp1C = bs_getState();
    switch(ncCameraNodeList_getNodeType(camera_node_index)){
        case 4:
            sp28 = ncCameraNodeList_getCameraNodeType4(camera_node_index);
            sp24 = code33250_func_802BA234(sp28);
            func_80290BC0(sp24);
            return FALSE;
        case 3: //L80290DD8
            if(bsBeeFly_inSet(sp1C) && !code33310_func_802BA4D0(ncCameraNodeList_getCameraNodeType3(camera_node_index))){
                return FALSE;
            }
            ncDynamicCamera_setState(0x11);
            func_802BF798(camera_node_index);
            func_80291488(0x9);
            return TRUE;
        case 1://L80290E28
            if(bsBeeFly_inSet(sp1C) && !code336F0_func_802BA89C(ncCameraNodeList_getCameraNodeType1(camera_node_index))){
                return FALSE;
            }
            ncDynamicCamera_setState(0x8);
            ncDynamicCam8_func_802BF9B8(camera_node_index);
            func_80291488(0x9);
            return TRUE;
        default://L80290E7C
            return FALSE;
    }
    

}

int func_80290E8C(void){
    if(player_getWaterState() != BSWATERGROUP_2_UNDERWATER)
        return FALSE;

    ncDynamicCamera_setState(3);
    func_80291488(0xB);
    if( map_get() == MAP_B_CC_CLANKERS_CAVERN
        && player_getYPosition() < 1201.0f
    ){
        func_802C1B20(1100.0f);
    }
    return TRUE;
}

void func_80290F14(void){
    if( !func_80298850() 
        && func_8028ECAC() != 4
        && batimer_get(7) == 0.0f
        && should_zoom_out_camera()
    ){
        switch(D_8037C061){
            case 1://L80290FA4
                func_80299D2C(SFX_12E_CAMERA_ZOOM_MEDIUM, 1.0f, 12000);
                func_80290B60(2);
                break;
            case 2://L80290FBC
                if(D_8037C07C){
                    func_80299D2C(SFX_12E_CAMERA_ZOOM_MEDIUM, 1.2f, 12000);
                    func_80290B60(3);
                }
                else{
                    func_80299D2C(SFX_12D_CAMERA_ZOOM_CLOSEST, 1.0f, 12000);
                    func_80290B60(1);
                }
                break;
            case 3://L80291008
                func_80299D2C(SFX_12D_CAMERA_ZOOM_CLOSEST, 1.0f, 12000);
                func_80290B60(1);
                break;
        }
        batimer_set(0x7, 0.4f);
    }
}

void func_8029103C(void){
    func_80299EB4();
}

int func_8029105C(s32 arg0){
    if(func_80298850())
        return FALSE;

    if(should_rotate_camera_left() && ncDynamicCamA_func_802C1DB0(-45.0f)){
        func_80291488(arg0);
        func_8029103C();
        return TRUE;
    }
    
    if(should_rotate_camera_right() && ncDynamicCamA_func_802C1DB0(45.0f)){
        func_80291488(arg0);
        func_8029103C();
        return TRUE;
    }

    return FALSE;
}

//_camera_mode_1_update
void func_80291108(void){
    if(!func_80290D48() && ncDynamicCamera_getState() == 0x10){
        func_80290F14();
        func_8029105C(8);
    }
}

//_camera_mode_2_3_b_update
void func_80291154(void){
    int tmp;
    if(!func_80290D48() && !func_80290E8C()){
        if(bakey_held(BUTTON_R)){
            ncDynamicCamera_setState(0x13);
            func_80291488(0x4);
            func_80290F14();
        }
        else{
            tmp = func_8029105C(7);
            func_80290F14();
            if(!tmp)
                ncDynamicCamera_setState(0xB);
        }
    }
}

//_camera_mode_4 and_c_update
void func_802911E0(void){
    if( !func_80290D48() && !func_80290E8C() && !func_8029105C(7)){
        func_80290F14();
        if(bakey_held(BUTTON_R)){
            func_802C095C();
        }
        else{
            if(func_802C0640())
                func_80291488(2);
        }
    }
}

//_camera_mode_7_update
void func_80291268(void){
    if( !func_80290D48() && !func_80290E8C()){
        func_80290F14();
        if(!func_8029105C(7) && ncDynamicCamA_func_802C1EE0()){
            func_80291488(2);
        }
    }
}

//_camera_mode_8_update
void func_802912D0(void){
    if(!func_80290D48()){
        func_80290F14();
        if(!func_8029105C(8) && ncDynamicCamA_func_802C1EE0()){
            func_802914CC(0x10);
        }

    }
}

//_camera_mode_A_update
void func_80291328(void){
    if(func_802C189C()){
        func_80291488(2);
    }
}

/* camera update */
void cameraMode_update(void){
    batimer_decrement(7);
    func_80290298();
    func_8029028C(0);
    switch(D_8037C062){
        case 0x9: //L802913A0
            if(func_80290D48())
                break;
            if(D_8037C060){
                func_80291488(1);
                ncDynamicCamera_setState(D_8037C060);
            }
            else{
                func_80291488(2);
            }
            break;
        case 0x1: //L802913E8
            func_80291108();
            break;
        case 0x7: //L802913F8
            func_80291268();
            break;
        case 0x8: //L80291408
            func_802912D0();
            break;

        case 0x4: //L80291418
        case 0xc: //L80291418
            func_802911E0();
            break;
        
        case 0xa: //L80291428
            func_80291328();
            break;

        default://80291438
            if(D_8037C060){
                func_80291488(1);
                ncDynamicCamera_setState(D_8037C060);
            }
            else{
                func_80291154();
            }
            break;
        
        case 0x5: //L8029146C
        case 0x6: //L8029146C
        case 0x0: //L8029146C
            break;
    }
}

s32 func_8029147C(void){
    return D_8037C062;
}

void func_80291488(s32 arg0){
    if(D_8037C062 == 0xa && arg0 != D_8037C062){
        func_8029028C(1);
    }
    D_8037C062 = arg0;
}

void func_802914CC(s32 arg0){
    D_8037C060 = arg0;
    if(D_8037C062 != 9 && D_8037C062 != 0xa){
        func_80291488(1);
        ncDynamicCamera_setState(arg0);
    }
}

void func_8029151C(s32 arg0){
    func_80291488(6);
    ncDynamicCamera_setState(arg0);
}

void func_80291548(void){
    D_8037C060 = 0;
    if(D_8037C062 != 9 && D_8037C062 != 0xa){
        func_80291488(2);
    }
}
