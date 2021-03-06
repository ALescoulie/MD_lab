//
// Created by Alia Lescoulie on 5/16/22.
//
#include "Atom.h"
#include "Boundary.h"

#include "CubicBox.h"


CubicBox::CubicBox(double size) {
    this->size = size;
    atoms = std::vector<Atom>();
}

void CubicBox::add_atom(Atom atom) {
    atoms.push_back(atom);
    n_atoms++;
}

void CubicBox::update_pos(Vec3* new_pos) {
    if (prev_pos != nullptr) {
        free(prev_pos);
    }

    prev_pos = positions;
    positions = new_pos;
}

int CubicBox::get_n_atoms() {
    return n_atoms;
}

Atom CubicBox::get_atom(int ind) {
    return atoms[ind];
}

void CubicBox::update_vel(Vec3* new_vel) {
    if (velocities != nullptr) {
        free(velocities);
    }
    velocities = new_vel;
}

Vec3 CubicBox::get_pos(int ind) {
    return Vec3(positions[ind].x, positions[ind].y, positions[ind].z);
}

Vec3 CubicBox::get_prev_pos(int ind) {
    return Vec3(prev_pos[ind].x, prev_pos[ind].y, prev_pos[ind].z);
}

Vec3 CubicBox::get_vel(int ind) {
    return Vec3(velocities[ind].x, velocities[ind].y, velocities[ind].z);
}

Vec3 CubicBox::get_mom(int ind) {
    auto mom = Vec3(velocities[ind].x, velocities[ind].y, velocities[ind].z);
    mom.vec_scale(atoms[ind].get_mass());
    return mom;
}

void CubicBox::set_prev_pos(Vec3 *n_prev_pos) {
    prev_pos = n_prev_pos;
}

double CubicBox::get_size() {
    return size;
}

CubicBox::~CubicBox() {
    if (positions != nullptr) {
        free(positions);
    }

    if (prev_pos != nullptr) {
        free(prev_pos);
    }

    if (velocities != nullptr) {
        free(velocities);
    }

    atoms.clear();
}
