// Class definition for XO_App class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI Board Games. :)\n";
    int game_number;


    while (true) {
        cout << "\nChoose a Game:\n";
        cout << "1) X_O Game\n"
                "2) Pyramid X_O Game\n"
                "3) Connect Four Game\n"
                "4) 5x5 X_O Game\n"
                "0) Exit\n";
        cin >> game_number;
        if (game_number == 1) {
            cout << "\nWelcome to X_O Game.\n";
            cout << "Press 1 if you want to play with computer: ";
            cin >> choice;
            if (choice != 1)
                players[1] = new Player(2, 'o');
            else
                //Player pointer points to child
                players[1] = new RandomPlayer('o', 3, 3);

            GameManager x_o_game(new X_O_Board(), players);
            x_o_game.run();
        }
        else if (game_number == 2) {
            cout << "\nWelcome to Pyramid X_O Game.\n";
            cout << "Press 1 if you want to play with computer: ";
            cin >> choice;
            if (choice != 1)
                players[1] = new Player(2, 'o');
            else
                //Player pointer points to child
                players[1] = new RandomPlayer('o', 3, 4);

            GameManager pyramid_x_o(new Pyramid_X_O_Board(), players);
            pyramid_x_o.run();
        }
        else if (game_number == 3) {
            cout << "\nWelcome to Connect Four Game.\n";
            cout << "Press 1 if you want to play with computer: ";
            cin >> choice;
            if (choice != 1)
                players[1] = new Player (2, 'o');
            else
                //Player pointer points to child
                players[1] = new RandomPlayer ('o', 6 , 7);

            GameManager connectFour (new ConnectFour_Board(), players);
            connectFour.run();
        }
        else if (game_number == 4) {
            cout << "\nWelcome to 5x5 X_O Game.\n";
            cout << "Press 1 if you want to play with computer: ";
            cin >> choice;
            if (choice != 1)
                players[1] = new Player (2, 'o');
            else
                //Player pointer points to child
                players[1] = new RandomPlayer ('o', 5 , 5);

            GameManager five_grid_game (new X_O_fivegrid_Board(), players);
            five_grid_game.run();
        }
        else
            break;
    }

    system("pause");
}
