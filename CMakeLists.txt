cmake_minimum_required(VERSION 3.0)
project(llvmSSAExplores)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-emit-llvm -S -c")


configure_file(main.cpp main.cpp COPYONLY)
add_custom_target(llvmByteCode ALL
        COMMAND bash -c "clang++ -O0 -emit-llvm -c main.cpp -o main.bc"
        SOURCES main.cpp
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

add_custom_target(llvmSSA ALL
        COMMAND bash -c "opt -mem2reg main.bc -o ssa.bc"
        DEPENDS llvmByteCode
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

add_custom_target(llvmDOT ALL
        COMMAND bash -c "opt -dot-cfg-only ssa.bc >/dev/null"
        DEPENDS llvmSSA
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

add_custom_target(llvmCFG ALL
        COMMAND bash -c "dot -Tpng -o ssa.png cfg.main.dot"
        DEPENDS llvmDOT
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

