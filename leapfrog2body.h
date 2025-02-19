#ifndef LEAPGROG2BODY_H
#define LEAPGROG2BODY_H
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "Vec.h"
#include "Particle_initializer.h"
#include "classes.h"
#include "leapfrog_functions.h"

void Leapfrog2Body(Vec r_0, Vec v_0, const double mu=0.01, double Timestep=0.01, double Totaltime=60)
{
    std::cout << "Writing to file 'leapfrog.txt'..." << std::endl;

    std::ofstream outfile("txt_output/leapfrog.txt");
    outfile << setprecision(12);

    // define initial conditions
    const double First_Energy = energy(r_0, v_0, mu);
    

    // calculate r_half and v_1
    Vec r_05 = r_half(r_0, v_0, acc(mu, r_0), Timestep);
    Vec rn = r_0;
    Vec vn = v_0;
    Vec a_05 = acceleration(r_05, mu);
    double time = 0;
    double Energy = energy(rn, vn, mu);
    double Energy_error = abs(First_Energy - Energy)/Energy;
    outfile << 0 << ' ' << rn.x() << ' ' << rn.y() << ' ' << rn.z() << ' ' << vn.x() << ' ' << vn.y() << ' ' << vn.z() << ' ' << Energy_error <<'\n';

    for (time += Timestep; time < Totaltime + Timestep/2; time += Timestep)
    {
        a_05 = acceleration(r_05, mu);
        vn = leapfrogstep(vn, a_05, Timestep);
        rn = leapfrogstep(r_05, vn, Timestep*0.5);
        r_05 = leapfrogstep(r_05, vn, Timestep);
        Energy = energy(rn, vn, mu);
        Energy_error = abs(First_Energy - Energy)/Energy;
        outfile << time << ' ' << rn.x() << ' ' << rn.y() << ' ' << rn.z() << ' ' << vn.x() << ' ' << vn.y() << ' ' << vn.z() << ' ' << Energy_error <<'\n';
    }
    outfile.close();

    std::cout << "Done writing." << std::endl;
    
}

#endif