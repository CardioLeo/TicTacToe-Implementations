/*
 * Author: William Z Chadwick
 * Date Created: 02/22/2024
 * Date Modified:
 * Description: A basic implementation of Tic Tac Toe
 * Usage:
 */

#include<iostream>
using namespace std;

int main(){
bool win_check = false;
while (win_check == false) {
	cout << "while(win_check == false){\n";
	cout << "	draw_board()\n";
	cout << "	win_check()\n";
	cout << "	change_turn()\n";
        cout << "	player_move()\n";
        cout << "}\n";
	cout << "return 0\n";
	cout << win_check;
	win_check = true;
	cout << win_check;
}
return 0;
}
