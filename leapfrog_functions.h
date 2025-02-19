#ifndef LEAPFROG_FUNCTIONS_H
#define LEAPFROG_FUNCTIONS_H
#include <cmath>
#include "Vec.h"
#include "Particle_initializer.h"
#include "classes.h"
using namespace std;

// calculate leapfrog r_half
Vec r_half(Vec r_0, Vec v_0, Vec a_0, double h)
{
    return r_0 + 0.5*h*v_0 + (h*h)*a_0/8;
}


// calculate leapfrog r_nhalf
Vec leapfrogstep(Vec r, Vec v, double h)
{
    return r + h*v;
}

Vec acceleration(Vec r0, double mu) 
{
    return -mu * r0 / r0.norm3();
}

double energy(Vec rn, Vec vn, double mu)
{
    return 0.5 * vn.norm2() - mu/rn.norm();
}

#endif