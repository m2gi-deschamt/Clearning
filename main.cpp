#include "Player.hpp"
#include "Game.hpp"

int main() {
    Player playerOne("Thibaud", 25, MALE);
    Puissance4 game;
    

    GameInstance firstGame(game);
    firstGame.addPlayer(playerOne);

    playerOne.display();

    firstGame.display();




    return 0;
}