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
    Vec3* positions = nullptr;
    Vec3* prev_pos = nullptr;
    Vec3* velocities = nullptr;
    Boundary bounds;
    double size;
public:
    CubicBox(double size, Boundary bounds);
    void add_atom(Atom atom);
    void update_pos(Vec3* new_pos);
    void update_vel(Vec3* new_vel);
    void set_prev_pos(Vec3* n_prev_pos);
    int get_n_atoms();
    Vec3 get_pos(int ind);
    Vec3 get_prev_pos(int ind);
    Vec3 get_vel(int ind);
    Vec3 get_mom(int ind);
    Atom get_atom(int ind);
};

#endif //MD_LAB_CUBICBOX_H
