//
// Created by Alia Lescoulie on 5/14/22.
//

#include "Boundary.h"

#include <cmath>

Boundary::Boundary(double size) {
    this->size = size;
}

Vec3 Boundary::apply_bounds(Vec3 calc_pos) {
    calc_pos.x -= (size * round(calc_pos.x/size));
    calc_pos.y -= (size * round(calc_pos.y/size));
    calc_pos.z -= (size * round(calc_pos.z/size));
    return calc_pos;
}
