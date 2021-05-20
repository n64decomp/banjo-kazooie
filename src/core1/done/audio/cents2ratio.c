#include <libaudio.h>

f32 alCents2Ratio(s32 cents) 
{
    f32 x;
    f32 ratio = 1.0f;
    
    if (cents >= 0) {
        x = 1.00057779f;         /* 2^(1/1200) */
    } else {
        x = 0.9994225441f;       /* 2^(-1/1200) */
        cents = -cents;
    }
    
    while (cents) {
        if (cents & 1)
            ratio *= x;
        x *= x;
        cents >>= 1;
    }

    return ratio;
}
