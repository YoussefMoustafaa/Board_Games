#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

X_O_fivegrid_Board::X_O_fivegrid_Board() {
    n_rows = n_cols = 5;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
bool X_O_fivegrid_Board::update_board (int x, int y,char mark) {
        // Only update if move is valid
        if (!(x < 0 || x > 5 || y < 0 || y > 5) && (board[x][y] == 0)) {
            board[x][y] = toupper(mark);
            n_moves++;
            return true;
        }
        else
            return false;
    }

void X_O_fivegrid_Board::display_board(){
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-------------------------------------------------";
    }
    cout << endl;
}
bool X_O_fivegrid_Board::is_winner() {
    if(n_moves != 24)
        return false;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; ++j) {
            bool row = 0, col = 0, diag_up = 0, diag_down = 0;

            if ((i + 2) < 5) {
                row = board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j];
                if (row) {
                    if (board[i][j] == 'X')
                        count_x++;
                    else
                        count_y++;
                }
            }
            if ((j + 2 < 5)) {
                col = board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2];
                if (col) {
                    if (board[i][j] == 'X')
                        count_x++;
                    else
                        count_y++;
                }
            }
            if ((j + 2) < 5 && (i + 2) < 5) {
                diag_up = board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i+2][j + 2];
                if (diag_up) {
                    if (board[i][j] == 'X')
                        count_x++;
                    else
                        count_y++;
                }
            }


            if ((j + 2) < 5 && (i - 2) >= 0) {
                diag_down = board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2];
                if (diag_down) {
                    if (board[i][j] == 'X')
                        count_x++;
                    else
                        count_y++;
                }
            }
        }
    }
//    cout << count_x;
//    cout << count_y;
  if(count_x > count_y)
      cout << "X wins" << endl;
  else if (count_x < count_y)
      cout << "O wins" << endl;
    return false;
}

bool X_O_fivegrid_Board::is_draw(){
    return (n_moves == 24 && count_x == count_y);
}
bool X_O_fivegrid_Board::game_is_over(){
    return n_moves == 24;
}