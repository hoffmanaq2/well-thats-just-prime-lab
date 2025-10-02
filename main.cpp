#include <iostream>

#include "src/prime.hpp"

void printVector(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i != v.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}

int main() {
    Factorizer f;

    std::vector<int> result0 = f.primeFactors(0);
    std::vector<int> result1 = f.primeFactors(1);
    std::vector<int> result2 = f.primeFactors(9);
    std::vector<int> result3 = f.primeFactors(10);
    std::vector<int> result4 = f.primeFactors(100);

    std::cout << "Factors of 0: "; printVector(result0); std::cout << "\n";
    std::cout << "Factors of 1: "; printVector(result1); std::cout << "\n";
    std::cout << "Factors of 9: "; printVector(result2); std::cout << "\n";
    std::cout << "Factors of 10: "; printVector(result3); std::cout << "\n";
    std::cout << "Factors of 100: "; printVector(result4); std::cout << "\n";

}