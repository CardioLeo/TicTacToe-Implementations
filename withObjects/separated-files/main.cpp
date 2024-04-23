#include<iostream>
#include<array>
#include "board_class.h"
#include "details_class.h"
#include "player_class.h"

using namespace std;

int main(){
        Details this_game;
        Board board;
        Player player1;
        this_game.announce_game_over_value();
        board.draw_board(board.give_board_spots());
        while (this_game.give_round_count() <= 9){
                // details::display_info();
                this_game.what_is_round_num();
                int error1 = player1.player_move();
                int request = player1.give_requested_spot();
                int error2 = board.attempt_to_fill(request);
                if (error1 || error2){
                        this_game.decrement_round_count();
                }
                board.draw_board(board.give_board_spots());
                // board::find_three_in_a_row();
                // details::change_turn();
                this_game.increment_round_count();
                this_game.round_limit_checker();
                error1 = 0; // resets error values, just to be safe
                error2 = 0; // may be superfluous
        }
        return 0;
}
