#include "Game.hpp"

#include <iostream>


bool Puissance4::isMoveValid(int row, int col, const Board& board) const {
    return true;
}

bool Puissance4::checkVictory(const Board& board) const {
    return false;
}

std::string Puissance4::getName() const {
    return name;
}

int Puissance4::getRows() const {
    return board_rows;
}

int Puissance4::getCols() const {
    return board_columns;
}

int Puissance4::getMaxPlayer() const {
    return NUMBER_OF_PLAYER;
}


GameInstance::GameInstance(const Game &game)
    : 
    game(game),
    board(game.getRows(), game.getCols())
    {};

void GameInstance::addPlayer(const Player &player) {
    if (players.size() < game.getMaxPlayer()) {
        players.insert(player);
    } else {
        cout << "add new player to this instance is not possible";
    }
};

void GameInstance::start() {

}
void GameInstance::play() {

}
void GameInstance::pause() {

}

void GameInstance::display() {
    cout << "Game instance values : \n game : " << game.getName() << "\n";
};

const set<Player>& GameInstance::getPlayers() const {
    return players;
}

void GameInstance::placePiece(Position position, std::unique_ptr<Piece> piece) {
    board.placePiece(position, std::move(piece));
}

bool GameInstance::havePiece(Position pos) const {
    return board.havePiece(pos);
}