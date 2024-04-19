#include<iostream>
#include<array>
using namespace std;

class Board {
        private:
                static constexpr std::array<char, 9> board_spots = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

        public :
                static std::array<char,9> give_board_spots(){
                        return Board::board_spots;
                }
                static void draw_board(std::array<char,9>){ // this function is fairly self-explanatory; it draws the board by referencing the values from the array, board_spots
                        cout << "\n\n     |     |     \n";
                        cout << "  " << Board::board_spots[0] << "  |  " << Board::board_spots[1] << "  |  " << Board::board_spots[2] << "  \n";
                        cout << "_____|_____|_____\n";
                        cout << "     |     |     \n";
                        cout << "  " << Board::board_spots[3] << "  |  " << Board::board_spots[4] << "  |  " << Board::board_spots[5] << "  \n";
                        cout << "_____|_____|_____\n";
                        cout << "     |     |     \n";
                        cout << "  " << Board::board_spots[6] << "  |  " << Board::board_spots[7] << "  |  " << Board::board_spots[8] << "  \n";
                        cout << "     |     |     \n\n\n";
                };
                /*bool announce_three_in_a_row(){
                        cout << "That's three in a row!\n\nPlayer \" << mark << \" wins!\n";
                        return game_over = true;
                        // this var needs to be in the game_details
                        // class.... hm. commenting out this code for now
                }*/
};

class Details {
        public:
		// methods
		int round_count(){
			int r_c = this->round_counter;
			return r_c;
		}
                bool is_game_over(){
			bool g_o = this->game_over;
			return g_o;
		}
		int test_r_c_is_10(){
                        return main_game_loop();
                }
		void announce_game_over_value(){
			cout << "game_over is now set to: " << this->game_over << "\n\n\n";
		}
	private:
	        void what_is_round_num(){
                        cout << "Round Number: " << this->round_counter << "\n\n\n";
                }
		void display_info(){
			if (this->round_counter == 9){
				cout << "\n\nLast round!\n\n\n";
			}
			cout << "Player Turn: --not yet declared--\n\n\n";
			what_is_round_num(); // remove this later when
					     // included in
					     // round_limit_checker();
			// here is final place for round_limit_checker();
		}

		// variables
                int round_counter = 1;
		bool game_over = false;

		// methods
		void round_limit_checker(){
			// should be final place for what_is_round_num();
			if (this->round_counter > 9){
				this->game_over = true;
				announce_game_over_value();
				// call or return end game function
				// here later
			}
		}
                int main_game_loop(){
			// round_limit_checker();
			for (this->round_counter; this->round_counter <= 9; this->round_counter++){
				what_is_round_num();
				Board::draw_board(Board::give_board_spots());
				// board::draw_board();
                        }
			round_limit_checker();
                        return this->round_counter;
                }
};

int main(){
	Details this_game;
//	Board board;
//	main_game_loop();
	// Board::draw_board(Board::give_board_spots());
		// the following is not intended to be permanent
	this_game.announce_game_over_value();
	this_game.test_r_c_is_10();
	return 0;
}
