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
Pyramid_X_O_Board::Pyramid_X_O_Board () {
    n_rows = 3;
    board = new char*[n_rows];  // make three rows
    int cells = 1;  // cells = number of columns
    for (int i = 0; i < n_rows; ++i) {
        board[i] = new char[cells];  // assign columns
        for (int j = 0; j < cells; ++j)
            board[i][j] = 0;
        cells += 2;  // first column is 1, then 3, then 5
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Pyramid_X_O_Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    // 0 <= x >= 2   0 <= y >= 4 and y < x*2
    if (!(x < 0 || x > 2 || y < 0 || y > 4 || y > x*2) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

// Display the board and the pieces on it
void Pyramid_X_O_Board::display_board() {
    int cells = 1;
    int indent = 2;
    vector<string> lines = {"\n\t\t---------", "\n\t-------------------------", "\n------------------------------------------"};
    int index_lines = 0;
    for (int i = 0; i < 3; ++i) {
        cout << "\n";
        for (int k = 0; k < indent; ++k)
            cout << "\t";
        indent--;
        cout << "|";
        for (int j = 0; j < cells; ++j) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << "|";
        }
        cout << lines[index_lines++];
        cells += 2;
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool Pyramid_X_O_Board::is_winner() {
    int x = 1, y = 0;
    char ref = board[0][0];
    bool flag = false;
    for (int i = 0; i < 2; ++i) {
        if (board[x][y] && ref == board[x][y]) {
            flag = true;
        } else {
            flag = false;
            break;
        }
        x++;
    }
    if (flag)
        return true;

    x = 1, y = 2;
    for (int i = 0; i < 2; ++i) {
        if (board[x][y] && ref == board[x][y]) {
            flag = true;
        } else {
            flag = false;
            break;
        }
        x++;
        y += 2;
    }
    if (flag)
        return true;

    x = 1, y = 1;
    for (int i = 0; i < 2; ++i) {
        if (board[x][y] && ref == board[x][y]) {
            flag = true;
        } else {
            flag = false;
            break;
        }
        x++;
        y++;
    }
    if (flag)
        return true;

    x = 1, y = 1;
    ref = board[1][0];
    for (int i = 0; i < 2; ++i) {
        if (board[x][y] && ref == board[x][y]) {
            flag = true;
        } else {
            flag = false;
            break;
        }
        y++;
    }
    if (flag)
        return true;

    int k = 0;
    x = 2;
    for (int i = 0; i < 3; ++i) {
        ref = board[2][k];
        k++;
        y = k;
        for (int j = 0; j < 2; ++j) {
            if (board[x][y] && ref == board[x][y]) {
                flag = true;
            } else {
                flag = false;
                break;
            }
            y++;
        }
        if (flag)
            return true;
    }

    return flag;
}

// Return true if 9 moves are done and no winner
bool Pyramid_X_O_Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool Pyramid_X_O_Board::game_is_over () {
    return n_moves >= 9;
}

Pyramid_X_O_Board::~Pyramid_X_O_Board() {
    for (int i = 0; i < n_rows; ++i) {
        delete[] board[i];
    }
    delete[] board;
    board = nullptr;
}
