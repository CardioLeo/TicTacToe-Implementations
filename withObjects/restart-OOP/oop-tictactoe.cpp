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
		std::array<char, 9> board_spots = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

		char mark;
		int spot;
		void fill_spot(){
			board_spots[spot-1] = mark; 
		}

	public:
		void draw_board(){
                        cout << "\n\n     |     |     \n";
                        cout << "  " << this->board_spots[0] << "  |  " << this->board_spots[1] << "  |  " << this->board_spots[2] << "  \n";
                        cout << "_____|_____|_____\n";
                        cout << "     |     |     \n";
                        cout << "  " << this->board_spots[3] << "  |  " << this->board_spots[4] << "  |  " << this->board_spots[5] << "  \n";
                        cout << "_____|_____|_____\n";
                        cout << "     |     |     \n";
                        cout << "  " << this->board_spots[6] << "  |  " << this->board_spots[7] << "  |  " << this->board_spots[8] << "  \n";
                        cout << "     |     |     \n\n\n";
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

		void is_game_over(){
			if (this->game_over == true){
				cout << "The Game is now over\n";
			} else {
				cout << "Keep playing\n";
			}
		}

		// round info follows here:

		void last_round_check(){
			if (this->current_round >= 9){
				cout << "\n\nLast Round!\n\n\n";
			}
		}
		void tell_current_round(){
			cout << "The current round is: " << this->current_round << "\n";
			this->last_round_check();
		}
		void tell_player_mark(char mark){
			cout << "The current mark is: " << mark << endl;
		}
		void increment_round(){
			this->current_round++;
		}
		void display_round_info(char mark){
			this->tell_current_round();
			this->tell_player_mark(mark);
			this->increment_round();
		}
        public:
		void display_info(char mark){
			this->is_game_over();
			this->display_round_info(mark);
		}

		bool win_check(){
			return (this->game_over || this->current_round >= 10);
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
                void print_spots_already_tried(){
                        cout << "here are the spots you've already tried: ";
                        for (int i = 0; i < 9; i++){
                                cout << spots_already_tried[i] << " ";
                        }
                }

		void announce_choice(int spot){
			cout << "You put " << spot << endl;
			this->print_spots_already_tried();
		}
		bool check_input(int spot){
			bool spot_is_full = this->spot_full_check(spot);
			if (cin.fail()){
				this->say_invalid();
				this->announce_choice(spot);
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				return false;
			} else if (spot <= 0 || spot >= 10){
				cout << "Please only enter a number between 1 and 9.\n";
				this->announce_choice(spot);
				return false;
			} else if (spot_is_full == true){
				this->announce_choice(spot);
				return false;
			} else if (spot_is_full == false){
				this->spots_already_tried[spot-1] = spot;
				this->announce_choice(spot);
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
		void announce_turn(){
			cout << "It is now time to pick a spot...\n";
		}

	public:
		int move(){
				this->announce_turn();
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
	board.draw_board();
	while (this_game.win_check() == false){
		int round = this_game.give_round();
		char mark = player.change_turn(round);
		this_game.display_info(mark);
		int move = player.move();
		board.test_mark(mark, move);
		board.draw_board();
		// int round = this_game.give_round();
		// char mark = player.change_turn(round);
		// board.test_mark(mark);
		// board.find_three_in_a_row();
	};

	return 0;
}
