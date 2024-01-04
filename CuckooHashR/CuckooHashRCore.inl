//
// Created by KAVOSH on 1/4/2024.
//
#ifndef GENERALHASHING_CUCKOOHASHRCORE_INL
#define GENERALHASHING_CUCKOOHASHRCORE_INL
#include "CuckooHashR.hpp"
#include <memory>
#include <utility>

template<typename AnyT, typename HashFuncs>
void CuckooHashR<AnyT, HashFuncs>::expand() {
    rehash(static_cast<int>(CuckooTable.size()/LOAD_FACTER));
}

// same table size but new hash functions to be generated
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

        if(isActive(pos) && CuckooTable.at(pos).element == element)
            return pos;
    }
    return -1;
}

template<typename AnyT, typename HashFuncs>
size_t CuckooHashR<AnyT, HashFuncs>::getHashFunc(const AnyT &element, int which) {
    return hashFuncs.hash(element, CuckooTable.size(), which) % CuckooTable.size();
}

template<typename AnyT, typename HashFuncs>
bool CuckooHashR<AnyT, HashFuncs>::insertHelper(const AnyT &element) {

    static constexpr int COUNTING_LIMIT{100};
    AnyT elementCopy{element};


    while(true){
        int pos;
        int last_pos{-1};

        for(int count{0}; count < COUNTING_LIMIT; ++count){

            // iterating through the hash functions
            for(int i{0}; i<hashFuncN; ++i){
                pos = getHashFunc(elementCopy, i);

                if(!isActive(pos)){
                    CuckooTable.at(pos) = std::move(CuckooNode{elementCopy, true});
                    ++currentSize;
                    return true;
                }
            }

            // no position which is free is found. Start for evicting a position randomly
        }
        int i{0};

        do{
            pos = getHashFunc(elementCopy, random());
        } while (pos == last_pos && i++ < 5);

        last_pos = pos;
        std::swap(elementCopy, CuckooTable.at(pos).element);
    }

    ++rehashesCount;

    if(rehashesCount > MAX_REHASHES){
        expand();
        rehashesCount = 0;
    }else{
        rehash();
    }
}


template<typename AnyT, typename HashFuncs>
bool CuckooHashR<AnyT, HashFuncs>::insertHelper(const AnyT &&element) {

    static constexpr int COUNTING_LIMIT{100};
    AnyT elementCopy{element};


    while(true){
        int pos;
        int last_pos{-1};

        for(int count{0}; count < COUNTING_LIMIT; ++count){

            // iterating through the hash functions
            for(int i{0}; i<hashFuncN; ++i){
                pos = getHashFunc(elementCopy, i);

                if(!isActive(pos)){
                    CuckooTable.at(pos) = std::move(CuckooNode{std::move(elementCopy), true});
                    ++currentSize;
                    return true;
                }
            }

            // no position which is free is found. Start for evicting a position randomly
        }
        int i{0};

        do{
            pos = getHashFunc(elementCopy, random());
        } while (pos == last_pos && i++ < 5);

        last_pos = pos;
        std::swap(elementCopy, CuckooTable.at(pos).element);
    }

    ++rehashesCount;

    if(rehashesCount > MAX_REHASHES){
        expand();
        rehashesCount = 0;
    }else{
        rehash();
    }
}

template<typename AnyT, typename HashFuncs>
CuckooHashR<AnyT, HashFuncs>::CuckooHashR(int capacity)
: CuckooTable(capacity)
{
    hashFuncN = hashFuncs.getHashFuncN();
}


template<typename AnyT, typename HashFuncs>
bool CuckooHashR<AnyT, HashFuncs>::isActive(int pos) {
    if(pos == -1){
        return false;
    }
    return CuckooTable.at(pos).isActive;
}

#endif //GENERALHASHING_CUCKOOHASHRCORE_INL
