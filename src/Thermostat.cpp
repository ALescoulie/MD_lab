//
// Created by Alia Lescoulie on 5/16/22.
//

#include "Thermostat.h"

#include "random"
#include "cmath"

Thermostat::Thermostat(double temp, double dt, Boundary* bounds) {
    this->temp = temp;
    this->dt = dt;
    this->bounds = bounds;
}

void Thermostat::randomize_velocities(CubicBox *box) {
    std::default_random_engine rd;

    auto vel = static_cast<Vec3*>(malloc(sizeof(double) *
                                               box->get_n_atoms() * box->get_n_atoms()));
    std::uniform_real_distribution<double> dis(-1000, 1000);
    for (int i = 0; i < box->get_n_atoms(); i++) {
        vel[i] = Vec3(dis(rd), dis(rd), dis(rd));
    }
    box->update_vel(vel);

    auto avg = calc_avg_vel(box);
    for (int i = 0; i < box->get_n_atoms(); i++) {
        vel[i].vec_sub(avg);
    }

    double t_cur = measure_temp(box);
    double t_scale = sqrt(temp/t_cur);

    for (int i = 0; i < box->get_n_atoms(); i++) {
        vel[i].vec_scale(t_scale);
    }

    // Getting prev positions
    auto prev_pos = static_cast<Vec3*>(malloc(sizeof(double) *
                                         box->get_n_atoms() * box->get_n_atoms()));

    for (int i = 0; i < box->get_n_atoms(); i++) {
        prev_pos[i].vec_scale(0);
        prev_pos[i].vec_add(box->get_pos(i));
        auto c_vel = box->get_vel(i);
        c_vel.vec_scale(dt);
        prev_pos[i].vec_sub(c_vel);
        prev_pos[i] = bounds->apply_bounds(prev_pos[i]);
    }

    box->set_prev_pos(prev_pos);
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
