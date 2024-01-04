cmake_minimum_required(VERSION 3.23)
project(GeneralHashing)

set(CMAKE_CXX_STANDARD 23)

add_executable(GeneralHashing
        SimSepChainer/test/testSimSepChainer.cpp
        SimSepChainer/SimSepChainer.hpp
        SimSepChainer/SimSepChainer.inl
        SimSepChainer/SimSepChainerMem.inl

        SimProber/SimProber.hpp
        SimProber/SimProber.inl
        NextPrime.hpp NextPrime.cpp CuckooHashR/CuckooHashR.hpp CuckooHashR/CuckooHashRCore.inl CuckooHashR/CuckooHashRInter.inl)
