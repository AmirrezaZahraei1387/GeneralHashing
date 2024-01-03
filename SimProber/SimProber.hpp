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

    bool contain(HashObj& element);
    bool insert(HashObj& element);
    bool insert(HashObj&& element);
    bool remove(HashObj& element);
    size_t getSize();
    void makeEmpty();

private:
    enum NodeState{DELETED, EMPTY, ACTIVE};

    struct Node{
        HashObj element;
        NodeState status;
    };


    std::vector<NodeState> hashTable_p;
    HashFunction& hashFunc_p;
    size_t size_p{0};
    size_t capacity_p;

    bool isActive(size_t index);
    size_t findPos(const HashObj& element);
    void rehash();
};


#endif //GENERALHASHING_SIMPROBER_HPP
