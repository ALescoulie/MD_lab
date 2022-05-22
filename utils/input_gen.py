#!bin/python
"""
Generates an input file for MD_lab
Arguments
-1  Name of the Input file
"""

import sys

yaml = [
    'topology:',
    'output:',
    '# Do not change, these are the only options in this version',
    'force_field: "lj"',
    'boundary: "periodic"',
    'thermostat: "random"',
    '# Time units in fs, distance units in nm, temp units in K',
    'box_size:',
    'temp:',
    'timestep:',
    'time:',
    'record_freq:'
]

if __name__ == '__main__':
    fname = sys.argv[1]

    with open(fname, "w") as fp:
        for line in yaml:
            fp.write(f"{line}\n")
