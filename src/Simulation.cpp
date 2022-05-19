//
// Created by Alia Lescoulie on 5/6/22.
//

#include "Simulation.h"

Simulation:: Simulation(std::string topology, std::string trajectory,
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
    Thermostat::radomize_velocities(box);

    // Running simulation
    int step_count = 0;
    //auto trj_writer = Writer(this->trj, box);
    int n_frames = (int)(time/dt);

    for (int i = 0; i < n_frames; i++) {
        field->update_forces();
        if (step_count == frame_step) {
            //trj_writer.write_frame(); Not yet implemented
            step_count = -1;
        }
        step_count++;
    }
}
