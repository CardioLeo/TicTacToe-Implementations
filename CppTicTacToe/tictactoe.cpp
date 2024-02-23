/*
 * Author: William Z Chadwick
 * Date Created: 02/22/2024
 * Date Modified:
 * Description: A basic implementation of Tic Tac Toe
 * Usage:
 */

#include<iostream>
using namespace std;

void draw_board(){
	cout << "\n\n";
	cout << "   |   |   \n";
	cout << "___|___|___\n";
        cout << "   |   |   \n";
        cout << "___|___|___\n";
        cout << "   |   |   \n";
        cout << "   |   |   \n";
	cout << "\n\n";
}

void play_game(){
	{
	bool win_check = false;
        while (win_check == false) {
                cout << "while(win_check == false){\n";
                cout << "       draw_board()\n";
		draw_board();
                cout << "       win_check()\n";
                cout << "       change_turn()\n";
                cout << "       player_move()\n";
                cout << "}\n";
                cout << "return 0\n";
                cout << win_check << "\n";
                win_check = true;
                cout << win_check << "\n";
                // print(win_check);
        }
	}
}

int main(){

	play_game();

return 0;
}
