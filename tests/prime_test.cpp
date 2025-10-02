#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/prime.hpp"

// Z - Zero
TEST_CASE("Zero input returns empty factors", "[Z]") {
    Factorizer f;
    REQUIRE(f.primeFactors(0).empty());
}

// O - One
TEST_CASE("One input returns empty factors", "[O]") {
    Factorizer f;
    REQUIRE(f.primeFactors(1).empty());
}

// M - Many
TEST_CASE("Composite numbers with many factors", "[M]") {
    Factorizer f;
    REQUIRE(f.primeFactors(100) == std::vector<int>{2, 2, 5, 5});
    REQUIRE(f.primeFactors(60) == std::vector<int>{2, 2, 3, 5});
}

// B - Boundaries
TEST_CASE("Boundary numbers around primes", "[B]") {
    Factorizer f;
    REQUIRE(f.primeFactors(2) == std::vector<int>{2});
    REQUIRE(f.primeFactors(3) == std::vector<int>{3});
    REQUIRE(f.primeFactors(4) == std::vector<int>{2, 2});
}

// I - Interfaces
TEST_CASE("Interface consistency: same input gives same output", "[I]") {
    Factorizer f;
    std::vector<int> firstCall = f.primeFactors(36);
    std::vector<int> secondCall = f.primeFactors(36);
    REQUIRE(firstCall == secondCall);
}

// E - Exceptions (special or unexpected inputs)
TEST_CASE("Negative numbers return empty factors", "[E]") {
    Factorizer f;
    REQUIRE(f.primeFactors(-5).empty());
}

// S - Sample (general known cases)
TEST_CASE("Sample known factorizations", "[S]") {
    Factorizer f;
    REQUIRE(f.primeFactors(9) == std::vector<int>{3, 3});
    REQUIRE(f.primeFactors(10) == std::vector<int>{2, 5});
    REQUIRE(f.primeFactors(17) == std::vector<int>{17}); // prime number
}
