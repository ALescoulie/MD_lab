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
    chemfiles::Trajectory file(fname);
    auto topology = chemfiles::Topology();
    chemfiles::Frame frame = file.read();
    file.set_topology(topology);
    auto positions = frame.positions();
    Vec3* pos = (Vec3*)malloc(sizeof(Vec3) * topology.size());
    for (size_t i = 0; i < topology.size(); i++) {
        pos[i].x = positions[i][0];
        pos[i].y = positions[i][1];
        pos[i].z = positions[i][2];
        box->add_atom(Atom(topology[i].name(), &pos[i], nullptr,
                      topology[i].mass()));
    }
    box->update_pos(pos);
}

CubicBox* Reader::get_box() {
    return box;
}
