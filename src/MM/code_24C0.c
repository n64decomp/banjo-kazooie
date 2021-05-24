/*!!!DONE!!!*/
#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

extern ActorInfo chhutInfo;
extern ActorInfo chchimpystump;
extern ActorInfo chgrublinInfo;
extern ActorInfo chcongaInfo;
extern ActorInfo chorangeInfo;
extern ActorInfo chjujuhitboxInfo;
extern ActorInfo chjujuInfo;
extern ActorInfo chorangepadInfo;
extern ActorInfo chlmonkeyInfo;

void func_803888B0(void){
    func_803053E8( &chhutInfo,          actor_new,     0X400);
    func_803053E8( &chchimpystump,      actor_new,       0x0);
    func_803053E8( &chgrublinInfo,      actor_new, 0X2000121);
    func_803053E8( &chcongaInfo,        actor_new, 0X2000160);
    func_803053E8( &chorangeInfo,       actor_new,       0x0);
    func_803053E8( &chjujuhitboxInfo,   actor_new,       0x0);
    func_803053E8( &chjujuInfo,         actor_new,    0X4004);
    func_803053E8( &chorangepadInfo,    actor_new,      0X40);
    func_803053E8( &chlmonkeyInfo,      actor_new,     0X100);
}
