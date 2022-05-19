//
// Created by Alia Lescoulie on 5/16/22.
//

#include "Thermostat.h"

#include "random"
#include "cmath"

Thermostat::Thermostat(double temp) {
    this->temp = temp;
}

void Thermostat::radomize_velocities(CubicBox *box) {
    std::random_device rd;
    std::mt19937 gen(rd);
    std::uniform_real_distribution<> dis(-1000, 1000);
    for (int i = 0; i < box->get_n_atoms(); i++) {
        Vec3 r_vel = Vec3(dis(gen), dis(gen), dis(gen));
        box->update_vel(i, r_vel);
    }
    auto avg = calc_avg_vel(box);
    for (int i = 0; i < box->get_n_atoms(); i++) {
        auto cur_vel = box->get_atom(i).get_vel();
        cur_vel.vec_sub(avg);
        box->update_vel(i, cur_vel);
    }
}

Vec3 Thermostat::calc_avg_vel(CubicBox *box) {
    auto avg = Vec3(0, 0, 0);
    for (int i = 0; i < box->get_n_atoms(); i++) {
        auto tmp = box->get_atom(i).get_vel();
        avg.vec_add(tmp);
    }
    avg.vec_scale((double)1/box->get_n_atoms());
    return avg;
}

double Thermostat::measure_temp(CubicBox *box) {
    double t = 0;
    int df = box->get_n_atoms()*3;
    for (int i = 0; i < box->get_n_atoms(); i++) {
        double v = box->get_atom(i).get_vel().vec_dist(z_vec);
        double m = box->get_atom(i).get_mass();
        t += (m * v * v)/(kb * df);
    }
    return t;
}
