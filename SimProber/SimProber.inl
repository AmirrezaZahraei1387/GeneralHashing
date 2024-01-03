//
// Created by KAVOSH on 1/2/2024.
//

#ifndef GENERALHASHING_SIMPROBER_INL
#define GENERALHASHING_SIMPROBER_INL
#include "SimProber.hpp"

template<typename HashObj>
bool SimProber<HashObj>::isActive(size_t index) {
    return hashTable_p[index] == ACTIVE;
}

template<typename HashObj>
SimProber<HashObj>::SimProber(SimProber::HashFunction hashFunc, size_t capacity)
:hashFunc_p(hashFunc),capacity_p(capacity), hashTable_p(capacity)
{}

template<typename HashObj>
size_t SimProber<HashObj>::findPos(const HashObj &element) {
    size_t offset{1};
    size_t currentPos{hashFunc_p(element, capacity_p)};

    while(hashTable_p[currentPos].status != EMPTY
    &&
    hashTable_p[currentPos].element != element){
        currentPos += offset;
        offset += 2;
        if(currentPos >= capacity_p){
            currentPos -= capacity_p;
        }
    }

    return currentPos;
}

template<typename HashObj>
bool SimProber<HashObj>::contain(HashObj &element) {
    size_t index{findPos(element)};
    return isActive(index);
}

template<typename HashObj>
bool SimProber<HashObj>::insert(HashObj &element) {
    size_t index{findPos(element)};
    if(isActive(index)){
        return false;
    }

    hashTable_p[index].element = element;
    hashTable_p[index].status = ACTIVE;

    if(++size_p > capacity_p/2){
        rehash();
    }
    return true;
}

template<typename HashObj>
bool SimProber<HashObj>::insert(HashObj &&element) {
    size_t index{findPos(element)};
    if(isActive(index)){
        return false;
    }

    hashTable_p[index].element = std::move(element);
    hashTable_p[index].status = ACTIVE;

    if(++size_p > capacity_p/2){
        rehash();
    }
    return true;
}

template<typename HashObj>
bool SimProber<HashObj>::remove(HashObj &element) {
    size_t index{findPos(element)};

    if(!isActive(index)){
        return false;
    }

    hashTable_p[index].status = DELETED;
    --size_p;
    return true;
}

template<typename HashObj>
size_t SimProber<HashObj>::getSize() {
    return size_p;
}

template<typename HashObj>
void SimProber<HashObj>::makeEmpty() {
    for(auto& x: hashTable_p){
        x.status = EMPTY;
    }
}

template<typename HashObj>
void SimProber<HashObj>::rehash() {
    std::vector<HashObj> oldHashTable = hashTable_p;
    hashTable_p.resize(nextPrime(2*capacity_p));

    for(auto& x: hashTable_p){
        x.status = DELETED;
    }

    size_p = 0;
    capacity_p = hashTable_p.size();
    for(auto& x: oldHashTable){
        if(x.status == ACTIVE)
            insert(std::move(x.element));
    }
}

#endif //GENERALHASHING_SIMPROBER_INL
