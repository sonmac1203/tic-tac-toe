#ifndef TICTACTOE_BOARD
#define TICTACTOE_BOARD

#include <iostream>
#include <vector>
#include "player.hpp"

class Board{

public:   

struct miniMax{
    int position;
    int score;
};

    int board[3][3];

    Board(){
        makeBoard();
    }

    void makeBoard(){ // Initialize a board
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                board[i][j] = 0; 
            } 
        }
    }

    void printBoard(){ // Receive a board and print it
        char letterBoard[3][3];
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (board[i][j] == 0){
                    letterBoard[i][j] = ' ';
                }
                else if (board[i][j] == 1){
                    letterBoard[i][j] = 'X';
                }
                else{
                    letterBoard[i][j] = 'O';
                }

                if ( j == 2){
                    std::cout << " " << letterBoard[i][j] << " ";
                }
                else{
                    std::cout << " " << letterBoard[i][j] << " |";
                }
            }
            std::cout<<std::endl;
        }
    }


    bool checkWin(){
	    for (int i = 0; i < 3; i++) {
		    if (board[i][0] + board[i][1] + board[i][2] == 3 || board[0][i] + board[1][i] + board[2][i] == 3 || board[0][0] + board[1][1] + board[2][2] == 3 || board[0][2] + board[1][1] + board[2][0] == 3) { //Three 'X's means a sum of 3, since X corresponds to 1
			    return true;
		    }
		    else if (board[i][0] + board[i][1] + board[i][2] == -3 || board[0][i] + board[1][i] + board[2][i] == -3 || board[0][0] + board[1][1] + board[2][2] == -3 || board[0][2] + board[1][1] + board[2][0] == -3) { //Three 'O's means a sum of 0, since O corresponds to 0
		    	return true;
		    }
	    }
        return false;       
    }

    int checkPlayerWin(){
	    for (int i = 0; i < 3; i++) {
		    if (board[i][0] + board[i][1] + board[i][2] == 3 || board[0][i] + board[1][i] + board[2][i] == 3 || board[0][0] + board[1][1] + board[2][2] == 3 || board[0][2] + board[1][1] + board[2][0] == 3) { //Three 'X's means a sum of 3, since X corresponds to 1
			    return -1;
		    }
		    else if (board[i][0] + board[i][1] + board[i][2] == -3 || board[0][i] + board[1][i] + board[2][i] == -3 || board[0][0] + board[1][1] + board[2][2] == -3 || board[0][2] + board[1][1] + board[2][0] == -3) { //Three 'O's means a sum of 0, since O corresponds to 0
		    	return 1;
		    }
	    }
        return 0;       
    }


    bool checkFull(){ // Check if the board is already full or not
        if (countEmptyBoxes() == 0)
            return true;
        return false;
    }


    void makeMove(Player player,  int position){ // Make the move for either human or computer
        if(board[returnY(position)][returnX(position)] == 0){
            if(player.getLetter() == 'X'){
                board[returnY(position)][returnX(position)] = 1;
            }
            else if (player.getLetter() == 'O'){
                board[returnY(position)][returnX(position)] = -1;
            }
        }
    }



    int countEmptyBoxes(){
        int emptyBox = 0;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (board[i][j] == 0)
                    emptyBox++;
            }
        }
        return emptyBox;
    }

    int utilityFunction(){ // Calculate the utility function's value
        return (checkPlayerWin())*(countEmptyBoxes()+1);
    }

    std::vector<int> availableMove(){
        std::vector<int> avail_move;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (board[i][j] == 0){
                    avail_move.push_back(3*i + j);
                }
            }
        }
        return avail_move;
    }

    void print_avail_move(std::vector<int> avail_move){
        for (int i = 0; i < avail_move.size(); i++){
            std::cout << avail_move.at(i) << " ";
        }
        std::cout<<std::endl;
    }


    void play(Player player1, Player player2){
        Board::welcome(); // welcome statement and introduction board

        while (1){
            int position;
            bool valid_answer = false;
            while(!valid_answer){
                std::cout << "Human please enter position (0 - 8): ";
                std::cin >> position;
                for (int i = 0; i < availableMove().size(); i++){
                    if (position == availableMove().at(i)){
                        valid_answer = true;
                        break;
                    }
                }
            }
            Board::makeMove(player1, position);
            Board::printBoard();
            if(checkWin()){
                std::cout << "Human won !!!" << std::endl;
                break;
            }
            if (checkFull()){
                std::cout << "This is a tie !!!" << std::endl;
                break;
            }  
            position = computerPlay(player2).position;
            Board::makeMove(player2, position);
            std::cout << "Computer chose position: " << position << std::endl;
            Board::printBoard();
            if(checkWin()){
                std::cout << "Computer won !!!" << std::endl;
                break;
            }
            if (checkFull()){
                std::cout << "This is a tie !!!" << std::endl;
                break;
            }        
        }
    }

    miniMax computerPlay(Player player){
        Player other_player;
        if(player.getLetter() == 'O'){
            other_player.setLetter('X');
        }
        else{
            other_player.setLetter('O');
        }
        miniMax best;
        miniMax sim;

        if (checkWin()) {
            best.position = -100;
            best.score = utilityFunction();
            return best;        
        }
        else if (checkFull()) {
            best.position = -100;
            best.score = 0;
            return best;
        }

        if (player.getLetter() == 'O'){ // O
            best.position = -100;
            best.score = -500;
        }
        else if (player.getLetter() == 'X'){ // X
            best.position = -100;
            best.score = 500;
        }

        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (board[i][j] == 0){
                    makeMove(player, (3*i+j));
                    sim = computerPlay(other_player);

                    // Undo move
                    board[i][j] = 0;
                    sim.position = 3*i + j;

                    if (player.getLetter() == 'O'){
                        if (sim.score > best.score){
                            best = sim;
                        }
                    }
                    else {
                        if (sim.score < best.score){
                            best = sim;
                        }
                    }
                }
            }
        }
        return best;
    }

    void welcome(){
        std::cout<<"Let's play Tic Tac Toe!"<<std::endl;
        std::cout<<" 0 | 1 | 2 \n 3 | 4 | 5 \n 6 | 7 | 8 "<< std::endl; 
    }

    int returnX(int position){ // Convert from position to x coordinate
        return position % 3;
    }

    int returnY(int position){ // Convert from position to y coordinate
        return (int)(position / 3);
    }
};




#endif
