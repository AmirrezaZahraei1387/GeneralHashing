cmake_minimum_required(VERSION 3.23)
project(GeneralHashing)

set(CMAKE_CXX_STANDARD 23)

add_executable(GeneralHashing SimSepChainer/SimSepChainer.hpp SimSepChainer/SimSepChainer.inl SimSepChainer/SimSepChainerMem.inl SimSepChainer/test/testSimSepChainer.cpp SimProber/SimProber.hpp SimProber/SimProber.inl)
