#ifndef PIECE_HPP
#define PIECE_HPP

#include "string"

class Piece {
private:
    std::string name;

public:
    Piece(const std::string& n) : name(n) {}
    std::string getName() const { return name; }
};

class Pawn : public Piece {
public:
    Pawn() : Piece("pawn") {}
};


#endif