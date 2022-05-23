//
// Created by Alia Lescoulie on 5/14/22.
//

#include <string>

#include "InputParser.h"
#include "ForceField.h"
#include "Simulation.h"
#include "Boundary.h"
#include "Thermostat.h"

#include "yaml-cpp/yaml.h"

InputParser::InputParser(std::string fname) {

    YAML::Node config = YAML::LoadFile(fname);

    if (config["topology"]) {
        top = config["topology"].as<std::string>();
    } else {
        throw "missing topology in input file";
    }

    if (config["output"]) {
        trj = config["output"].as<std::string>();
    } else {
        throw "missing output in input file";
    }

    if (config["force_field"]) {
        forces = config["force_field"].as<std::string>();
    } else {
        throw "missing force field in input file";
    }

    if (config["boundary"]) {
        bounds = config["boundary"].as<std::string>();
    } else {
        throw "missing boundary in input file";
    }

    if (config["thermostat"]) {
        thermo = config["thermostat"].as<std::string>();
    } else {
        throw "missing thermostat in input file";
    }

    if (config["box_size"]) {
        size = config["box_size"].as<double>();
    } else {
        throw "missing box in input file";
    }

    if (config["timestep"]) {
        dt = config["timestep"].as<double>();
    } else {
        throw "missing timestep in input file";
    }

    if (config["time"]) {
        time = config["time"].as<double>();
    } else {
        throw "missing time in input file";
    }

    if (config["record_freq"]) {
        freq = config["record_freq"].as<int>();
    } else {
        throw "missing record_freq in input file";
    }

    if (config["temp"]) {
        temp = config["temp"].as<double>();
    } else {
        throw "missing record_freq in input file";
    }
}

Simulation* InputParser::init_sim() {
    ForceField* f;
    Thermostat* t;
    auto periodic = new Boundary(size);

    if (forces == "lj") {
        f = new ForceField(dt, periodic);
    }

    if (thermo == "random") {
        t = new Thermostat(temp, dt, periodic);
    }
    auto trj_file = new chemfiles::Trajectory(trj, 'w');
    auto sim = new Simulation(top, trj_file, f, t, temp,
                              size, dt, time, freq);
    return sim;
}
