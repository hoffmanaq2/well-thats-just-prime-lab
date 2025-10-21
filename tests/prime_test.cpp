#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/prime.hpp"

// Z - Zero
TEST_CASE("Zero input returns empty factors", "[Z]") {
    Factorizer f;
    REQUIRE(f.primeFactors(0).empty());

    // isPrime and isComposite
    REQUIRE(f.isPrime(0) == false);
    REQUIRE(f.isComposite(0) == false);

    // reduce (0 as numerator)
    REQUIRE(f.reduce(0, 5) == "0");
}

// O - One
TEST_CASE("One input returns empty factors", "[O]") {
    Factorizer f;
    REQUIRE(f.primeFactors(1).empty());

    REQUIRE(f.isPrime(1) == false);
    REQUIRE(f.isComposite(1) == false);

    // reduce (1 over something)
    REQUIRE(f.reduce(1, 3) == "1/3");
    REQUIRE(f.reduce(3, 1) == "3");
}

// M - Many
TEST_CASE("Composite numbers with many factors", "[M]") {
    Factorizer f;
    REQUIRE(f.primeFactors(100) == std::vector<int>{2, 2, 5, 5});
    REQUIRE(f.primeFactors(60) == std::vector<int>{2, 2, 3, 5});

    // isPrime
    REQUIRE(f.isPrime(2) == true);
    REQUIRE(f.isPrime(3) == true);
    REQUIRE(f.isPrime(4) == false);
    REQUIRE(f.isPrime(9) == false);
    REQUIRE(f.isPrime(17) == true);

    // isComposite
    REQUIRE(f.isComposite(4) == true);
    REQUIRE(f.isComposite(9) == true);
    REQUIRE(f.isComposite(17) == false);

    // reduce
    REQUIRE(f.reduce(36, 12) == "3");
    REQUIRE(f.reduce(12, 12) == "1");
    REQUIRE(f.reduce(12, 14) == "6/7");
    REQUIRE(f.reduce(12, 37) == "12/37");
}

// B - Boundaries
TEST_CASE("Boundary numbers around primes", "[B]") {
    Factorizer f;
    REQUIRE(f.primeFactors(2) == std::vector<int>{2});
    REQUIRE(f.primeFactors(3) == std::vector<int>{3});
    REQUIRE(f.primeFactors(4) == std::vector<int>{2, 2});

    REQUIRE(f.isPrime(2) == true);
    REQUIRE(f.isPrime(3) == true);
    REQUIRE(f.isPrime(4) == false);
    REQUIRE(f.isPrime(5) == true);
    REQUIRE(f.isPrime(6) == false);

    // reduce small fractions
    REQUIRE(f.reduce(2, 4) == "1/2");
    REQUIRE(f.reduce(3, 9) == "1/3");

}

// I - Interfaces
TEST_CASE("Interface consistency: same input gives same output", "[I]") {
    Factorizer f;
    std::vector<int> firstCall = f.primeFactors(36);
    std::vector<int> secondCall = f.primeFactors(36);
    REQUIRE(firstCall == secondCall);


    bool first = f.isPrime(13);
    bool second = f.isPrime(13);
    REQUIRE(first == second);

    std::string firstReduce = f.reduce(12, 14);
    std::string secondReduce = f.reduce(12, 14);
    REQUIRE(firstReduce == secondReduce);
}

// E - Exceptions (special or unexpected inputs)
TEST_CASE("Negative numbers return empty factors", "[E]") {
    Factorizer f;
    REQUIRE(f.primeFactors(-5).empty());

    // Denominator zero
    REQUIRE(f.reduce(5, 0) == "undefined");

    // Negative values
    REQUIRE(f.isPrime(-7) == false);
    REQUIRE(f.isComposite(-10) == false);
}

// S - Sample (general known cases)
TEST_CASE("Sample known factorizations", "[S]") {
    Factorizer f;
    REQUIRE(f.primeFactors(9) == std::vector<int>{3, 3});
    REQUIRE(f.primeFactors(10) == std::vector<int>{2, 5});
    REQUIRE(f.primeFactors(17) == std::vector<int>{17}); // prime number

    REQUIRE(f.isPrime(7) == true);
    REQUIRE(f.isComposite(8) == true);

    REQUIRE(f.reduce(10, 5) == "2");
    REQUIRE(f.reduce(15, 20) == "3/4");

}

