#include "../src/prime.hpp"
#include <sstream>

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

//ADD ONS FOR PORTFOLIO

//Check if number is prime
bool Factorizer::isPrime(int n) {
    if (n<= 1) {
        return false;
    }
    std::vector<int> factors = primeFactors(n);
    // A prime number will have exactly one prime factor: itself
    return (factors.size() == 1 && factors[0] == n);
}

// Check if a number is composite
bool Factorizer::isComposite(int n) {
    if (n <= 1) {
        return false; // 0 and 1 are not composite
    }
    // Composite means not prime
    return !isPrime(n);
}


// Simplify (reduce) a fraction using primes
std::string Factorizer::reduce(int numerator, int denominator) {
    if (denominator == 0) {
        return "undefined"; // cannot divide by zero
    }

    if (numerator == 0) {
        return "0";
    }

    std::vector<int> numFactors = primeFactors(numerator);
    std::vector<int> denFactors = primeFactors(denominator);

    // Cancel out common factors
    for (size_t i = 0; i < numFactors.size(); i++) {
        for (size_t j = 0; j < denFactors.size(); j++) {
            if (numFactors[i] == denFactors[j]) {
                numFactors[i] = 1;
                denFactors[j] = 1;
                break;
            }
        }
    }

    // Multiply remaining numerator and denominator
    int reducedNum = 1;
    for (size_t i = 0; i < numFactors.size(); i++) {
        reducedNum *= numFactors[i];
    }

    int reducedDen = 1;
    for (size_t j = 0; j < denFactors.size(); j++) {
        reducedDen *= denFactors[j];
    }

    // If the denominator reduces to 1, return only numerator
    if (reducedDen == 1) {
        std::ostringstream oss;
        oss << reducedNum;
        return oss.str();
    }

    // Otherwise, return "num/den"
    std::ostringstream oss;
    oss << reducedNum << "/" << reducedDen;
    return oss.str();
}