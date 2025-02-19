#ifndef LEAPFROG_NBODY_H2
#define LEAPFROG_NBODY_H2
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include "Vec.h"
#include "Particle_object.h"
#include "classes.h"
#include "leapfrog_functions.h"


void leapfrogNbody(std::vector<Particle_object> alldeeltjes_old, double TimeStep, const double TotalTime, int N, const double G)
{
    std::cout << "Writing to file 'leapfrog.txt'..." << endl;

    //eenheden: 1.989e30 kg = 1 zonsmassa
    // 149597870700 meter = 1 AU
    // 86400 seconden = 1 dag
    // G = 6.674e-11 m^3 s^(-2) kg^-1

    ofstream outfile("txt_output/leapfrogNbody.txt");

    outfile << setprecision(15);

    outfile << N << endl;

    //Make a second vector, to edit and remember positions/velocities
    vector<Particle_object> alldeeltjes = alldeeltjes_old;

    
    //Calculate energy
    double StartEnergy = EnergyCalc(&alldeeltjes, N, G);
    double Energy;
    double Energy_error;
    double time;
    double acceleration;
    


    // calculate r_half
    for (int i = 0; i<N; ++i) {
            Particle_object r05 = alldeeltjes_old[i];
            alldeeltjes[i].setPosition(r_half(r05.Position(), r05.Velocity(), accNbody(alldeeltjes_old, N, i), TimeStep));        
    }

     

    Energy = EnergyCalc(&alldeeltjes_old, N, G);
    Energy_error = abs(StartEnergy - Energy)/Energy;

    for (int i = 0; i<N; ++i) {
            outfile << 0 << ' ' << alldeeltjes_old[i].Position().x() << ' ' << alldeeltjes_old[i].Position().y() << ' ' << alldeeltjes_old[i].Position().z() << ' ' << alldeeltjes_old[i].Velocity().x() << ' ' << alldeeltjes_old[i].Velocity().y() << ' ' << alldeeltjes_old[i].Velocity().z() << ' ' << Energy_error <<'\n';
        
    }

    for (time += TimeStep; time <=TotalTime; ++TimeStep) {

        // acceleration = vers
        
        for (int i = 0; i <N; ++i)
        {
            // calculate v_new
            alldeeltjes[i].setVelocity(leapfrogstep(alldeeltjes_old[i].Velocity(), accNbody(alldeeltjes_old, N, i), TimeStep));
        
        }

        for (int i = 0; i <N; ++i)
        {
            // calculate r_new
            alldeeltjes[i].setPosition(leapfrogstep(alldeeltjes_old[i].Position(), alldeeltjes[i].Velocity(), TimeStep));
        }

        

        for (int i = 0; i <N; ++i)
        {
            // adjust r and v to list and rename r_old and v_old
            Vec save_new_data = alldeeltjes[i].Position();
            alldeeltjes[i].setPosition((save_new_data + alldeeltjes_old[i].Position())/2.0);
            alldeeltjes_old[i].setPosition( save_new_data);
            alldeeltjes_old[i].setVelocity(alldeeltjes[i].Velocity());
        
        }
        //calculate energy:

        double Energy = EnergyCalc(&alldeeltjes, N, G);

        double Energy_error = abs((StartEnergy - Energy)/Energy);
        
        for (int i = 0; i<N; ++i) {
            outfile << time << ' ' << alldeeltjes[i].Position().x() << ' ' << alldeeltjes[i].Position().y() << ' ' << alldeeltjes[i].Position().z() << ' ' << alldeeltjes[i].Velocity().x() << ' ' << alldeeltjes[i].Velocity().y() << ' ' << alldeeltjes[i].Velocity().z() << ' ' << Energy_error <<'\n';
        
        }
        outfile << endl;
    }
    outfile.close();


    cout << "Done writing." << endl;
}

#endif