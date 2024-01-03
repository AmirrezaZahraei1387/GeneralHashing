//
// Created by KAVOSH on 1/3/2024.
//
#include "NextPrime.hpp"

int nextPrime(int number) {

    int n{number - 1};
    bool isPrime;

    while(true){
        ++n;
        for(int i = 2; i<(n/2); ++i){
            if(n % i == 0) {
                isPrime = false;
                break;
            }
        }

        if(isPrime){
            return n;
        }else
            isPrime = true;
    }

}

