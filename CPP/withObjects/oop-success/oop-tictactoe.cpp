/*
 * Author: William Z Chadwick
 * Date Created: 12/20/2024
 * Date Modified: 12/21/2024
 * Description: Basic OOP TicTacToe Implementation in C++
 * Usage: 
 */

#include<iostream>
#include<array>
#include<limits>
using namespace std;

class Board {
	private:
		// class data members
	
		array<char, 9> board_spots = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
		array<array<int, 3>, 8> winning_rows = {
			{
				{0, 1, 2},
				{3, 4, 5},
				{6, 7, 8},
				{0, 3, 6},
				{1, 4, 7},
				{2, 5, 8},
				{0, 4, 8},
				{2, 4, 6}
			}
		};
		char mark;
		int spot;
		bool winning_row_found = false;

		// class methods
		
		void fill_spot(){
			board_spots[spot-1] = mark; 
		}
		void announce_three_in_a_row(){
			cout << "That's three in a row!\n\n Player " << mark << " wins!\n" << endl;
		}
                bool send_win_to_Game_Data(){
                        return winning_row_found;
                }
		bool look_for_winning_rows(bool main_game_over){
			int temp1, temp2, temp3;
			for (int i = 0; i < 8; i++){
				temp1 = winning_rows[i][0];
				temp2 = winning_rows[i][1];
				temp3 = winning_rows[i][2];
				if (board_spots[temp1] == board_spots[temp2] && board_spots[temp2] == board_spots[temp3]){
					this->announce_three_in_a_row();
					this->winning_row_found = true;
					return winning_row_found;
				}
			}
			cout << endl;
			return false;
		}

	public:

		bool draw_board(){
                        cout << "\n\n     |     |     \n";
                        cout << "  " << this->board_spots[0] << "  |  " << this->board_spots[1] << "  |  " << this->board_spots[2] << "  \n";
                        cout << "_____|_____|_____\n";
                        cout << "     |     |     \n";
                        cout << "  " << this->board_spots[3] << "  |  " << this->board_spots[4] << "  |  " << this->board_spots[5] << "  \n";
                        cout << "_____|_____|_____\n";
                        cout << "     |     |     \n";
                        cout << "  " << this->board_spots[6] << "  |  " << this->board_spots[7] << "  |  " << this->board_spots[8] << "  \n";
                        cout << "     |     |     \n\n\n";
			return look_for_winning_rows(winning_row_found);
                }
		void test_mark(char mark, int move){
			this->mark = mark;
			this->spot = move;
			this->fill_spot();
		}
};

class Game_Data {
        private:
		
		// data members
		
		bool game_over = false;
		int current_round = 1;
		
		// class methods

		// round related methods follow here:

		void last_round_check(){
			if (this->current_round >= 9){
				cout << "\n\nLast Round!\n\n\n";
			}
		}
		void tell_current_round(){
			cout << "The current round is: " << this->current_round << "\n\n";
			this->last_round_check();
		}
		void tell_player_mark(char mark){
			cout << "The current turn is: " << mark << endl;
		}
		void increment_round(){
			this->current_round++;
		}
		void display_round_info(char mark){
			this->tell_current_round();
			this->tell_player_mark(mark);
			this->increment_round();
		}
		
		// methods for announcing game over & for receiving the bool
		// passed from the board object, here
		
                void receive_game_over(bool main_game_over){
                        if (main_game_over == true){
                                this->game_over == true;
                        }
                }
        public:
		void display_info(char mark){
			this->display_round_info(mark);
		}

		bool win_check(bool main_game_over){
			receive_game_over(main_game_over);
			if (this->game_over || this->current_round >= 10){
				return true;
			}
			return false;
		}

		int give_round(){
			return current_round;
		}
};

class Player {
	private:

		// data members

		char mark;
		int play_again_input = 0;
		int spot = 0;
		bool is_round_odd = true;
		std::array<int, 9> spots_already_tried = {};

		// class methods

		void say_invalid(){
			cout << "Hm, looks like you pressed some key that isn't valid....\nPlease try again\n" << endl;
		}

		bool spot_full_check(int spot){
			if (this->spots_already_tried[spot-1] == spot){
				cout << "That spot has already been taken!\n";
				return true;
			}
			return false;
		}
		bool check_input(int spot){
			bool spot_is_full = this->spot_full_check(spot);
			if (cin.fail()){
				this->say_invalid();
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				return false;
			} else if (spot <= 0 || spot >= 10){
				cout << "Please only enter a number between 1 and 9.\n";
				return false;
			} else if (spot_is_full == true){
				return false;
			} else if (spot_is_full == false){
				this->spots_already_tried[spot-1] = spot;
			}
			return true;
		}

 		int get_spot_to_fill(){
                        cin >> this->spot;
			int retake = this->check_input(spot);
			if (retake == false){
				get_spot_to_fill();
			}
                        return spot;
                }

	public:
		int move(){
				spot = this->get_spot_to_fill();
				// pass spot to board
				return spot;
			}
	 	char change_turn(int round){
                        if (round % 2 == 1){
				this->mark = 'X';
                        } else {
                                this->mark = 'O';
                        }
			return mark;
                }
};

int main(){
	
	// initializing objects
	
	Board board;
	Game_Data this_game;
	Player player;

	// game play	
	
	bool is_game_over = false;
	board.draw_board();
	while (is_game_over == false){
		int round = this_game.give_round();
		char mark = player.change_turn(round);
		this_game.display_info(mark);
		int move = player.move();
		board.test_mark(mark, move);
		is_game_over = board.draw_board();
		this_game.win_check(is_game_over);
	};

	return 0;
}
