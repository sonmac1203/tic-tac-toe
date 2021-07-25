#ifndef TICTACTOE_PLAYER
#define TICTACTOE_PLAYER

#define pass (void)0
#include <iostream>
#include <vector>

class Player{
private:
    char letter;

public:
    Player(char letter){
        this->letter = letter;
    }
    Player(){
        pass;
    }

    char getLetter(){
        return this->letter;
    }

    void setLetter(char letter){
        this->letter = letter;
    }
};

#endif