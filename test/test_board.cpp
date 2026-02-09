#include <catch2/catch_test_macros.hpp>
#include "Board.hpp"
#include "Piece.hpp"
#include "Game.hpp"

using namespace std;

TEST_CASE("have piece") {
    const Puissance4 puissance4;
    GameInstance game(puissance4);
    game.placePiece({1,1}, std::make_unique<Pawn>());
    REQUIRE(game.havePiece({1,1}) == true);
}

TEST_CASE("No piece") {
    const Puissance4 puissance4;
    GameInstance game(puissance4);
    game.placePiece({1,3}, std::make_unique<Pawn>());
    REQUIRE(game.havePiece({1,1}) == false);
}
