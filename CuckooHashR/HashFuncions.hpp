//
// Created by KAVOSH on 1/4/2024.
//
#ifndef GENERALHASHING_HASHFUNCIONS_HPP
#define GENERALHASHING_HASHFUNCIONS_HPP
#include <cstddef>

// providing an interface class for the class to implement the
// hash function generating scheme

template<typename AnyT>
class HashFunction{
public:

    // determines the ith hash function and returns
    // the appropriate hash id for the item element
    // by using tableCapacity which is optional.
    virtual size_t hash(const AnyT& element, int tableCapacity, int i) const = 0;

    // return the number of hash functions available
    virtual int getHashFuncN() = 0;

    // generating the same amount of new hash function as before
    virtual void generateNewFuncs() = 0;

};


#endif //GENERALHASHING_HASHFUNCIONS_HPP
