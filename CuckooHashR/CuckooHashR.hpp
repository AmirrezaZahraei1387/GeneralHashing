//
// Created by KAVOSH on 1/4/2024.
//
#ifndef GENERALHASHING_CUCKOOHASHR_HPP
#define GENERALHASHING_CUCKOOHASHR_HPP
#include <cstddef>
#include <vector>
#include <random>

template<typename AnyT, typename HashFuncs>
class CuckooHashR{
public:
    explicit CuckooHashR(int capacity);

    bool insert(const AnyT& element);
    bool insert(AnyT&& element);
    void makeEmpty();
    int getSize();
    bool remove(const AnyT& element);
    bool contain(const AnyT& element);
private:

    struct CuckooNode{
        AnyT element;
        bool isActive{false};
    };

    static constexpr double LOAD_FACTER{0.40};
    static constexpr int MAX_REHASHES{5};

    bool isActive(int pos);
    bool insertHelper(const AnyT& element);
    bool insertHelper(const AnyT&& element);
    size_t getHashFunc(const AnyT& element, int which);
    int findPos(const AnyT& element);
    void rehash();
    void rehash(int newSize);
    void expand();

    std::vector<CuckooNode> CuckooTable;
    int currentSize{0};
    int hashFuncN{};
    int rehashesCount{0};
    HashFuncs hashFuncs;

    std::random_device rd{};
    std::mt19937 r{rd()};
    std::uniform_int_distribution<int> random{0, hashFuncN - 1};

};

#include "CuckooHashRCore.inl"
#include "CuckooHashRInter.inl"

#endif //GENERALHASHING_CUCKOOHASHR_HPP
