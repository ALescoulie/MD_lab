//
// Created by Alia Lescoulie on 5/6/22.
//
#include "Atom.h"
#include "vec3.h"

#include <string>

Atom::Atom(std::string id, Vec3* pos, Vec3* vel, double mass) {
    this->id = id;
    this->pos = pos;
    this->vel = vel;
    this->mass = mass; // temp value
}

void Atom::set_pos(Vec3* n_pos) {
    pos->x = n_pos->x;
    pos->y = n_pos->y;
    pos->z = n_pos->z;
}

void Atom::set_vel(Vec3* n_vel) {
    vel->x = n_vel->x;
    vel->y = n_vel->y;
    vel->z = n_vel->z;
}

Vec3 Atom::get_pos() {
    Vec3 tmp = Vec3(pos->x, pos->y, pos->z);
    return tmp;
}

Vec3 Atom::get_mom() {
    Vec3 tmp = Vec3(vel->x, vel->y, vel->z);
    tmp.vec_scale(mass);
    return tmp;
}

double Atom::get_mass() {
    return mass;
}

Vec3 Atom::get_vel() {
    Vec3 tmp = Vec3(vel->x, vel->y, vel->z);
    return tmp;
}
