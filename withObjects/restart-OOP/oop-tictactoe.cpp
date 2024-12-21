#include<iostream>
#include<array>
#include<limits>
using namespace std;

class Board {
	private:
		std::array<char, 9> board_spots = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

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

		// class methods

		void say_invalid(){
			cout << "\nHm, looks like you pressed some key that isn't valid....\n\nPlease try again\n\n" << endl;
		}

		bool check_input(int spot){
			if (cin.fail()){
				this->say_invalid();
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				// must reduce turn counter if false
				return false;
			}
			return true;
		}

		bool ask_round_to_decrement(int retake){
			if (retake == false){
				return false;
			}
			return true;
		} // I may not even need this function, actually, since I made
		  // get_spot_to_fill self-reflexive and the round doesn't even
		  // unnecesarily increment, hence doesn't need to be decremented...
		  // I probably need to add this function to Board, though, for when
		  // the input passed out from get_spot_to_fill doesn't fit with
		  // the board data

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
		void move(){
				this->announce_turn();
				this->get_spot_to_fill();
				// pass spot to board
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
