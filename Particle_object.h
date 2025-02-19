#ifndef PARTICLE_OBJECT_H2
#define PARTICLE_OBJECT_H2
#include <cmath>
#include "Vec.h"

class Particle_object
{
    double m;
    double p_x;
    double p_y;
    double p_z;
    double v_x;
    double v_y;
    double v_z;
public:
    Particle_object() {m=0; p_x=0; p_y=0; p_z=0; v_x=0; v_y=0; v_z=0;}
    Particle_object(double mass, double x, double y, double z, double vx, double vy, double vz) {m = mass; p_x = x; p_y = y; p_z = z; v_x = vx; v_y = vy; v_z = vz;}
    
    //Get positions
    double px() {return p_x;}
    double py() {return p_y;}
    double pz() {return p_z;}
    Vec Position() {
        Vec positionvector = Vec(p_x, p_y, p_z);
        return positionvector;
    }
    //Get velocities
    double vx() {return v_x;}
    double vy() {return v_y;}
    double vz() {return v_z;}
    Vec Velocity() {
        Vec velocityvector = Vec(v_x, v_y, v_z);
        return velocityvector;
    }
    //Get mass
    double Mass() {return m;}

    //Set positions and velocities
    void setPosition(Vec a) {
        p_x = a.x();
        p_y = a.y();
        p_z = a.z();
    }
    void setVelocity(Vec a) {
        v_x = a.x();
        v_y = a.y();
        v_z = a.z();
    }
};

#endif