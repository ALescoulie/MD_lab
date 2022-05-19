//
// Created by Alia Lescoulie on 5/6/22.
//
#include "Atom.h"
#include "vec3.h"

#include <string>

Atom::Atom(std::string id, double x, double y, double z, double mass) {
    this->id = id;
    this->pos = Vec3(x, y, z);
    this->mass = mass; // temp value
}

void Atom::set_pos(Vec3 n_pos) {
    pos = n_pos;
}

void Atom::set_mom(Vec3 n_mom) {
    momentum = n_mom;
}

Vec3 Atom::get_pos() {
    return pos;
}

Vec3 Atom::get_mom() {
    return momentum;
}

double Atom::get_mass() {
    return mass;
}

Vec3 Atom::get_vel() {
    Vec3 vel = Vec3(momentum.x, momentum.y, momentum.z);
    vel.vec_scale(1/mass);
    return vel;
}
