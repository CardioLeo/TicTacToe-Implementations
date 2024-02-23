/*
 * Author: William Z Chadwick
 * Date Created: 02/22/2024
 * Date Modified:
 * Description: A basic implementation of Tic Tac Toe
 * Usage:
 */

#include<iostream>
using namespace std;

int round_counter = 1;
bool player_one_turn = true;
bool player_two_turn = false;
char mark = 'X';
bool game_over = false;
bool three_in_a_row = false; // variable for algorithm to return later

char blank_spot = '~';
char a1 = blank_spot;
char a2 = blank_spot;
char a3 = blank_spot;
char b1 = blank_spot;
char b2 = blank_spot;
char b3 = blank_spot;
char c1 = blank_spot;
char c2 = blank_spot;
char c3 = blank_spot;

void draw_board(){
	cout << "draw_board()\n";
//	cout << "Below are three rows across: 1, 2, and 3,\nand three columns down: a, b, and c.\nPlayer inputs row and column together in the format:\nb2\n";
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


void find_three_in_a_row(){
	int array_values = 0;
	switch(array_values){
		case '1': // three across top
			if (a1 != '~' && a1 == a2 && a2 == a3){
				cout << "The three across the top are a match!\n";
				cout << "Player " << a1 << " wins!\n";
			}
		case '2': // three across middle
			if (b1 != '~' && b1 == b2 && b2 == b3){
                                cout << "The three across the middle are a match!\n";
				cout << "Player " << b1 << " wins!\n";
                        }
		case '3': // three across bottom
			if (c1 != '~' && c1 == c2 && c2 == c3){
                                cout << "The three across the bottom are a match!\n";
				cout << "Player " << c1 << " wins!\n";
                        }
		case '4': // three down on left
			if (a1 != '~' && a1 == b1 && b1 == c1){
                                cout << "The three down on the left are a match!\n";
				cout << "Player " << a1 << " wins!\n";
                        }
		case '5': // three down on middle
			if (a2 != '~' && a2 == b2 && b2 == c2){
                                cout << "The three down on the middle are a match!\n";
				cout << "Player " << a2 << " wins!\n";
                        }
		case '6': // three down on right
			if (a3 != '~' && a3 == b3 && b3 == c3){
                                cout << "The three down on the right are a match!\n";
				cout << "Player " << a3 << " wins!\n";
                        }
		case '7': // three diagonal, top left to bottom right
			if (a1 != '~' && a1 == b2 && b2 == c3){
                                cout << "The three diagonal, top left to bottom right, are a match!\n";
				cout << "Player " << a1 << " wins!\n";
                        }
		case '8': // three diagonal, bottom left to top right
			if (a3 != '~' && a3 == b2 && b2 == c1){
                                cout << "The three diagonal, bottom left to top right, are a match!\n";
				cout << "Player " << a3 << " wins!\n";
                        }
	        case '9': // no winning combination found; game continues
                        cout << "No winning combination found! Game continues\n";
	}
}

void win_check(){
        switch(round_counter){
		case 'p': // game is in play
			if (round_counter <= 9){
	                	game_over = false;
				find_three_in_a_row();
			}
		case 's': // tie or stalemate
			if (round_counter == 9 && three_in_a_row == false){
                		game_over = true; // because there is a tie or stalemate
				cout << "There has been a tie or a stalemate.\n";
			}
        	case 't': // three in a row algorithm has returned true
			if (three_in_a_row == true){
				game_over = true;
				cout << "A player has won by getting three marks in a row!";
			}
        }
                cout << "win_check()\n";
//                cout << "If the game is over, the following value will be 1: " << game_over << "\n";
//                cout << "If the algorithm has found a winner, the following value will be 1: " << three_in_a_row << "\n";
}

void display_turn(){
	cout << "It is " << mark << "'s turn\n";
}

void change_turn(){
	cout << "change_turn()\n";
	if (round_counter % 2 == 1){
	//	player_one_turn = true;
	//	player_two_turn = false;
                mark = 'X';
	} else {
	//	player_one_turn = false;
	//	player_two_turn = true;
                mark = 'O';
	}
display_turn();
}

void player_move(){
	cout << "player_move()\n";
}

void play_game(){
	{
	while (round_counter <= 3) {
                cout << "while(game_over == false) do\n";
		draw_board();
                win_check();
		change_turn();
                player_move();
                cout << "round_counter is " << round_counter << "\n";
		round_counter++;
		}
        }
}

int main(){

	play_game();

return 0;
}
