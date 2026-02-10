#include <gtest/gtest.h>
#include "Board.hpp"
#include "Piece.hpp"
#include "Game.hpp"

using namespace std;


class GameInstanceTest : public ::testing::Test {
protected:
    Puissance4 puissance4;
    GameInstance game;

    GameInstanceTest() : game(puissance4) {}

    void SetUp() override {
        game.placePiece({1,1}, std::make_unique<Pawn>());
    }

    void TearDown() override {
        // Optionnel : nettoyage après chaque test
    }
};

TEST_F(GameInstanceTest, HavePieceAt11) {
    EXPECT_TRUE(game.havePiece({1,1}));
}

TEST_F(GameInstanceTest, NoPieceAt12) {
    EXPECT_FALSE(game.havePiece({1,2}));
}
