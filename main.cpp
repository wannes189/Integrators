#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include "Vec.h"
#include "Particle_object.h"
#include "Particle_initializer.h"


#include "leapfrog2body.h"
#include "leapfrogmanybodies.h"

int main() {
    //set program parameters
     double TimeStep = 0.01;
     const double G = 1;
     const double TotalTime = 60;

    //Initialize particles
    std::vector<Particle_object> particles;
    GetParticles(&particles, "initial_particles.txt");
    int N = particles.size();

    // //Run RK4
    // RK4_Nbody(particles, TimeStep, TotalTime, N, G);

    // //Run Forest Ruth for 2body problem
    // forestruthNbody(particles, TimeStep, TotalTime, N, G);

    // //Run Leapgrof for Nbody problem
    // leapfrogNbody(particles, TimeStep, TotalTime, N, G);

    // //Determine initial conditions for the 2body case
    double mu = 0.01;
    Vec r0 = Vec(1, 0, 0);
    Vec v0 = Vec(0, 0.06, 0);

    // //Run RK4 for 2body system
    // RK4_2body(r0, v0, mu, TimeStep);

    // //Run Forest Ruth for 2body problem
    // ForestRuth2Body(r0, v0, mu, TimeStep);

    //Run Leapfrog for 2body problem
    Leapfrog2Body(r0, v0, mu, TimeStep, TotalTime);
}