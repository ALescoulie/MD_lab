//
// Created by Alia Lescoulie on 5/16/22.
//

#ifndef MD_LAB_CUBICBOX_H
#define MD_LAB_CUBICBOX_H

#include "Atom.h"
#include "vec3.h"
#include "Boundary.h"

#include <vector>


class CubicBox {
private:
    int n_atoms;
    std::vector<Atom> atoms;
    Boundary bounds;
    double size;
public:
    CubicBox(double size);
    void add_atom(Atom atom);
    void update_pos(int mol_ind, Vec3 new_pos);
    void update_vel(int mol_ind, Vec3 new_vel);
    int get_n_atoms();
    Atom get_atom(int ind);
};

#endif //MD_LAB_CUBICBOX_H
