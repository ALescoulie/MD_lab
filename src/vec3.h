#pragma once

class Vec3 {
public:
    double x;
    double y;
    double z;

    Vec3();
    Vec3(double x, double y, double z);

    void vec_add(Vec3 vec);

    void vec_sub(Vec3 vec);

    void vec_scale(double scale);

    double vec_dot(Vec3 vec);

    void vec_cross(Vec3 vec);

    double vec_dist(Vec3 vec);

    void norm();

};
