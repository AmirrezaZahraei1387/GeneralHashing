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
    void getSize();
    bool remove(const AnyT& element);
    bool contain(const AnyT& element);
private:

    struct CuckooNode{
        AnyT element;
        bool isActive;
    };

    static constexpr double LOAD_FACTER{0.40};
    static constexpr int MAX_REHASHES{5};

    bool insertHelper(const AnyT& element);
    bool insertHelper(const AnyT&& element);
    size_t getHashFuc(const AnyT& element, int which);
    int findPos(const AnyT& element);
    void rehash();
    void rehash(int newSize);
    void expand();

    std::vector<CuckooNode> CuckooTable;
    int currentSize{0};
    std::uniform_int_distribution<int> random;
    int hashFuncN{};
    int rehashesCount{0};
    HashFuncs hashFuncs;
};


#endif //GENERALHASHING_CUCKOOHASHR_HPP
