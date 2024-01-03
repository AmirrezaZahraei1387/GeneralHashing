//
// Created by KAVOSH on 1/1/2024.
//
#ifndef GENERALHASHING_SIMSEPCHAINER_HPP
#define GENERALHASHING_SIMSEPCHAINER_HPP
#include <list>
#include <vector>
#include <functional>

template<typename HashObj>
class SimSepChainer{
public:
    using HashFunction = std::function<size_t(const HashObj&, size_t)>;

    explicit SimSepChainer(HashFunction hashFunc, size_t capacity);

    void makeEmpty();

    bool insert(const HashObj& ho);
    bool insert(HashObj&& ho);
    bool remove(const HashObj& ho);
    bool contain(const HashObj& ho);
    size_t getSize();
    size_t getCapacity();

private:

    bool boundOk(size_t hash);
    void rehash();

    std::vector<std::list<HashObj>> hashTable_p;
    HashFunction& hashFunc_p;
    size_t size_p{0};
    size_t capacity_p;
};

#include "SimSepChainer.inl"
#include "SimSepChainerMem.inl"
#endif //GENERALHASHING_SIMSEPCHAINER_HPP
