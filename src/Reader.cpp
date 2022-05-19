//
// Created by Alia Lescoulie on 5/17/22.
//

#include "Reader.h"

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

    for (size_t i = 0; i < topology.size(); i++) {

        box->add_atom(Atom(topology[i].name(),
                      positions[i][0],
                      positions[i][1],
                      positions[i][2],
                      topology[i].mass()));
    }
}

CubicBox* Reader::get_box() {
    return box;
}
