//
// Created by Alia Lescoulie on 5/6/22.
//

#ifndef MD_LAB_ATOM_H
#define MD_LAB_ATOM_H

#include <string>
#include "vec3.h"

class Atom {
public:
    Atom(std::string id, double x, double y, double z, double mass);
    void set_pos(Vec3 n_pos);
    void set_mom(Vec3 n_mom);
    Vec3 get_pos();
    Vec3 get_mom();
    Vec3 get_vel();
    double get_mass();
private:
    std::string id;
    Vec3 pos = Vec3(0, 0, 0);
    Vec3 momentum = Vec3(0, 0, 0);
    double mass;
};


#endif //MD_LAB_ATOM_H
