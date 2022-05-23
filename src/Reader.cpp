//
// Created by Alia Lescoulie on 5/17/22.
//

#include "vec3.h"

#include "Reader.h"

#include <vector>

Reader::Reader(std::string fname, double size) {
    this->fname = fname;
    this->box = new CubicBox(size);
    construct_box();
}

void Reader::construct_box() {
    auto trajectory = chemfiles::Trajectory(fname);
    trajectory.set_topology(fname);

    auto frame = trajectory.read();

    auto positions = frame.positions();
    Vec3* pos = (Vec3*)malloc(sizeof(Vec3) * frame.size());
    for (size_t i = 0; i < frame.size(); i++) {
        pos[i].x = positions[i][0];
        pos[i].y = positions[i][1];
        pos[i].z = positions[i][2];
        box->add_atom(Atom(frame[i].name(), &pos[i], nullptr,
                      frame[i].mass()));
    }
    box->update_pos(pos);
    trajectory.close();
}

CubicBox* Reader::get_box() {
    return box;
}
