#include <catch2/catch_test_macros.hpp>
#include "Player.hpp"

TEST_CASE("create player", "[math]") {
    Player player1("Thibaud", 24, MALE);

    REQUIRE(player1.getAge() == 24);
    REQUIRE(player1.getName() == "Thibaud");
    REQUIRE(player1.getGender() == MALE);
}
