#include <gtest/gtest.h>
#include "Player.hpp"

TEST(PlayerTest, ConfigPlayer) {
    Player player1("Thibaud", 24, MALE);
    EXPECT_TRUE(player1.getAge() == 24);
    EXPECT_TRUE(player1.getName() == "Thibaud");
    EXPECT_TRUE(player1.getGender() == MALE);
}
