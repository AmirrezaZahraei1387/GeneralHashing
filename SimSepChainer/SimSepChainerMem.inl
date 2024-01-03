//
// Created by KAVOSH on 1/1/2024.
//
#ifndef GENERALHASHING_SIMSEPCHAINERMEM_INL
#define GENERALHASHING_SIMSEPCHAINERMEM_INL
#include "SimSepChainer.hpp"
#include <memory>

template<typename HashObj>
SimSepChainer<HashObj>::SimSepChainer(HashFunction hashFunc, size_t capacity):
capacity_p(capacity),
hashFunc_p(hashFunc),
hashTable_p(capacity)
{}

#endif //GENERALHASHING_SIMSEPCHAINERMEM_INL
