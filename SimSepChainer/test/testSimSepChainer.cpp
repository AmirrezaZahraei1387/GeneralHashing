//
// Created by KAVOSH on 1/2/2024.
//
#include <iostream>
#include "../SimSepChainer.hpp"
#define CAPACITY_TABLE 40

constexpr int MAX_NUM{90};

size_t hashFunction(const int& x, size_t){
    return x/2;
}

void insertItems(SimSepChainer<int>& table){
    bool x;

    for(int i{0}; i<= MAX_NUM; ++i){
        x = table.insert(i);
        std::cout<<"insertion of number "<<i<<" resulted in "<<x<<std::endl;
    }
}

void removeItems(SimSepChainer<int>& table){
    bool x;

    for(int i{0}; i<= MAX_NUM; i+=3){
        x = table.remove(i);
        std::cout<<"deletion of number "<<i<<" resulted in "<<x<<std::endl;
    }
}

void containTest(SimSepChainer<int>& table){
    bool x;

    for(int i{0}; i<= MAX_NUM; ++i){
        x = table.contain(i);
        std::cout<<"contain operation of "<<i<<" resulted in "<<x<<std::endl;
    }
}


int main(){
    SimSepChainer<int> table(hashFunction, CAPACITY_TABLE);
    insertItems(table);
    std::cout<<"current size: "<<table.getSize()<<std::endl;
    removeItems(table);
    std::cout<<"current size: "<<table.getSize()<<std::endl;
    containTest(table);
    std::cout<<"making the list empty: "<<std::endl;
    table.makeEmpty();
    std::cout<<"current size: "<<table.getSize()<<std::endl;
    insertItems(table);
    std::cout<<"current size: "<<table.getSize()<<std::endl;
}