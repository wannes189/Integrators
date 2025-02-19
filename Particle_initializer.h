#ifndef PARTICLE_INITIALIZER_H2
#define PARTICLE_INITIALIZER_H2
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
#include <iostream>
#include <string>
#include "Vec.h"
#include "Particle_object.h"

void GetParticles(std::vector<Particle_object>* particles, const std::string& filepath) {
    //Open fiel en check of file correct geopend is
    std::ifstream inputFile(filepath);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << filepath << std::endl;
        // Handle the error, for example, by returning an empty vector
        return;
    }
    
    double m, x, y, z, vx, vy, vz;
    while (inputFile >> m >> x >> y >> z >> vx >> vy >> vz) {
        particles->emplace_back(Particle_object(m, x, y, z, vx, vy, vz));
    }

    inputFile.close();
    return;
}

#endif