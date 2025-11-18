#ifndef BASECONNAISSANCE_H
#define BASECONNAISSANCE_H
#include "Regle.h"

typedef Regle *BC;

BC create_BC();
BC add_rules(BC bc, Regle *r);
BaseFait MI(BC baseC, BaseFait baseF);

#endif