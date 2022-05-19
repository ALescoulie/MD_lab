#include <cmath>

#include "vec3.h"

Vec3::Vec3(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Vec3::vec_add(Vec3 vec) {
    // Add vectors
    x += vec.x;
    y += vec.y;
    z += vec.z;
}

void Vec3::vec_sub(Vec3 vec) {
    /* Creates a new Vec3 vec3 = vec1 - vec2 */
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
}

void Vec3::vec_scale(double scale) {
    /* Creates a new Vec3 n_vec = vec * scalar */ 
    x *= scale;
    y *= scale;
    z *= scale;
}

double Vec3::vec_dot(Vec3 vec) {
    /* Computes dot production of two vectors Vectors */
    double dot = 0;
    dot += x * vec.x + vec.y * vec.y + vec.z * vec.z;
    
    return dot;
}

void Vec3::vec_cross(Vec3 vec) {
    /* Creates a new Vec3 vec3 = vec1 * vec2 */

    x = vec.x;
    y = vec.y;
    z = vec.z;
}

double Vec3::vec_dist(Vec3 vec) {
    vec_sub(vec);
    double d_sq = x*x + y*y + z*z;
    return sqrt(d_sq);
}

void Vec3::norm() {
    double r = 1/(sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

    x *= r;
    y *= r;
    z *= r;
}
