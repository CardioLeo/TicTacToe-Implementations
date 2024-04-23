#include<iostream>
#include<array>
#include "board_class.h"
#include "details_class.h"
#include "player_class.h"

using namespace std;

int main(){

	// instantiating objects

	Details this_game;
        Board board;
        Player player1;

	// player2 of course needs to be instantiated
	// but that will involve figuring out just how
	// the class should be designed to have more
	// than one player; versus how I previously
	// had a mark variable which alternated
	// between values based on whether the
	// round_counter var was divisible by 2

	// initial announcement & board-drawing

        this_game.announce_game_over_value();
        board.draw_board(board.give_board_spots());

	// main gameplay loop
	
        while (this_game.give_round_count() <= 9){
        
		// needs to be put in:
		// details::display_info();

                this_game.what_is_round_num();
                
		// primitive way of keeping track of
		// errors while calling primary object
		// methods:

		int error1 = player1.player_move();
                int request = player1.give_requested_spot();
                int error2 = board.attempt_to_fill(request);
                if (error1 || error2){
                        this_game.decrement_round_count();
                }

		// draws updated board, so long as errors = 0

                board.draw_board(board.give_board_spots());

		// needs to be put in:
                // board::find_three_in_a_row();
                // details::change_turn();
		
		// some housekeeping; hopefully can be done
		// more cleanly in the future
                
		this_game.increment_round_count();
                this_game.round_limit_checker();
                error1 = 0; // resets error values, just to be safe
                error2 = 0; // may be superfluous
        }
        return 0;
}
