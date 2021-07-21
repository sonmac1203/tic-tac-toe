#include <iostream>
#include "player.hpp"

using namespace std;

class TicTacToe{
private:
    int board[3][3];
    Player human = Player(1);
    Player computer = Player(-1);
    int totalTurns = 9;


public:

    TicTacToe(){
        makeBoard();
    }

    void makeBoard(){ // Initialize a board
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                board[i][j] = 0; 
            } 
        }
    }

    void printBoard(int board[][3]){ // Receive a board and print it
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
                    letterBoard[i][j] = 'Y';
                }

                if ( j == 2){
                    cout << " " << letterBoard[i][j] << " ";
                }
                else{
                    cout << " " << letterBoard[i][j] << " |";
                }
            }
            cout<<endl;
        }
    }


    bool checkWin(int board[][3]){
	    for (int i = 0; i < 3; i++) {
		    if (board[i][0] + board[i][1] + board[i][2] == 3 || board[0][i] + board[1][i] + board[2][i] == 3 || board[0][0] + board[1][1] + board[2][2] == 3 || board[0][2] + board[1][1] + board[2][0] == 3) { //Three 'X's means a sum of 3, since X corresponds to 1
			    return true;
		    }
		    else if (board[i][0] + board[i][1] + board[i][2] == -3 || board[0][i] + board[1][i] + board[2][i] == -3 || board[0][0] + board[1][1] + board[2][2] == -3 || board[0][2] + board[1][1] + board[2][0] == -3) { //Three 'O's means a sum of 0, since O corresponds to 0
		    	return true;
		    }
		    else {
		    	return false;
		    }
	    }       
    }

    int checkPlayerWin(int x[][3]) { //This function checks whether P1 has won the game and returns 0, or P2 has won the game and returns 1, or neither of them (a tie) and returns 2.
	    for (int i = 0; i < 3; i++) {
		    if (x[i][0] + x[i][1] + x[i][2] == 3 || x[0][i] + x[1][i] + x[2][i] == 3 || x[0][0] + x[1][1] + x[2][2] == 3 || x[0][2] + x[1][1] + x[2][0] == 3) { //Three 'X's means a sum of 3, since X corresponds to 1
                return 1;
		    }
		    else if (x[i][0] + x[i][1] + x[i][2] == -3 || x[0][i] + x[1][i] + x[2][i] == -3 || x[0][0] + x[1][1] + x[2][2] == -3 || x[0][2] + x[1][1] + x[2][0] == -3) { //Three 'O's means a sum of 0, since O corresponds to 0
			    return -1;
		    }
		    else {
			    return 0;
		    }
	    }
    }

    bool checkFull(int board[][3]){ // Check if the board is already full or not
        if (countEmptyBoxes(board) == 0)
            return true;
        return false;
    }


    void makeMove(Player player,  int position, int board[][3]){ // Make the move for either human or computer
        if (player.getLetter() == 'X' && board[returnY(position)][returnX(position)] == 0){
            board[returnY(position)][returnX(position)] = 1;
            cout << "Human chose position "<< position << endl;
        }
        else if (player.getLetter() == 'O' && board[returnY(position)][returnX(position)] == 0){
            board[returnY(position)][returnX(position)] = -1;
            cout << "Computer chose position " << position << endl;
        }
        this->totalTurns --;
    }

    void play(){
        welcome(); // welcome statement and introduction board

        while (this->totalTurns > 0){
            int position;
            if (totalTurns % 2 != 0){
                cout << "Human please enter position (0 - 8): ";
                cin >> position;
                makeMove(human, position, board);
                printBoard(board);
            }
            else{
                position = computerPlay(board); 
                makeMove(computer, position, board);
                printBoard(board);
            }
        }
    }

    int countEmptyBoxes(int board[][3]){
        int emptyBox = 0;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (board[i][j] == 0)
                    emptyBox++;
            }
        }
        return emptyBox;
    }

    int utilityFunction(int board[][3]){ // Calculate the utility function's value
        return checkPlayerWin(board)*(countEmptyBoxes(board)+1);
    }

    int computerPlay(int board[][3]){
        int max = 0;
        int min = 0;
        if (checkWin(board) && checkFull(board)){
            if (countEmptyBoxes(board) % 2 == 0){ // human's turn -> find min

            }
            else if (countEmptyBoxes(board) % 2 != 0){ // computer's turn -> find max

            }
        }
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){

            }
        }
    }

    void welcome(){
        cout<<"Let's play Tic Tac Toe!"<<endl;
        cout<<" 0 | 1 | 2 \n 3 | 4 | 5 \n 6 | 7 | 8 "<<endl; 
    }

    int returnX(int position){ // Convert from position to x coordinate
        return position % 3;
    }

    int returnY(int position){ // Convert from position to y coordinate
        return (int)(position / 3);
    }


};
