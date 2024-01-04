//
// Created by KAVOSH on 1/4/2024.
//
#ifndef GENERALHASHING_CUCKOOHASHRINTER_INL
#define GENERALHASHING_CUCKOOHASHRINTER_INL
#include "CuckooHashR.hpp"

template<typename AnyT, typename HashFuncs>
void CuckooHashR<AnyT, HashFuncs>::makeEmpty() {
    currentSize = 0;
    for(auto& x: CuckooTable){
        x.isActive = false;
    }
}

template<typename AnyT, typename HashFuncs>
int CuckooHashR<AnyT, HashFuncs>::getSize() {
    return currentSize;
}

template<typename AnyT, typename HashFuncs>
bool CuckooHashR<AnyT, HashFuncs>::remove(const AnyT &element) {

    int pos{findPos(element)};

    if(!isActive(pos))
        return false;

    CuckooTable.at(pos).isActive = false;
    --currentSize;
    return true;
}


template<typename AnyT, typename HashFuncs>
bool CuckooHashR<AnyT, HashFuncs>::contain(const AnyT &element) {
    return isActive(findPos(element));
}

template<typename AnyT, typename HashFuncs>
bool CuckooHashR<AnyT, HashFuncs>::insert(AnyT &&element) {
    if(contain(element))
        return false;

    if(currentSize >= CuckooTable.size() * LOAD_FACTER)
        expand();

    return insertHelper(std::move(element));
}

template<typename AnyT, typename HashFuncs>
bool CuckooHashR<AnyT, HashFuncs>::insert(const AnyT &element) {
    if(contain(element))
        return false;

    if(currentSize >= CuckooTable.size() * LOAD_FACTER)
        expand();

    return insertHelper(element);
}


#endif //GENERALHASHING_CUCKOOHASHRINTER_INL
