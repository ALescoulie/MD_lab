//
// Created by Alia Lescoulie on 5/14/22.
//

#ifndef MD_LAB_BOUNDARY_H
#define MD_LAB_BOUNDARY_H


#include "vec3.h"

class Boundary {
private:
    double size;
public:
    Boundary(double size);

    Boundary();

    Vec3 apply_bounds(Vec3 calc_pos);
};


#endif //MD_LAB_BOUNDARY_H
