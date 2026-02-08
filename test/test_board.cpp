#include <catch2/catch_test_macros.hpp>
#include "Board.hpp"

TEST_CASE("Get columns", "[board]") {
    Board board(6, 7);
    REQUIRE(board.getCols() == 7);
}

TEST_CASE("Add piece", "[board]") {
    Board board(6, 7);
    board.cellAt(1,1).setPiece(std::make_unique<Piece>("pawn"));
    REQUIRE(board.cellAt(1,1).getPiece()->getName() == "pawn");
}
