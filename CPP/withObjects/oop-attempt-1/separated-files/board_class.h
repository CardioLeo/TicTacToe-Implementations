#include<iostream>
#include<array>
using namespace std;

//
// // //
// temporary global variables
// // //
//
        char mark1 = 'X';
        char mark2 = 'O';
// // //


class Board {
        private:
                std::array<char, 9> board_spots = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

        public :
                std::array<char,9> give_board_spots(){
                        return board_spots;
                }
		char give_one_spot(int request){
                        return this->board_spots[request];
                }

                int attempt_to_fill(int request){
                        if (this->board_spots[request-1] == 'X' || this->board_spots[request-1] == 'O'){
                                cout << "\nThis spot has already been filled!\n\nPlease choose another spot.\n";
                                return 1;
                        } else {
                                 this->board_spots[request-1] = mark1;
                                 return 0;
                        }
                }
                void draw_board(std::array<char,9>){
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
