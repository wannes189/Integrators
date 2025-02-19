#ifndef CLASSES_H
#define CLASSES_H
#include <cmath>
#include <vector>
#include "Vec.h"
#include "Particle_object.h"


// calculate acceleration
Vec acc(double mu, Vec r)
{
    return -mu * r/r.norm3();
}

// calculate energy
double energy(double mu, Vec r, Vec v)
{
    return 0.5*v.norm() - mu/r.norm();
}

double EnergyCalc(std::vector<Particle_object>* particles, int N, double G) {
    double energy = 0;
    for (int i=0; i < N; ++i) {
        //Kinetische energie afkomstig van deeltje i
        energy += 0.5 * (*particles)[i].Mass() * (*particles)[i].Velocity().norm2();
        //Potentiele energie afkomstig van deeltje i ten gevolge van andere deeltjes j>i
        for (int j=i+1; j < N; ++j) {
            energy -= 0.5 * G * (*particles)[i].Mass() * (*particles)[j].Mass() / ((*particles)[i].Position() - (*particles)[j].Position()).norm();
        }
    }
    return energy;
}

Vec NBodyAcc(double G, double mass, Vec pos1, Vec pos2) {
    double abs = (pos1 - pos2).norm();
    return  - G * mass * (pos1 - pos2) / (abs*abs*abs);
}

Vec accformula(Vec position_i, Vec position_j, double mass_j, double G=6) {
    return G * mass_j * (position_i-position_j)/((position_i-position_j).norm3());
}

Vec accNbody(std::vector<Particle_object> array_of_particles, int size, int i) {
    Vec acceleration;

    for (int j = 0; j < size; ++j) {
        if (i != j) {
            Vec position_i = array_of_particles[i].Position();
            Vec position_j = array_of_particles[j].Position();
            double mass_j = array_of_particles[j].Mass();
            acceleration = acceleration - accformula(position_i, position_j, mass_j);
        }
    }
    return acceleration;
}

#endif