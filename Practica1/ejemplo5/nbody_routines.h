#ifndef NBODY_ROUTINES_H
#define NBODY_ROUTINES_H

#include "nbody.h"

void bodyForce(body2 *p, float dt, int n);
void integrate(body2 *p, float dt, int n);

#endif
