#include <ultra64.h>

#ifndef BANJO_KAZOOIE_BOOL_H
#define BANJO_KAZOOIE_BOOL_H

typedef int bool;
#define NOT(boolean) ((boolean) ^ 1)
#define BOOL(boolean) ((boolean) ? TRUE : FALSE)

#endif
