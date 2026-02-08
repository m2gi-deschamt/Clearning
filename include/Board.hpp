#ifndef BOARD_HPP
#define BOARD_HPP

#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

using std::vector;

#include "Piece.hpp"


class Cell {
private:
    std::unique_ptr<Piece> piece;
public:
    Cell() : piece(nullptr) {}

    bool isEmpty() const { return piece == nullptr; }

    Piece* getPiece() const { return piece.get(); }

    void setPiece(std::unique_ptr<Piece> p) { piece = std::move(p); }

    void removePiece() { piece.reset(); }
};

class Board {
private:
    vector<vector<Cell>> cells;
    int rows;
    int columns;
public: 
    Board(int rows, int columns);
    bool havePiece(int row, int col) const;
    Cell& cellAt(int row, int col); 
    const Cell& cellAt(int row, int col) const; 
    int getRows() const { return rows; } 
    int getCols() const { return columns; }
    void display() const;
};

#endif