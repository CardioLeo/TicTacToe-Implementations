#include<iostream>
#include<array>
#include<limits>
using namespace std;

//
// // //
// temporary global variables
// // //
//
        // char mark1 = 'X';
        // char mark2 = 'O';
// // //


class Board {
        private:
                std::array<char, 9> board_spots = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
		bool found_three = false;
		char mark;
 		bool find_three_in_a_row(){
                        if (this->board_spots[0] == this->board_spots[1] && this->board_spots[0]
== this->board_spots[2]){
				return true;
			} else {
				return false;
			}


                }
        public:
                std::array<char,9> give_board_spots(){
                        return board_spots;
                }
		
		char give_one_spot(int request){
			return this->board_spots[request];
		}

		bool give_found_three(){
			return this->found_three;
		}
		
		void set_mark(char current_mark){
			this->mark = current_mark;
		}

		int attempt_to_fill(int request, char current_mark){
			this->mark = current_mark;
			if (this->board_spots[request-1] == 'X' || this->board_spots[request-1] == 'O'){
				cout << "\nThis spot has already been filled!\n\nPlease choose another spot.\n";
				return 1;
                        } else {
                                 this->board_spots[request-1] = mark;
				 return 0;
                        }
                }

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
}


                bool announce_three_in_a_row(){
			this->found_three = this->find_three_in_a_row();
			if (this->found_three){
                        	cout << "That's three in a row!\n\nPlayer " << this->mark << " wins!\n";
                        	return true; // this->game_over = true;
			} else {
				return false; // this->game_over = false;
			}
                        // this var needs to be in the game_details
                        // class.... hm. commenting out this code for now
                }
};

class Game_Details {
        public:
		// methods
		int give_round_count(){
			return this->round_counter;
		}
		void increment_round_count(){
			this->round_counter++;
		}
		void decrement_round_count(){
			if (this->round_counter > 0){
				this->round_counter--;
			}
		}
		bool is_game_over(){
			return this->game_over;
		}
		bool test_game_over(bool outside_test){
			if (outside_test == true){
				this->game_over = true;
			}
			return this->game_over;
		}

		void announce_game_over_value(){
			cout << "game_over is now set to: " << this->game_over << "\n\n\n";
		}
 		void what_is_round_num(){
                        cout << "Round Number: " << this->round_counter << "\n\n\n";
                }
                void round_limit_checker(){
                        // should be final place for what_is_round_num();
                        if (this->round_counter > 9){
                                this->game_over = true;
                                announce_game_over_value();
                                // call or return end game function
                                // here later
                        }
                }
		char give_current_mark(){
			return this->current_mark();
		}
	private:
		void display_info(){
			if (this->round_counter == 9){
				cout << "\n\nLast round!\n\n\n";
			}
			cout << "Player Turn: " << this->current_mark() << "\n\n\n";
			what_is_round_num(); // remove this later when
					     // included in
					     // round_limit_checker();
			// here is final place for round_limit_checker();
		}

		// variables
                int round_counter = 1;
		bool game_over = false;
		// char mark1 = 'X';
		// char mark2 = 'O';
		char mark;
		char current_mark(){
        		if (this->round_counter % 2 == 1){
                		this->mark = 'X';
        		} else {
                		this->mark = 'O';
        		}
			return this->mark;
		}
		// methods


};

class Player {
	public:
		int player_move(){
			cout << "Player " << this->mark << ", Please select the spot to place your mark.\n";
                        cin >> this->requested_spot;
			int invalid = this->validate_input(this->requested_spot);
			if (invalid){
				return 1;
			}
			return 0;
		}

		int give_requested_spot(){
                        return this->requested_spot;
                }


		/*
		char (*func) pass_request(){
			return this->give_requested_spot();
		}*/ // probably doesn't work ^^ but will save in case
		    // give_requested_spot() doesn't do the trick

		//
		
		char pass_on_mark(char current_mark){
			this->receive_current_mark(current_mark);
			return this->mark;
		}

	private:
		//
		
		// methods
		void say_invalid(){
		        cout << "\nHm, looks like you pressed some key that isn't valid...\n\nPlease try again\n\n" << endl;
		}
		
		int validate_input(char requested_spot){
			if (cin.fail()){
                		say_invalid();
                		cin.clear();
                		cin.ignore(numeric_limits<streamsize>::max(), '\n');
				return 1;
        		} else if (!(requested_spot > 0) || !(requested_spot <= 10)){
                		cout << "\nPlease only enter a number between 1 and 9.\n";
                		return 1;
        		}
			return 0;
		}

		void receive_current_mark(char current_mark){
			this->mark = current_mark;
		}


		// data members
		
		char mark = 'Y';
		int spot_to_fill = 0;
		int requested_spot = 0;
		// char mark1 = 'X'; // this will later need to be defined
				  // by initalization at the beginning
				  // of two separate player objects
		// char mark2 = 'O';
		int play_again_input = 0; // this may need to be moved
					  // to details class, or it may
					  // need to have a counterpart
					  // there
};

int main(){
	// initialize objects
	Game_Details this_game;
	Board board;
	Player player1;

	this_game.announce_game_over_value();
	board.draw_board();
	// game logic:
	while (this_game.give_round_count() <= 9 || this_game.test_game_over(board.announce_three_in_a_row()) == false){
		// details::display_info();
		this_game.what_is_round_num();
		char current_mark = this_game.give_current_mark();
		player1.pass_on_mark(current_mark);
		board.set_mark(current_mark);
		int invalid_input_check = player1.player_move();
		int request = player1.give_requested_spot();
		int spot_taken_check = board.attempt_to_fill(request, current_mark);
		if (invalid_input_check || spot_taken_check){
			this_game.decrement_round_count();
		}
		board.draw_board();
		// this_game.test_game_over(board.announce_three_in_a_row());
		this_game.increment_round_count();
		this_game.round_limit_checker();
		invalid_input_check = 0; // resets error values, just to be safe
		spot_taken_check = 0; // may be superfluous
	}
	return 0;
}
