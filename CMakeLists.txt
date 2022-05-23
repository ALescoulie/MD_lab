cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 14)


project(MD_lab)

include(FetchContent)

FetchContent_Declare(yaml-cpp
        GIT_REPOSITORY "https://github.com/jbeder/yaml-cpp.git"
        GIT_TAG "420c98231094b1cd2e5de3a714c4e3ee9b4f1118"
        )

FetchContent_Declare(chemfiles
        GIT_REPOSITORY "https://github.com/chemfiles/chemfiles.git"
        GIT_TAG "600768a4d4ba155a07e8c422177ea1e8655b810b"
        )

FetchContent_Declare(eigen
        GIT_REPOSITORY "https://gitlab.com/libeigen/eigen.git"
        GIT_TAG "481a4a8c319640a3689be11c66b38cf1f9dc50b2"
        )

FetchContent_MakeAvailable(yaml-cpp)
FetchContent_MakeAvailable(chemfiles)
FetchContent_MakeAvailable(eigen)

add_executable(
        MD_lab
        src/main.cpp
        src/Simulation.cpp
        src/Simulation.h
        src/Atom.cpp
        src/Atom.h
        src/vec3.cpp
        src/vec3.h
        src/ForceField.cpp
        src/ForceField.h
        src/Boundary.cpp
        src/Boundary.h
        src/InputParser.cpp
        src/InputParser.h
        src/Thermostat.cpp
        src/Thermostat.h
        src/CubicBox.cpp
        src/CubicBox.h
        src/Reader.cpp
        src/Reader.h)

target_link_libraries(MD_lab yaml-cpp chemfiles eigen)
