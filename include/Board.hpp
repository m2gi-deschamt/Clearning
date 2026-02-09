#ifndef BOARD_HPP
#define BOARD_HPP

#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

using std::vector;

#include "Piece.hpp"

struct Position {
    int row;
    int col;
};

class Cell {
private:
    std::unique_ptr<Piece> piece;

    Cell() : piece(nullptr) {}

    std::unique_ptr<Piece> takePiece() {
        return std::move(piece);
    }

    bool setPiece(std::unique_ptr<Piece> p) { piece = std::move(p); return true;}

    void removePiece() { piece.reset(); }

    bool isEmpty() const { return piece == nullptr; }

    Piece* getPiece() const { return piece.get(); }

    friend class Board;
};

class Board {
private:
    vector<vector<Cell>> cells;
    int rows;
    int columns;

    void movePiece(Position from, Position to); 
    bool havePiece(Position position) const;
    void placePiece(Position position, std::unique_ptr<Piece> piece);
    
    Cell& cellAt(int row, int col); 
    const Cell& cellAt(int row, int col) const;
     
    int getRows() const { return rows; } 
    int getCols() const { return columns; }
    void display() const;
    Board(int rows, int columns);

    friend class GameInstance;
};

#endif