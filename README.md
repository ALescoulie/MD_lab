# MD_lab
### Alia Lescoulie

A Molecular Dynamics Lenard-Jones model build in C++.

## Building

```bash
git clone git@github.com:ALescoulie/MD_lab.git

cmake build .

make
```

## Scripts

There are two python helper scripts in the `utils` directory to help setting up simulations. `grid_gen.py` writes an xyz file of a cubic lattice of the specified molecule and `input_gen.py` make a blank input file.

### `grid_gen.py`

The arguments for `grid_gen.py` are in order:

1. The name of the specified atoms
2. The length in nm of the grid
3. The number of atoms per cell in the grid
4. The name of the output file, this should end in `.xyz`

Usage:

```bash
python utils/grid_gen.py Kr 10 10 grid.xyz
```

### `input_gen.py`

The arguments for `input_gen.py` are in order:

1. The file name ending with `.yaml`

```bash
python utils/input_gen.py input.yaml
```

# Running

This simulation only runs dispersion interactions for particles. To use generate a topology file. This can be done with `grid_gen.py` if you want a cubic lattice of a single atom.

To generate the input file use `input_gen.py` to make a blank input than fill out the specified fields. Then that file is passed to the `MD_lab` executable as an argument as shown below. At the moment the only tunable parameters are temperature, time step, simulation time, and time steps per frame.

```bash
./MD_lab input.yaml
```

Afterwards the trajectory will be returned to the specified file.
