#ifndef GAME_HPP
#define GAME_HPP


#include "Board.hpp"
#include "Player.hpp"
#include "Piece.hpp"

#include <string>
#include <set>

using namespace std;
enum GameState {
    START,
    INPROGRESS,
    FINISH
};

class Game {
    public:
        Game() = default;
        virtual bool isMoveValid(int row, int col, const Board& board) const = 0;
        virtual bool checkVictory(const Board& board) const = 0;
        virtual std::string getName() const = 0;
        virtual int getRows() const = 0;
        virtual int getCols() const = 0;
        virtual int getMaxPlayer() const = 0;

    private: 
        int NUMBER_OF_PLAYER;
};


class Puissance4 : public Game {
    private:
        int NUMBER_OF_PLAYER = 2;
        std::string name = "Puissance 4";
        int board_rows = 6;
        int board_columns = 7;
    
    public:
        Puissance4(){};
        bool isMoveValid(int row, int col, const Board& board) const override;
        bool checkVictory(const Board& board) const override;
        std::string getName() const override;
        int getRows() const override;
        int getCols() const override;  
        int getMaxPlayer() const override;
};


class GameInstance {
    private:
        const Game &game;
        set<Player> players;
        Board board;
        enum GameState state = START;
        
    public:
        GameInstance(const Game &game);
        void start();
        void play();
        void pause();
       
        void addPlayer(const Player &player);
        const set<Player>& getPlayers() const;
        
        void placePiece(Position position, std::unique_ptr<Piece> piece);

        bool havePiece(Position pos) const;
        void display();
};
#endif