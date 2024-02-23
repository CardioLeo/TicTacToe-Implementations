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
bool game_over = false;
bool three_in_a_row = false; // variable for algorithm to return later

char test_char = '~';
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
	cout << "draw_board()\n";
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


void find_three_in_a_row(){
	int array_values = 0;
	switch(array_values){
		case '1': // three across top
			if (array_values == 1){
				cout << "The three across the top are a match!\n";
			}
		case '2': // three across middle
			if (array_values == 2){
                                cout << "The three across the middle are a match!\n";
                        }
		case '3': // three across bottom
			if (array_values == 3){
                                cout << "The three across the bottom are a match!\n";
                        }
		case '4': // three down on left
			if (array_values == 4){
                                cout << "The three down on the left are a match!\n";
                        }
		case '5': // three down on middle
			if (array_values == 5){
                                cout << "The three down on the middle are a match!\n";
                        }
		case '6': // three down on right
			if (array_values == 6){
                                cout << "The three down on the right are a match!\n";
                        }
		case '7': // three diagonal, top left to bottom right
			if (array_values == 7){
                                cout << "The three diagonal, top left to bottom right, are a match!\n";
                        }
		case '8': // three diagonal, bottom left to top right
			if (array_values == 8){
                                cout << "The three diagonal, bottom left to top right, are a match!\n";
                        }
	        case '9': // no winning combination found; game continues
                        if (array_values == 0){
                                cout << "No winning combination found! Game continues\n";
                        }
	}
}

void win_check(){
        switch(round_counter){
		case 'p': // game is in play
			if (round_counter <= 9){
	                	game_over = false;
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
                cout << "If the game is over, the following value will be 1: " << game_over << "\n";
                cout << "If the algorithm has found a winner, the following value will be 1: " << three_in_a_row << "\n";
}

void change_mark(){
        char mark;
        if (player_one_turn == true){
                mark = 'X';
                cout << "Player mark is " << mark << "\n";
        } else {
                mark = 'O';
                cout << "Player mark is " << mark << "\n";
        }
}

void change_turn(){
	cout << "change_turn()\n";
	if (round_counter % 2 == 1){
		player_one_turn = true;
		player_two_turn = false;
		cout << "player one's turn is " << player_one_turn << "\n";
		cout << "player two's turn is " << player_two_turn << "\n";
	} else {
		player_one_turn = false;
        	player_two_turn = true;
		cout << "player one's turn is " << player_one_turn << "\n";
                cout << "player two's turn is " << player_two_turn << "\n";
	}
change_mark();
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
		if (round_counter >= 3) {
			three_in_a_row = true;
			cout << "The algorithm has found a winner!\n\n";
		}
        }
	}
}

int main(){

	play_game();

return 0;
}
