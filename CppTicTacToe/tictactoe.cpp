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
char mark = 'X';
bool game_over = false;
bool three_in_a_row = false; // variable for algorithm to return later

char blank_spot = '~';
int spot_to_fill = 0; // for empty, until filled by player and used by player_move()
char a1 = '1';
char a2 = '2';
char a3 = '3';
char b1 = '4';
char b2 = '5';
char b3 = '6';
char c1 = '7';
char c2 = '8';
char c3 = '9';

void round_limit_checker(){
                cout << "Round Number: " << round_counter << "\n";
		if (round_counter >= 9){
                        game_over = true;
			cout << "There are no more rounds.\n";
                }
                round_counter++;
}

void display_info(){
        cout << "Player Turn: " << mark << "\n";
	round_limit_checker();
}

void draw_board(){
	display_info();
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
	int array_values = 0; // a placeholder until I can use player input
	switch(array_values){
		case '1': // three across top
			if (a1 != '~' && a1 == a2 && a2 == a3){
				cout << "The three across the top are a match!\n";
				cout << "Player " << a1 << " wins!\n";
			}
			break;
		case '2': // three across middle
			if (b1 != '~' && b1 == b2 && b2 == b3){
                                cout << "The three across the middle are a match!\n";
				cout << "Player " << b1 << " wins!\n";
                        }
			break;
		case '3': // three across bottom
			if (c1 != '~' && c1 == c2 && c2 == c3){
                                cout << "The three across the bottom are a match!\n";
				cout << "Player " << c1 << " wins!\n";
                        }
			break;
		case '4': // three down on left
			if (a1 != '~' && a1 == b1 && b1 == c1){
                                cout << "The three down on the left are a match!\n";
				cout << "Player " << a1 << " wins!\n";
                        }
			break;
		case '5': // three down on middle
			if (a2 != '~' && a2 == b2 && b2 == c2){
                                cout << "The three down on the middle are a match!\n";
				cout << "Player " << a2 << " wins!\n";
                        }
			break;
		case '6': // three down on right
			if (a3 != '~' && a3 == b3 && b3 == c3){
                                cout << "The three down on the right are a match!\n";
				cout << "Player " << a3 << " wins!\n";
                        }
			break;
		case '7': // three diagonal, top left to bottom right
			if (a1 != '~' && a1 == b2 && b2 == c3){
                                cout << "The three diagonal, top left to bottom right, are a match!\n";
				cout << "Player " << a1 << " wins!\n";
                        }
			break;
		case '8': // three diagonal, bottom left to top right
			if (a3 != '~' && a3 == b2 && b2 == c1){
                                cout << "The three diagonal, bottom left to top right, are a match!\n";
				cout << "Player " << a3 << " wins!\n";
                        }
			break;
	        default: // no winning combination found; game continues
                        if (round_counter < 9){
				cout << "No winning combination found! Game continues\n";
			}
	}
}

void change_turn(){
	if (round_counter % 2 == 1){
                mark = 'X';
	} else {
                mark = 'O';
	}
}

void player_move(){
	cout << "Please select which spot you wish to place your mark in.\n";
	cin >> spot_to_fill;
	switch(spot_to_fill){
		case 1:
			a1 = mark;
			break;
		case 2:
			a2 = mark;
			break;
		case 3:
			a3 = mark;
			break;
		case 4:
			b1 = mark;
			break;
		case 5:
			b2 = mark;
			break;
		case 6:
			b3 = mark;
			break;
		case 7:
			c1 = mark;
			break;
		case 8:
			c2 = mark;
			break;
		case 9:
			c3 = mark;
			break;
	}
}

void play_game(){
	{
	while (game_over == false) {
		draw_board();
		find_three_in_a_row();
		change_turn();
                player_move();
		}
        }
}

int main(){

	play_game();

return 0;
}
