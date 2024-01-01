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
    using HashFunction = std::function<size_t(const HashObj&, size_t tableSize)>;

    explicit SimSepChainer(HashFunction& hashFunc);
    explicit SimSepChainer(SimSepChainer& ht);
    explicit SimSepChainer(SimSepChainer&& ht);

    SimSepChainer& operator = (SimSepChainer<HashObj>& ht);
    SimSepChainer& operator = (SimSepChainer<HashObj>&& ht);

    void makeEmpty();
    bool isEmpty();

    bool insert(const HashObj& ho);
    bool insert(HashObj&& ho);
    bool remove(const HashObj& ho);
    bool contain(const HashObj& ho);

private:
    std::vector<std::list<HashObj>> hashTable_p;
    HashFunction& hashFunc_p;
};


#endif //GENERALHASHING_SIMSEPCHAINER_HPP
