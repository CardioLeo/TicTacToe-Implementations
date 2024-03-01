/*
 * Author: William Z Chadwick
 * Date Created: 02/22/2024
 * Date Modified: 03/01/2024
 * Description: A basic implementation of Tic Tac Toe
 * Usage:
 */

#include<iostream>
using namespace std;


// main global variables follow here

int round_counter = 1;
char mark = 'X';
bool game_over = false;
int spot_to_fill = 0; // for empty spots, until filled by player and used by player_move() and attempt_to_fill_spot()
char board_spots[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};


// function prototypes follow here

void draw_board();
void announce_three_in_a_row();
void round_limit_checker();
void display_info();
void find_three_in_a_row();
void change_turn();
void attempt_to_fill_spot();
void player_move();
void start_game();
void ask_to_play();
void play_again();
void reset_pregame_variables();


// function definitions follow here

void draw_board(){ // this function is fairly self-explanatory; it draws the board by referencing the values from the array, board_spots
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
}


void round_limit_checker(){
                cout << "Round Number: " << round_counter << "\n";
		if (round_counter > 9){
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
	// I call round_limit_checker with display_info
	// in large part because it logically and
	// chronologically belongs with display_info,
	// and so by calling it at the end of
	// display_info(), I can make the main loop
	// of start_game() much more legible, for one-
	// but another point here is that it increases
	// the ease of maintaining the code, because
	// if they were separated, and I had to move
	// one of them, and forgot to move the other
	// I could mess up the game_logic flow.
}

void find_three_in_a_row(){
		// this could really stand to be refactored;
		// preferably, I would refactor it by making
		// a data structure with sets of winning matches
		// or combinations, and then looping through them;
		// which would be less lines of code and likely
		// more readable, to say the least.
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

void attempt_to_fill_spot(){
// this function implements the logic for checking
// if the spot has already been marked, and then
// marking it, if appropriate; but I can't get
// it to stop going into an endless loop if you
// enter a letter rather than a number.
// I refactored to this function rather than having
// like 3-4 lines of code in player_move() for each
// of the possible spots to fill; I think this is
// both more slim and more readable, easier to edit.
	if (board_spots[spot_to_fill-1] == 'X' || board_spots[spot_to_fill-1] == 'O') {
		cout << "\nThis spot has already been filled!\n\nPlease choose another spot.\n";
		round_counter--;
		// because the input is found to be in error,
		// round_counter must be decremented so that
		// the erroneous input does not cause the
		// rounds to keep moving, and turns changing,
		// even when the input was incorrect.
	} else if (!(spot_to_fill > 0) || !(spot_to_fill <= 10)) {
	        cout << "\nPlease only enter a number between 1 and 9.\n";
	        round_counter--;
		// this particular conditional is important
		// for making sure users don't input numbers
		// below 1 or above 9.
	}/* else if (!(isalpha(spot_to_fill))) {
		cout << "\nYou did not enter a digit...\n\nEntering something other than a digit causes the game to fail... :(\n";
		round_counter--;
		game_over = true;
		// this conditional is supposed to stop the
		// user from entering a letter where they are
		// supposed to enter a number; but it doesn't
		// work, so it is commented out.
	}*/ else {
		board_spots[spot_to_fill-1] = mark;
		// this final conditional, having passed all
		// the other conditionals, implements actually
		// changing the mark to the mark of whoever's
		// turn it is.
	}
}

void player_move(){
	cout << "Player " << mark << ", Please select the spot to place your mark.\n";
	cin >> spot_to_fill;
	attempt_to_fill_spot();
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
		// play_again() doesn't work without resetting these values;
		// but I figure it is more legible to abstract this reset into it's own function
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
			// not sure why this way of validating input works here,
			// but not in the middle of start_game(); specifically
			// why does this make the game exit if a letter is typed in,
			// but it doesn't do the same thing if a letter is typed in
			// the middle of start_game()?
			// I think it might be cecause play_game() is the last
			// function to be called in main;
		}
	}
}

int main(){

	draw_board();
	start_game();
	play_again();

return 0;
}
