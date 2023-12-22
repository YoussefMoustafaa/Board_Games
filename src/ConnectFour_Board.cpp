// Class definition for X_O_Board class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

// Set the board
ConnectFour_Board::ConnectFour_Board () {
    n_rows =6;
    n_cols = 7;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool ConnectFour_Board::update_board (int x, int y, char mark){
    // Only update if move is valid
//    cout<<board[x][y]<<endl;
//
    if (!(x < 0 || x > 5|| y < 0 || y > 6) && (board[x][y] == 0) ) {
//        if(x==5){
//            board[x][y] = toupper(mark);
//            n_moves++;
//            return true;
//        }
//        else if (board[x+1][y]){
//            board[x][y] = toupper(mark);
//            n_moves++;
//            return true;
//        }
//    }
        if(x== 5) { board[x][y] = toupper(mark);
            n_moves++;
            return true;
        }
        for(int i = 1; x + i < 6 ; i ++){
            if(board[x+i][y] != 0){
                board[x+i-1][y] = toupper(mark);
                n_moves++;
                return true;
            }
            if(x+i ==5 && board[5][y]== 0){
                board[5][y] = toupper(mark);
                n_moves++;
                return true;
            }

        }
    }
    else
        return false;
}


// Display the board and the pieces on it
void ConnectFour_Board::display_board() {
    for (int i: {0,1,2,3,4,5}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4,5,6}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------------------------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool ConnectFour_Board::is_winner() {
    for(int i = 0 ; i < 6 ; i ++){
        for (int j = 0; j < 7; ++j) {
            bool w = 0 , x = 0, y = 0, z= 0;
            if((i +3) < 6){
                x = (board[i][j] == board[i+1][j] && board[i][j] == board[i+2][j] && board[i][j] == board[i+3][j]) && ((i +3) < 6) && (board[i][j] !=0);
//                if(x){
//                    cout<<"x"<<endl;
//                    cout<<i<<" "<<j<<endl;
//                    cout<<board[i][j]<<" " << board[i+1][j]<<" " << board[i+2][j]<<" " << board[i+3][j];
//                    cout<<endl<<endl<<endl;
//                }
            }
            if((j +3) < 7){
                y = (board[i][j] == board[i][j+1] && board[i][j] ==  board[i][j+2] && board[i][j] ==   board[i][j+3]) && ((j +3) < 7) && (board[i][j+3] !=0);
//                if(y){
//                    cout<<"y";
//                    cout<<board[i][j]<<" " << board[i][j+1]<<" " << board[i][j+2]<<" " << board[i][j+3];
//                    cout<<endl<<endl<<endl;
//                }
            }
            if((j +3) < 7 && (i +3) <6 ){
                z = (board[i][j] == board[i+1][j+1] && board[i][j] ==  board[i+2][j+2] && board[i][j] ==   board[i+3][j+3])&& ((j +3) < 7 && (i +3) <6 ) && (board[i][j] !=0);
//                if(z){
//                    cout<<"z";
//                    cout<<board[i][j]<<" " << board[i+1][j+1]<<" " << board[i+2][j+2]<<" " << board[i+3][j+3];
//                    cout<<endl<<endl<<endl;
//                }
            }
            if((j +3 ) <7 && (i -3) >=0){
                w =  (board[i][j] == board[i-1][j+1] && board[i][j] ==  board[i-2][j+2] && board[i][j] ==   board[i-3][j+3])&& ((j +3) < 7 && (i -3) >=0 ) && (board[i][j] !=0);
//                if(w) cout<<w<<endl<<endl;
            }
            if(w || x || y ||z){
                return true;
            }
//            else if((board[i][j] == board[i][j+1] == board[i][j+2] == board[i][j+3])&& ((j +3) < 7) && (board[i][j] !=0) ){
//                return true;
//            }
//            else if((board[i][j] == board[i+1][j+1] == board[i+2][j+2] == board[i+3][j+3])&& ((j +3) < 7 && (i +3) < 6) && (board[i][j] !=0) ){
//                return true;
//            }
//            else if((board[i][j] == board[i-1][j-1] == board[i-2][j-2] == board[i-3][j-3])&& ((j -3) >=0 && (i -3) >=0) && (board[i][j] !=0) ){
//                return true;
//            }

        }
    }
    return false;
}

// Return true if 9 moves are done and no winner
bool ConnectFour_Board::is_draw() {
    return (n_moves == 42 && !is_winner());
}

bool ConnectFour_Board::game_is_over () {
    return n_moves >=42;
}
