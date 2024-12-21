#include<iostream>
#include<array>
#include<limits>
using namespace std;

class Board {
	private:
		std::array<char, 9> board_spots = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

		bool attempt_to_fill_spot(int spot){
			char b_s = board_spots[spot-1]; // I'm purely making this var to make
							// the rest of this function easier
							// to read
			if (b_s == 'X' || b_s == 'O'){
				cout << "\nThis spot has already been filled!\n\nPlease choose anothere spot.\n";
				this->ask_for_new_spot();
				return false;
			}
			b_s == spot; // this probably isn't specific enough, since it will
				     // need to make the mark, not the spot....
				     // so I need to make Board ask Player for the mark...
			return true;
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
		
		bool ask_for_new_spot(){
			return false;
		} // this one function can probably be used to signal to the Game_Data class
		  // both that a decrement is needed, and to the Player class that a new
		  // input is needed
		  // also, notice the simplicity of this function versus the
		  // ask_round_to_decrement function; this is better
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
				cout << "The Game is not yet over; keep playing\n";
			}
		}

		// round info follows here:

		void last_round_check(){
			if (this->current_round >= 9){
				cout << "\n\nLast Round!\n\n\n";
			}
		}
		void tell_current_round(){
			cout << "The current round is: " << this->current_round << "\n\n";
			this->last_round_check();
		}
		void increment_round(){
			this->current_round++;
		}
		void display_round_info(){
			this->tell_current_round();
			this->increment_round();
		}
        public:
		void display_info(){
			this->is_game_over();
			this->display_round_info();
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

		char mark = 'Y';
		int play_again_input = 0;
		int spot_to_fill = 0;
		bool is_round_odd = true;
		std::array<int, 9> spots_already_tried = {};

		// class methods

		void say_invalid(){
			cout << "\nHm, looks like you pressed some key that isn't valid....\n\nPlease try again\n\n" << endl;
		}

		bool spot_full_check(int spot){
			if (this->spots_already_tried[spot-1] == spot){
				cout << "\nThat spot has already been taken!\n\n";
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
				// must reduce turn counter if false
				return false;
			} else if (spot <= 0 || spot >= 10){
				cout << "\nPlease only enter a number between 1 and 9.\n";
				return false;
			} else if (spot_is_full == true){
				return false;
			} else if (spot_is_full == false){
				this->spots_already_tried[spot-1] = spot;
			}
			return true;
		}

 		int get_spot_to_fill(){
                        int spot = 0;
                        cin >> spot;
			int retake = this->check_input(spot);
			if (retake == false){
				get_spot_to_fill();
			}
                        return spot;
                }
		void announce_turn(){
			cout << "It is now time to pick a move...\n";
		}

	public:
		void compare_round_with_bool(int current_round){
			if (current_round % 2 == 1){
				this->is_round_odd = true;	
			}
		}
		int move(){
				this->announce_turn();
				spot_to_fill = this->get_spot_to_fill();
				// pass spot to board
				return spot_to_fill;
			}
			/* bool spot_error_received(bool error){
					
			} */
	 	void change_turn(int round){
                        if (round % 2 == 1){
                                this->mark = 'X';
                        } else {
                                this->mark = 'O';
                        }
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
		this_game.display_info();
		// create a struct of 3-5 values or something
		// which the board, player, & game pass between each other?
		// or am I thinking effectively of a global variable again
		player.move();
		// player.error_check_and_info_pass();
		board.draw_board();
		int round = this_game.give_round();
		player.change_turn(round);
		// board.error_check_and_info_pass();
		// board.find_three_in_a_row();
		// this_game.change_turn();
	};

	return 0;
}
