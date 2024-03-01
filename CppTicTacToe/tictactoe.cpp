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

int spot_to_fill = 0; // for empty, until filled by player and used by player_move()
char board_spots[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void draw_board();
void announce_three_in_a_row();
void round_limit_checker();
void display_info();
void find_three_in_a_row();
void change_turn();
void player_move();
void start_game();
void ask_to_play();
void play_again();
void reset_pregame_variables();


void draw_board(){
	cout << "\n\n";
       	cout << "     |     |     \n";
	cout << "  " << board_spots[0] << "  |  " << board_spots[1] << "  |  " << board_spots[2] << "  \n";
	cout << "_____|_____|_____\n";
	cout << "     |     |     \n";
        cout << "  " << board_spots[3] << "  |  " << board_spots[4] << "  |  " << board_spots[5] << "  \n";
	cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
	cout << "  " << board_spots[6] << "  |  " << board_spots[7] << "  |  " << board_spots[8] << "  \n";
	cout << "     |     |     \n";
	cout << "\n\n";
}

void announce_three_in_a_row(){
        cout << "That's three in a row!\n\nPlayer " << mark << " wins!\n";
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
	if (board_spots[0] == board_spots[1] && board_spots[1] == board_spots[2]) { // three across top
		announce_three_in_a_row();
	} else if (board_spots[3] == board_spots[4] && board_spots[4] == board_spots[5]) { // three across middle
        	announce_three_in_a_row();
	} else if (board_spots[6] == board_spots[7] && board_spots[7] == board_spots[8]) { // three across bottom
		announce_three_in_a_row();
	} else if (board_spots[0] == board_spots[3] && board_spots[3] == board_spots[6]) { // three down on left
        	announce_three_in_a_row();
	} else if (board_spots[1] == board_spots[4] && board_spots[4] == board_spots[7]) { // three down on middle
        	announce_three_in_a_row();
	} else if (board_spots[2] == board_spots[5] && board_spots[5] == board_spots[8]) { // three down on right
        	announce_three_in_a_row();
	} else if (board_spots[0] == board_spots[4] && board_spots[4] == board_spots[8]) { // three diagonal, top left to bottom right
		announce_three_in_a_row();
	} else if (board_spots[2] == board_spots[4] && board_spots[4] == board_spots[6]) { // three diagonal, bottom left to top right
        	announce_three_in_a_row();
	} else { // no winning combination found; game continues
                if (round_counter < 9){
			cout << "No wins yet!\n";
		} else if (round_counter > 9) {
			cout << "There are no turns left!\n\nI'm guessing this is a tie. Close game :)\n";
			game_over = true;
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
			board_spots[0] = mark;
			break;
		case 2:
			board_spots[1] = mark;
			break;
		case 3:
			board_spots[2] = mark;
			break;
		case 4:
			board_spots[3] = mark;
			break;
		case 5:
			board_spots[4] = mark;
			break;
		case 6:
			board_spots[5] = mark;
			break;
		case 7:
			board_spots[6] = mark;
			break;
		case 8:
			board_spots[7] = mark;
			break;
		case 9:
			board_spots[8] = mark;
			break;
		default:
                        cout << "Please only enter a number between 1 and 9.\n\nAll other input causes the game to exit!\n";
			game_over = true; // game over set to true so tha
					  // the game will not go through
					  // all 9 rounds without input,
					  // which is what happens when
					  // this default case becomes
					  // active, say because a user
					  // input a character like g or h
	}
}

void start_game(){
	while (game_over == false) {
		display_info();
                player_move();
		draw_board();
		find_three_in_a_row();
		change_turn();
	}
}

void ask_to_play(){
        cout << "\nI hope you had fun!\n\nWould you like to play again?\n\nIf you want to play again, press 1. If you're done, press 2.\n\n";
}

void reset_pregame_variables(){
	game_over = false;
	round_counter = 1;
	board_spots[0] = '1';
	board_spots[1] = '2';
	board_spots[2] = '3';
	board_spots[3] = '4';
	board_spots[4] = '5';
	board_spots[5] = '6';
	board_spots[6] = '7';
	board_spots[7] = '8';
	board_spots[8] = '9';
}

void play_again(){
	while (game_over = true){
		ask_to_play();
		int play_again_input = 0;
		cin >> play_again_input;
		if (play_again_input == 1){
			reset_pregame_variables();
			change_turn();
			cout << "\n\nHere we go again!\n" << endl; // uses endl to clear input buffer
			draw_board();
			start_game();
		} else if (play_again_input == 2){
			cout << "\nHave a great day!\n" << endl; // communicates to user that user is exiting
			game_over = false; // causes play_again loop to exit
			return;
		} else if (play_again_input != 1 || play_again_input != 2) {
			cout << "\nHm, looks like you pressed some key that isn't valid...\n\nUnfortunately this causes the game to exit\n\n" << endl;
			return;
		}
	}
}

int main(){

	draw_board();
	start_game();
	play_again();

return 0;
}
