/*
 * Author: William Z Chadwick
 * Date Created: 04/02/2024
 * Date Modified: 04/02/2024
 * Description: An implementation of TicTacToe with classes & OOP in C++.
 */


// Below, first the reader will find the class definitions:
// board, game_details, and player; after that are a few
// independent functions which will form the control flow
// for the game, such as: start_game, ask_to_play,
// and play_again,

// classes:
// 

class board {
        private {
                std::array<char, 9> board_spots = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        }
        public {
                std::array<char,9> give_board_spots(){
                        return std::array<char, 9> board_spots;
                }
                void draw_board(give_board_spots()){ // this function is fairly self-explanatory; it draws the board by referencing the values from the array, board_spots
        		cout << "\n\n     |     |     \n";
        		cout << "  " << board_spots[0] << "  |  " << board_spots[1] << "  |  " << board_spots[2] << "  \n";
        		cout << "_____|_____|_____\n";
        		cout << "     |     |     \n";
        		cout << "  " << board_spots[3] << "  |  " << board_spots[4] << "  |  " << board_spots[5] << "  \n";
        		cout << "_____|_____|_____\n";
        		cout << "     |     |     \n";
        		cout << "  " << board_spots[6] << "  |  " << board_spots[7] << "  |  " << board_spots[8] << "  \n";
        		cout << "     |     |     \n\n\n";
		};
		bool announce_three_in_a_row(){
        		cout << "That's three in a row!\n\nPlayer " << mark << " wins!\n";
        		return game_over = true;
		}
};

class game_details {
	private {

		// class variables
		int round_counter = 1;
		char game_over = false;
		int play_again_input = 0;
		int spot_to_fill = 0;

		// class methods
		void change_turn();
		void reset_pregame_variables();
		void say_invalid();
	}
	public {
		int give_round_counter(int round_counter){
			return round_counter;		
		}

		int up_one_round(int give_round_counter){
			round_counter++;
			return round_counter;		
		}

		void display_info();
	}
};

class player {
	private {
		char player_mark = 'X'; // if I have two separate player
					// objects, then I need an
					// abstraction to manage change
					// turns other than just the
					// round_counter making the mark
					// change when it's odd/even.
		//
		void attempt_to_fill_spot();
		void player_move();
	}

	public {
		//
	}
};

// independepnt functions
//

void start_game();
void ask_to_play();
void play_again();
