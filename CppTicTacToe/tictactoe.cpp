/*
 * Author: William Z Chadwick
 * Date Created: 02/22/2024
 * Date Modified:
 * Description: A basic implementation of Tic Tac Toe
 * Usage:
 */

#include<iostream>
using namespace std;

int round_counter = 0;

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
	cout << "Below are three rows across: 1, 2, and 3,\nand three columns down: a, b, and c.\nPlayer inputs row and column together in the format:\nb2\n";
	cout << "\n\n";
       	cout << "     |     |     \n";
	cout << "  " << a1 << "  |  " << a2 << "  |  " << a3 << "  \n";
	cout << "_____|_____|_____\n";
	cout << "     |     |     \n";
        cout << "  " << b1 << "  |  " << b2 << "  |  " << b3 << "  \n";
	cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
	cout << "  " << c1 << "  |  " << c2 << "  |  " << c3 << "  \n";
	cout << "     |     |     \n";
	cout << "\n\n";
}

void change_turn(){
	bool player_one_turn = true;
	bool player_two_turn = false;
	if (round_counter % 2 == 1){
		player_one_turn = false;
		player_two_turn = true;
		cout << "\nplayer one's turn is " << player_one_turn << "\n";
		cout << "\nplayer two's turn is " << player_two_turn << "\n";
	} else {
		player_one_turn = true;
        	player_two_turn = false;
		cout << "\nplayer one's turn is " << player_one_turn << "\n";
                cout << "\nplayer two's turn is " << player_two_turn << "\n";
	}
}

void play_game(){
	{
	bool win_check = false;
	while (round_counter <= 2) {
                cout << "while(win_check == false){\n";
                cout << "       draw_board()\n";
		draw_board();
                cout << "       win_check()\n";
                cout << "       change_turn()\n";
		change_turn();
                cout << "       player_move()\n";
                cout << "}\n";
                cout << "return 0\n";
                cout << win_check << "\n";
                win_check = true;
		cout << "round_counter is " << round_counter << "\n";
		round_counter++;
		cout << win_check << "\n";
                // print(win_check);
        }
	}
}

int main(){

	play_game();

return 0;
}
