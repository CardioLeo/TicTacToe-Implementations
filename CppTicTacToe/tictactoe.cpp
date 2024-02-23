/*
 * Author: William Z Chadwick
 * Date Created: 02/22/2024
 * Date Modified:
 * Description: A basic implementation of Tic Tac Toe
 * Usage:
 */

#include<iostream>
using namespace std;

char a1 = 'A';
char a2 = 'A';
char a3 = 'A';
char b1 = 'A';
char b2 = 'A';
char b3 = 'A';
char c1 = 'A';
char c2 = 'A';
char c3 = 'A';

void draw_board(){
	cout << "\n\n";
	cout << "   |   |   \n";
	cout << "___|___|___\n";
        cout << "   |   |   \n";
        cout << "___|___|___\n";
        cout << "   |   |   \n";
        cout << "   |   |   \n";
	cout << "\n\n";
	cout	<< a1 << "\n";
	cout 	<< a2 << "\n"
		<< a3 << "\n"
		<< b1 << "\n"
		<< b2 << "\n"
		<< b3 << "\n"
		<< c1 << "\n"
		<< c2 << "\n"
		<< c3 << "\n";
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
