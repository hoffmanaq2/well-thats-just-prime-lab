#include <vector>
#include <string>
#pragma once

class Factorizer {
public:
    //methods that will calculate and return prime factors of a number
    std::vector<int> primeFactors (int n);
    bool isPrime(int n);
    bool isComposite(int n);
    std::string reduce(int numerator, int denominator);
};