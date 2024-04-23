#include<iostream>
using namespace std;

class Details {
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

        private:
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


};
