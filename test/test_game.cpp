#include <catch2/catch_test_macros.hpp>
#include "Game.hpp"
#include "Player.hpp"

TEST_CASE("Add players", "[player]") {
    Player player1("Thibaud", 32, MALE);
    Player player2("Olivier", 24, MALE);
    Puissance4 puissance4;
    GameInstance game(puissance4);
    REQUIRE(game.getPlayers().size() == 0);
    game.addPlayer(player1);
    REQUIRE(game.getPlayers().size() == 1);
}

TEST_CASE("Number of players > MAX", "[player]") {
    Player player1("Thibaud", 32, MALE);
    Player player2("Olivier", 24, MALE);
    Player player3("Mylene", 28, FEMALE);
    Puissance4 puissance4;
    GameInstance game(puissance4);
    game.addPlayer(player1);
    game.addPlayer(player2);
    REQUIRE(game.getPlayers().size() == 2);
    game.addPlayer(player3); // should return a warning, two players max for this game
    REQUIRE(game.getPlayers().size() == 2);
}

