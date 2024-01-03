//
// Created by KAVOSH on 1/1/2024.
//
#ifndef GENERALHASHING_SIMSEPCHAINER_INL
#define GENERALHASHING_SIMSEPCHAINER_INL
#include <algorithm>
#include <list>
#include <cstddef>
#include "SimSepChainer.hpp"

template<typename HashObj>
void SimSepChainer<HashObj>::makeEmpty() {
    for(auto& theList: hashTable_p){
        theList.clear();
    }
    size_p = 0;
}


template<typename HashObj>
bool SimSepChainer<HashObj>::contain(const HashObj &ho) {
    size_t index{hashFunc_p(ho, size_p)};
    if(!boundOk(index)){
        return false;
    }
    auto& whichList = hashTable_p[index];
    return std::find(std::begin(whichList), std::end(whichList), ho) != std::end(whichList);
}

template<typename HashObj>
bool SimSepChainer<HashObj>::remove(const HashObj &ho) {

    size_t index{hashFunc_p(ho, size_p)};
    if(!boundOk(index)){
        return false;
    }
    auto& whichList = hashTable_p[index];
    auto itr = std::find(std::begin(whichList), std::end(whichList), ho);

    if(itr== std::end(whichList))
        return false;

    whichList.erase(itr);
    --size_p;
    return true;
}

template<typename HashObj>
bool SimSepChainer<HashObj>::insert(const HashObj &ho) {

    size_t index{hashFunc_p(ho, size_p)};
    if(!boundOk(index)){
        return false;
    }

    auto& whichList = hashTable_p[index];
    if(std::find(std::begin(whichList), std::end(whichList), ho) == std::end(whichList)){
        whichList.push_back(ho);
        ++size_p;
        return true;
    }
    return false;
}

template<typename HashObj>
bool SimSepChainer<HashObj>::insert(HashObj &&ho) {

    size_t index{hashFunc_p(ho, size_p)};
    if(!boundOk(index)){
        return false;
    }

    auto& whichList = hashTable_p[index];
    if(std::find(std::begin(whichList), std::end(whichList), ho) == std::end(whichList)){
        whichList.push_back(std::move(ho));
        ++size_p;
        return true;
    }
    return false;
}

template<typename HashObj>
size_t SimSepChainer<HashObj>::getSize() {
    return size_p;
}

template<typename HashObj>
bool SimSepChainer<HashObj>::boundOk(size_t hash) {
    return (hash < capacity_p);
}

#endif //GENERALHASHING_SIMSEPCHAINER_INL
