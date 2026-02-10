#include <gtest/gtest.h>
#include "Game.hpp"
#include "Player.hpp"

TEST(GameTest, AddPlayers) {
    Player player1("Thibaud", 32, MALE);
    Player player2("Olivier", 24, MALE);
    Puissance4 puissance4;
    GameInstance game(puissance4);
    EXPECT_TRUE(game.getPlayers().size() == 0);
    game.addPlayer(player1);
    EXPECT_TRUE(game.getPlayers().size() == 1);
}

TEST(GameTest, PLAYERMAX) {
    Player player1("Thibaud", 32, MALE);
    Player player2("Olivier", 24, MALE);
    Player player3("Mylene", 28, FEMALE);
    const Puissance4 puissance4;
    GameInstance game(puissance4);
    game.addPlayer(player1);
    game.addPlayer(player2);
    EXPECT_TRUE(game.getPlayers().size() == 2);
    game.addPlayer(player3); // should return a warning, two players max for this game
    EXPECT_TRUE(game.getPlayers().size() == 2);
}

