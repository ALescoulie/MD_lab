//
// Created by Alia Lescoulie on 5/17/22.
//

#ifndef MD_LAB_READER_H
#define MD_LAB_READER_H

#include "CubicBox.h"

#include "chemfiles.hpp"

#include <string>

class Reader {
private:
    std::string fname;
    CubicBox* box;
    void construct_box();
public:
    Reader(std::string fname, double size);
    CubicBox* get_box();
};

#endif //MD_LAB_READER_H
