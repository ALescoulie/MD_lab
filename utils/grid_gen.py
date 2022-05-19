#!/bin/python
"""
This script generates a xzy file of atoms in a grid

Arguments
-1 Name of atom
-2 Size of grid in nm
-3 Atoms per edge
-4 filename of output
"""
import sys

if __name__ == "__main__":
    atom = sys.argv[1]
    size = float(sys.argv[2])
    n_atoms = int(sys.argv[3])
    fname = sys.argv[4]

    dist = 10*size/n_atoms

    with open(fname, "w") as f:
        f.write(f"{n_atoms**3}\n\n")
        for i in range(n_atoms):
            for j in range(n_atoms):
                for k in range(n_atoms):
                    f.write(f"{atom}    {dist*i}   {dist*j} {dist*k}\n")

        f.write("\nunits angstrom")
