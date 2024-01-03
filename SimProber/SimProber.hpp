//
// Created by KAVOSH on 1/2/2024.
//
#ifndef GENERALHASHING_SIMPROBER_HPP
#define GENERALHASHING_SIMPROBER_HPP
#include <functional>
#include <cstddef>
#include <vector>

template<typename HashObj>
class SimProber{
public:
    using HashFunction = std::function<size_t(const HashObj&, size_t)>;
    explicit SimProber(HashFunction hashFunc, size_t capacity);

    bool contain(const HashObj& element);
    bool insert(const HashObj& element);
    bool insert(HashObj&& element);
    bool remove(const HashObj& element);
    size_t getSize();
    size_t getCapacity();
    void makeEmpty();

private:
    enum NodeState{DELETED, EMPTY, ACTIVE};

    struct Node{
        HashObj element;
        NodeState status{EMPTY};
    };


    std::vector<Node> hashTable_p;
    HashFunction hashFunc_p;
    size_t size_p{0};
    size_t capacity_p;

    bool isActive(size_t index);
    size_t findPos(const HashObj& element);
    void rehash();
};

#include "SimProber.inl"

#endif //GENERALHASHING_SIMPROBER_HPP
