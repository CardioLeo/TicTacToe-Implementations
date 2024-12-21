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
		bool game_over = false;
		int current_round = 0;
		void tell_game_over(){
			if (this->game_over == true){
				cout << "The Game is now over\n";
			} else {
				cout << "The Game is not yet over; keep playing\n";
			}
		}
		void tell_current_round(){
			cout << "The current round is: " << this->current_round << "\n\n";
		}
		
		void increment_round(){
			this->current_round++;
		}

		void round_check(){
			this->increment_round();
			if (this->current_round >= 9){
				this->game_over = true;
			}
		}

        public:
                void give_game_status(){
			this->round_check();
			this->tell_game_over();
                	this->tell_current_round();
		}

		bool win_check(){
			return (this->game_over || this->current_round >= 10);
		}
};

int main(){
	// initializing objects
	Board board;
	Game_Data this_game;

	// game play
	board.draw_board();
	while (this_game.win_check() == false){
		board.draw_board();
		this_game.give_game_status();
	}

	return 0;
}
