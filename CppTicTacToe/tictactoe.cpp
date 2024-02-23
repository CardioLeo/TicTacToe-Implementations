/*
 * Author: William Z Chadwick
 * Date Created: 02/22/2024
 * Date Modified:
 * Description: A basic implementation of Tic Tac Toe
 * Usage:
 */

#include<iostream>
using namespace std;

char test_char = 'A';
char a1 = test_char;
char a2 = test_char;
char a3 = test_char;
char b1 = test_char;
char b2 = test_char;
char b3 = test_char;
char c1 = test_char;
char c2 = test_char;
char c3 = test_char;

void draw_board(){
	cout << "\n\n";
	cout << "   |   |   \n";
	cout << "___|___|___\n";
        cout << "   |   |   \n";
        cout << "___|___|___\n";
        cout << "   |   |   \n";
        cout << "   |   |   \n";
	cout << "\n\n";
	cout	<< a1 << "\n"
		<< a2 << "\n"
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
        int win_check_count = 0;
	while (win_check_count <= 2) {
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
		cout << "win_check_count is " << win_check_count << "\n";
		win_check_count++;
		cout << win_check << "\n";
                // print(win_check);
        }
	}
}

int main(){

	play_game();

return 0;
}
