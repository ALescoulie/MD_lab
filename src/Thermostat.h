//
// Created by Alia Lescoulie on 5/16/22.
//

#ifndef MD_LAB_THERMOSTAT_H
#define MD_LAB_THERMOSTAT_H


#include "CubicBox.h"

class Thermostat {
public:
    const double kb = 8.31151e51;
    Thermostat(double temp, double dt);
    void randomize_velocities(CubicBox* box);
    double measure_temp(CubicBox* box);
private:
    double temp;
    double dt;
    const Vec3 z_vec = Vec3(0, 0, 0);
    static Vec3 calc_avg_vel(CubicBox* box);
};

#endif //MD_LAB_THERMOSTAT_H
