//
// Created by Alia Lescoulie on 5/6/22.
//

#ifndef MD_LAB_ATOM_H
#define MD_LAB_ATOM_H

#include <string>
#include "vec3.h"

class Atom {
public:
    Atom(std::string id, Vec3* pos, Vec3* vel, double mass);
    void set_pos(Vec3 *n_pos);
    void set_vel(Vec3 *n_vel);
    Vec3 get_pos();
    double get_mass();
    std::string id;
private:
    Vec3* pos = nullptr;
    Vec3* vel = nullptr;
    double mass;
};

#endif //MD_LAB_ATOM_H
