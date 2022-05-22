//
// Created by Alia Lescoulie on 5/6/22.
//

#ifndef MD_LAB_SIMULATION_H
#define MD_LAB_SIMULATION_H

#include <list>
#include <vector>
#include <string>

#include "Atom.h"
#include "ForceField.h"
#include "Boundary.h"
#include "Thermostat.h"
#include "Reader.h"
#include "CubicBox.h"


class Simulation {
public:
    Simulation(std::string topology, std::string trajectory,
               ForceField* forces, Thermostat* thermo,double temp,
               double size, double ts, double time, int st_frame);
    void run();
private:
    void write_frame(CubicBox* box);
    std::string top;
    chemfiles::Trajectory trj = chemfiles::Trajectory("defualt.xyz");
    std::list<Atom> atoms;
    double size;
    double dt;
    double time;
    int frame_step;
    CubicBox* box;
    ForceField* field;
    Thermostat* therm;
};


#endif //MD_LAB_SIMULATION_H
