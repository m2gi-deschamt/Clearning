#include <catch2/catch_test_macros.hpp>
#include "Board.hpp"
#include "Piece.hpp"
/*
TEST_CASE("add piece", "[board]") {
    Board board(6, 7);
    REQUIRE(board.cellAt(1,1).getPiece()->getName() == "pawn");
}

TEST_CASE("have piece") {
    Board board(6, 7);
    board.setPiece(1,1,std::make_unique<Pawn>());
    REQUIRE(board.havePiece(1,1) == true);
    REQUIRE(board.havePiece(1,0) == false);
}
    */