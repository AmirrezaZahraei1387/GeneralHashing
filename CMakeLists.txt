cmake_minimum_required(VERSION 3.23)
project(GeneralHashing)

set(CMAKE_CXX_STANDARD 23)

add_executable(GeneralHashing
        main.cpp
        NextPrime.hpp
        NextPrime.cpp
        CuckooHashR/CuckooHashR.hpp
        CuckooHashR/CuckooHashRCore.inl
        CuckooHashR/CuckooHashRInter.inl CuckooHashR/HashFuncions.hpp)
