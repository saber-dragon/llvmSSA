cmake_minimum_required(VERSION 3.0)
project(llvmSSAExplores)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-emit-llvm -S -c")


configure_file(main.cpp main.cpp COPYONLY)
add_custom_target(llvmByteCode ALL
        COMMAND bash -c "clang++ -O0 -S -emit-llvm -c main.cpp -o main.ll"
        SOURCES main.cpp
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

add_custom_target(llvmSSA ALL
        COMMAND bash -c "opt -O0 -S -mem2reg main.ll -o ssa.ll"
        DEPENDS llvmByteCode
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

add_custom_target(llvmDOT ALL
        COMMAND bash -c "opt -O0 -dot-cfg-only ssa.ll >/dev/null"
        DEPENDS llvmSSA
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

add_custom_target(llvmCFG ALL
        COMMAND bash -c "dot -Tpng -o ssa.png cfg._Z3fooii.dot"
        DEPENDS llvmDOT
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

