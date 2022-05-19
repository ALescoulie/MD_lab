//
// Created by Alia Lescoulie on 5/14/22.
//

#ifndef MD_LAB_INPUTPARSER_H
#define MD_LAB_INPUTPARSER_H

#include <string>
#include <map>

#include "yaml-cpp/node/node.h"

#include "Simulation.h"

class InputParser {
public:
    InputParser(char* fname);
    Simulation* init_sim();
private:
    std::string top;
    std::string trj;
    std::string forces;
    std::string thermo;
    std::string bounds;
    double size;
    double dt;
    double time;
    double temp;
    int freq;
};

#endif //MD_LAB_INPUTPARSER_H
