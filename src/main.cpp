#include "InputParser.h"
#include "Simulation.h"

#include <iostream>

int main(int argc, char** argv) {
    std::cout << "Starting MD_lab\n" << std::endl;
    if (argc < 2) {
        std::cout << "Error: failed to provide input file\n" << std::endl;
        return 1;
    }
    std::cout << "Parsing input file\n" << std::endl;
    InputParser parser = InputParser(argv[1]);
    Simulation* sim = parser.init_sim();
    std::cout << "Running simulation\n" << std::endl;
    sim->run();
    std::cout << "MD_lab reminds you\n"
                 "Biology, I am an organism, I'm chemical, That's all, That is all.\n"
                 "-Mitski" << std::endl;
    return 0;
}
