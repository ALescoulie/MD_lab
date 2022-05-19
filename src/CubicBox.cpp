//
// Created by Alia Lescoulie on 5/16/22.
//

#include "CubicBox.h"
#include "Atom.h"

CubicBox::CubicBox(double size) {
    this->size = size;
    atoms = std::vector<Atom>();
    bounds = Boundary(size);
}

void CubicBox::add_atom(Atom atom) {
    atoms.push_back(atom);
    n_atoms++;
}

void CubicBox::update_pos(int mol_ind, Vec3 new_pos) {
    atoms[mol_ind].set_pos(bounds.apply_bounds(new_pos));
}

int CubicBox::get_n_atoms() {
    return n_atoms;
}

Atom CubicBox::get_atom(int ind) {
    return atoms[ind];
}

void CubicBox::update_vel(int mol_ind, Vec3 new_vel) {
    new_vel.vec_scale(atoms[mol_ind].get_mass());
    atoms[mol_ind].set_mom(new_vel);
}
