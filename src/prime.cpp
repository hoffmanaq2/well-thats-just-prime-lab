#include "../src/prime.hpp"

std::vector<int> Factorizer::primeFactors(int n) {
    std::vector<int> factors;

    if (n <= 1) {
        return factors;
    }

    //divide out factor 2
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    //check off factors
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    if (n > 2) {
        factors.push_back(n);
    }

    return factors;
}