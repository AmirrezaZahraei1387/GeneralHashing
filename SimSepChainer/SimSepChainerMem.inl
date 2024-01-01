//
// Created by KAVOSH on 1/1/2024.
//
#ifndef GENERALHASHING_SIMSEPCHAINERMEM_INL
#define GENERALHASHING_SIMSEPCHAINERMEM_INL
#include "SimSepChainer.hpp"

template<typename HashObj>
SimSepChainer<HashObj>::SimSepChainer(HashFunction &hashFunc): hashTable_p()
{
    hashFunc_p = hashFunc;
}

template<typename HashObj>
SimSepChainer<HashObj>::SimSepChainer(const SimSepChainer<HashObj> &ht) {
    *this = ht;
}

template<typename HashObj>
SimSepChainer<HashObj>::SimSepChainer(SimSepChainer<HashObj> &&ht) noexcept{
    *this = ht;
}

template<typename HashObj>
SimSepChainer<HashObj> &SimSepChainer<HashObj>::operator=(const SimSepChainer<HashObj> &ht) {
    if(ht != *this){
        hashTable_p = ht.hashTable_p;
        size_p = ht.size_p;
        hashFunc_p = ht.hashFunc_p;
    }
    return *this;
}


template<typename HashObj>
SimSepChainer<HashObj> &SimSepChainer<HashObj>::operator=(SimSepChainer<HashObj> &&ht) noexcept{
    hashTable_p = std::move(ht.hashTable_p);
    size_p = ht.size_p;
    hashFunc_p = std::move(ht.hashFunc_p);

    ht.size_p = 0;
    return *this;
}
#endif //GENERALHASHING_SIMSEPCHAINERMEM_INL
