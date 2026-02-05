#ifndef GAME_HPP
#define GAME_HPP


#include "Board.hpp"
#include "Player.hpp"


#include <string>
#include <set>

using namespace std;
class Game {
    private:
        string name;
        //set<Player> players;
        Board board;

    public:
        Game(string name, Board board);
        void start();
        void play();
        void pause();
};
#endif