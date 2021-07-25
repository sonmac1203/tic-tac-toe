#include <iostream>
#include "Board.hpp"
#include "Player.hpp"

int main(int argc, char** argv){
    Board new_game;
    Player human('X');
    Player computer('O');
    new_game.play(human, computer);

    return 0;

}

