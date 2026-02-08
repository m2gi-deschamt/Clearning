#include "Board.hpp"

// Constructeur
Board::Board(int r, int c) : rows(r), columns(c) {
    cells.resize(r);
    for (int i = 0; i < r; ++i) {
        cells[i].resize(c);
    }
}


// Accès aux cellules
Cell& Board::cellAt(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= columns) {
        throw std::out_of_range("Board::cellAt: indices out of range");
    }
    return cells[row][col];
}

const Cell& Board::cellAt(int row, int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= columns) {
        throw std::out_of_range("Board::cellAt: indices out of range");
    }
    return cells[row][col];
}

// Affichage du plateau
void Board::display() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (cells[i][j].isEmpty()) {
                std::cout << ". ";
            } else {
                std::cout << "P "; // On affiche "P" si la cellule contient une pièce
            }
        }
        std::cout << "\n";
    }
}
