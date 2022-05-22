//
// Created by Alia Lescoulie on 5/6/22.
//

#include "Simulation.h"

Simulation:: Simulation(std::string topology, chemfiles::Trajectory* trajectory,
                        ForceField *forces, Thermostat* thermo, double temp,
                       double size, double ts, double time, int st_frame) {
    this->top = topology;
    this->trj = trajectory;
    this->field = forces;
    this->size = size;
    this->time = time;
    this->therm = thermo;
    this->frame_step = st_frame;
    this->dt = ts;
}

void Simulation::run() {
    // Initializing box
    auto topol = Reader(top, size);
    box = topol.get_box();
    field->add_box(box);

    // Setting initial conditions
    therm->randomize_velocities(box);

    // Running simulation
    int step_count = 0;
    //auto trj_writer = Writer(this->trj, box);
    int n_frames = (int)(time/dt);

    for (int i = 0; i < n_frames; i++) {
        field->run_forces();
        if (step_count == frame_step) {
            write_frame(box);
            step_count = -1;
        }
        step_count++;
    }
    delete box;
    trj->close();
}

void Simulation::write_frame(CubicBox *box) {
    auto frame = chemfiles::Frame(chemfiles::UnitCell({size, size, size}));

    for (int i = 0; i < box->get_n_atoms(); i++) {
        auto pos = box->get_pos(i);
        frame.add_atom(chemfiles::Atom(box->get_atom(i).id), {pos.x, pos.y, pos.z});
    }

    trj->write(frame);
}
