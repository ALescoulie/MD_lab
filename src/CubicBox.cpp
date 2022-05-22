//
// Created by Alia Lescoulie on 5/16/22.
//

#include "CubicBox.h"
#include "Atom.h"

CubicBox::CubicBox(double size, Boundary bounds) {
    this->size = size;
    atoms = std::vector<Atom>();
    this->bounds = bounds;
}

void CubicBox::add_atom(Atom atom) {
    atoms.push_back(atom);
    n_atoms++;
}

void CubicBox::update_pos(Vec3* new_pos) {

}

int CubicBox::get_n_atoms() {
    return n_atoms;
}

Atom CubicBox::get_atom(int ind) {
    return atoms[ind];
}

void CubicBox::update_vel(Vec3* new_vel) {

}
