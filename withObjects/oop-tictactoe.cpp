#include<iostream>
#include<array>
using namespace std;

class board {
	private:
                std::array<char, 9> board_spots = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        
	public :
                std::array<char,9> give_board_spots(){
                        return board_spots;
                }
                void draw_board(std::array<char,9>){ // this function is fairly self-explanatory; it draws the board by referencing the values from the array, board_spots
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
                /*bool announce_three_in_a_row(){
                        cout << "That's three in a row!\n\nPlayer \" << mark << \" wins!\n";
                        return game_over = true;
			// this var needs to be in the game_details
			// class.... hm. commenting out this code for now
                }*/
};

int main(){
	board the_board;
	the_board.draw_board(the_board.give_board_spots());
	return 0;
}
