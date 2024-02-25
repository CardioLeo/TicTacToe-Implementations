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

void draw_board(){
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

void announce_three_in_a_row(){
        cout << "That's three in a row!\n";
        cout << "Player " << mark << " wins!\n";
        game_over = true;
        // draw_board();
}


void round_limit_checker(){
                cout << "Round Number: " << round_counter << "\n";
		if (round_counter >= 9){
			game_over = true;
		}
                round_counter++;
}

void display_info(){
        if (round_counter == 9){
                cout << "\n\nLast round!\n\n\n";
        }
	cout << "Player Turn: " << mark << "\n";
	round_limit_checker();
}

void find_three_in_a_row(){
	if (a1 == a2 && a2 == a3) { // three across middle
		announce_three_in_a_row();
	} else if (b1 == b2 && b2 == b3) { // three across middle
        	announce_three_in_a_row();
	} else if (c1 == c2 && c2 == c3) { // three across bottom
		announce_three_in_a_row();
	} else if (a1 == b1 && b1 == c1) { // three down on right
        	announce_three_in_a_row();
	} else if (a2 == b2 && b2 == c2) { // three down on middle
        	announce_three_in_a_row();
	} else if (a3 == b3 && b3 == c3) { // three down on right
        	announce_three_in_a_row();
	} else if (a1 == b2 && b2 == c3) { // three diagonal, top left to bottom right
		announce_three_in_a_row();
	} else if (a3 == b2 && b2 == c1) { // three diagonal, bottom left to top right
        	announce_three_in_a_row();
	} else { // no winning combination found; game continues
                if (round_counter < 9){
			cout << "No wins yet!\n";
		} else if (round_counter > 9) {
			cout << "There are no turns left!\nI'm guessing this is a tie. Close game :)\n";
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
	cout << "Player " << mark << ", Please select the spot to place your mark.\n";
	cin >> spot_to_fill; // still need to validate input!
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
	//	default:
                        // if (spot_to_fill != [1-9]) {
                        //      cout << "Please only enter a number between 1 and 9.\n";
			// re-call player_move()? recursion?
                        // }
	}
}

void play_game(){
	while (game_over == false) {
		display_info();
                player_move();
		draw_board();
		find_three_in_a_row();
		change_turn();
	}
}

int main(){

	draw_board();
	play_game();

return 0;
}
