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
    hashTable_p.clear();
    size_p = 0;
}

template<typename HashObj>
bool SimSepChainer<HashObj>::isEmpty() {
    return hashTable_p.empty();
}

template<typename HashObj>
bool SimSepChainer<HashObj>::contain(const HashObj &ho) {
    auto& whichList = hashTable_p[hashFunc_p(ho, size_p)];
    return std::find(std::begin(whichList), std::end(whichList), ho) != std::end(whichList);
}

template<typename HashObj>
bool SimSepChainer<HashObj>::remove(const HashObj &ho) {
    auto& whichList = hashTable_p[hashFunc_p(ho, size_p)];
    auto itr = std::find(std::begin(whichList). std::end(whichList), ho);

    if(itr== std::end(whichList))
        return false;

    whichList.erase(itr);
    --size_p;
    return true;
}

template<typename HashObj>
bool SimSepChainer<HashObj>::insert(const HashObj &ho) {
    const size_t index{hashFunc_p(ho, size_p)};

    if(index >= size_p){
        hashTable_p.push_back(std::list<HashObj>{ho});
        ++size_p;
        return true;
    }else{
        auto& whichList = hashTable_p[index];
        if(std::find(std::begin(whichList), std::end(whichList), ho) == std::end(whichList))
            return false;
        else{
            whichList.push_back(ho);
            ++size_p;
            return true;
        }
    }
}

template<typename HashObj>
bool SimSepChainer<HashObj>::insert(HashObj &&ho) {
    const size_t index{hashFunc_p(ho, size_p)};

    if(index >= size_p){
        hashTable_p.push_back(std::list<HashObj>{std::move(ho)});
        ++size_p;
        return true;
    }else{
        auto& whichList = hashTable_p[index];
        if(std::find(std::begin(whichList), std::end(whichList), ho) == std::end(whichList))
            return false;
        else{
            whichList.push_back(std::move(ho));
            ++size_p;
            return true;
        }
    }
}

template<typename HashObj>
size_t SimSepChainer<HashObj>::getSize() {
    return size_p;
}

#endif //GENERALHASHING_SIMSEPCHAINER_INL
