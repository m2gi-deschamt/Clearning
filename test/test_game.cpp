#include <catch2/catch_test_macros.hpp>

int sub(int a, int b) {
    return a - b;
}

TEST_CASE("Substraction simple", "[math]") {
    REQUIRE(sub(4, 3) == 1);
}

TEST_CASE("Substraction difficile", "[math]") {
    REQUIRE(sub(32, 12) == 20);
}
