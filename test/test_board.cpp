#include <catch2/catch_test_macros.hpp>

int mut(int a, int b) {
    return a * b;
}

TEST_CASE("Multiplication simple", "[math]") {
    REQUIRE(mut(4, 3) == 12);
}

TEST_CASE("Multiplication difficile", "[math]") {
    REQUIRE(mut(3, 6) == 18);
}
