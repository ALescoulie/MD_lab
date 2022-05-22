//
// Created by Alia Lescoulie on 5/14/22.
//

#include "ForceField.h"
#include "CubicBox.h"
#include "Atom.h"
#include "Boundary.h"

#include <vector>

ForceField::ForceField(double dt, Boundary* bounds) {
    this->dt = dt;
    this->bounds = bounds;
    init_id_table();
}

void ForceField::add_box(CubicBox *box) {
    this->box = box;
}

double** ForceField::calc_dists() {
    if (box != nullptr) {
        auto dists = static_cast<double **>(malloc(sizeof(double) *
                box->get_n_atoms() * box->get_n_atoms()));

        for (int i = 0; i < box->get_n_atoms(); i++) {
            for (int j = 0; j < box->get_n_atoms(); j++) {
                if (i <= j) {
                    dists[i][j] = 0;
                } else {
                    dists[i][j] = box->get_atom(i).get_pos().vec_dist(
                            box->get_atom(j).get_pos());
                }
            }
        }

        return dists;
    } else {
        throw "No box provided for force field";
    }
}

void ForceField::run_forces() {
    auto dists = calc_dists();
    auto force = static_cast<double **>(malloc(sizeof(double) *
            box->get_n_atoms() * box->get_n_atoms()));

    // Calculating forces on each particle
    for (int i = 0; i < box->get_n_atoms(); i++) {
        for (int j = 0; j < box->get_n_atoms(); j++) {
            if (dists[i][j] >= cutoff) {
                double e = eps_ij(id_table[box->get_atom(i).id],
                                  id_table[box->get_atom(j).id]);
                double s = sig_ij(id_table[box->get_atom(i).id],
                                  id_table[box->get_atom(j).id]);
                force[i][j] = lj_pot(dists[i][j], s, e);
            } else {
                force[i][j] = 0;
            }
        }
    }

    // Computing net force on each particle
    auto forces = std::vector<Vec3>(box->get_n_atoms());
    for (int i = 0; i < box->get_n_atoms(); i++) {
        forces[i].vec_scale(0);

        for (int j = 0; i < box->get_n_atoms(); i++) {
            auto tmp = box->get_atom(i).get_pos();
            tmp.vec_sub(box->get_atom(j).get_pos());
            tmp.norm();
            tmp.vec_scale(force[i][j]);
            forces[i].vec_add(tmp);
        }
    }

    // Updating positions
    Vec3* n_pos = static_cast<Vec3*>(malloc(sizeof(Vec3) *
            box->get_n_atoms()));
    Vec3* n_vel = static_cast<Vec3*>(malloc(sizeof(Vec3) *
                                            box->get_n_atoms()));
    double dtsq = dt*dt;
    for (int i = 0; i < box->get_n_atoms(); i++) {
        n_pos[i].vec_scale(0);
        n_pos[i].vec_add(box->get_pos(i));
        n_pos[i].vec_scale(2);
        n_pos[i].vec_sub(box->get_prev_pos(i));
        auto f_term = Vec3(forces[i].x, forces[i].y, forces[i].z);
        f_term.vec_scale(dtsq/box->get_atom(i).get_mass());
        n_pos[i].vec_add(f_term);
        n_pos[i] = bounds->apply_bounds(n_pos[i]);
        n_vel[i].vec_scale(0);
        n_vel[i].vec_add(n_pos[i]);
        n_vel[i].vec_sub(box->get_prev_pos(i));
        n_vel[i].vec_scale(1/(2*dt));
    }
    box->update_pos(n_pos);
    box->update_vel(n_vel);

    free(dists);
    free(force);
}

double ForceField::eps_ij(int i, int j) {
    return sqrt(lj_epsilon[i] * lj_epsilon[j]);
}

double ForceField::sig_ij(int i, int j) {
    return (lj_sig[i] * lj_sig[j])/2;
}

std::map<std::string, int> ForceField::init_id_table() {
    id_table = std::map<std::string, int>();
    id_table["H"] = 1;
    id_table["He"] = 2;
    id_table["Li"] = 3;
    id_table["Be"] = 4;
    id_table["B"] = 5;
    id_table["C"] = 6;
    id_table["N"] = 7;
    id_table["O"] = 8;
    id_table["F"] = 9;
    id_table["Ne"] = 10;
    id_table["Na"] = 11;
    id_table["Mg"] = 12;
    id_table["Al"] = 13;
    id_table["Si"] = 14;
    id_table["P"] = 15;
    id_table["S"] = 16;
    id_table["Cl"] = 17;
    id_table["Ar"] = 18;
    id_table["K"] = 19;
    id_table["Ca"] = 20;
    id_table["Sc"] = 21;
    id_table["Ti"] = 22;
    id_table["V"] = 23;
    id_table["Cr"] = 24;
    id_table["Mn"] = 25;
    id_table["Fe"] = 26;
    id_table["Co"] = 27;
    id_table["Ni"] = 28;
    id_table["Cu"] = 29;
    id_table["Zn"] = 30;
    id_table["Ga"] = 31;
    id_table["Ge"] = 32;
    id_table["As"] = 32;
    id_table["Se"] = 33;
    id_table["Br"] = 34;
    id_table["Kr"] = 35;
    return id_table;
}

double ForceField::lj_pot(double r, double s, double e) {
    double f = (-48 * e * pow(s, 12))/(pow(r, 14)) -
            (24 * e * pow(s, 6))/(pow(r,8));
    return f;
}
