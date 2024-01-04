//
// Created by KAVOSH on 1/4/2024.
//
#ifndef GENERALHASHING_CUCKOOHASHRCORE_INL
#define GENERALHASHING_CUCKOOHASHRCORE_INL
#include "CuckooHashR.hpp"
#include <memory>

template<typename AnyT, typename HashFuncs>
void CuckooHashR<AnyT, HashFuncs>::expand() {
    rehash(static_cast<int>(CuckooTable.size()/LOAD_FACTER));
}

template<typename AnyT, typename HashFuncs>
void CuckooHashR<AnyT, HashFuncs>::rehash() {
    hashFuncs.generateNewFuncs();
    rehash(CuckooTable.size());
}

template<typename AnyT, typename HashFuncs>
void CuckooHashR<AnyT, HashFuncs>::rehash(int newSize) {
    std::vector<CuckooNode> oldCuckooTable = CuckooTable;
    CuckooTable.resize(newSize);

    //resetting the table
    for(auto& x: CuckooTable){
        x.isActive = false;
    }

    for(auto& x: oldCuckooTable){
        if(x.isActive)
            insert(std::move(x.element));
    }
}

template<typename AnyT, typename HashFuncs>
int CuckooHashR<AnyT, HashFuncs>::findPos(const AnyT &element) {
    for(int i{0}; i<hashFuncN; ++i){
        int pos{getHashFuc(element, i)};

        if(CuckooTable.at(pos).isActive && CuckooTable.at(pos).element == element)
            return pos;
    }
    return -1;
}

template<typename AnyT, typename HashFuncs>
size_t CuckooHashR<AnyT, HashFuncs>::getHashFuc(const AnyT &element, int which) {
    return hashFuncs.hash(element, CuckooTable.size(), which) % CuckooTable.size();
}


#endif //GENERALHASHING_CUCKOOHASHRCORE_INL
