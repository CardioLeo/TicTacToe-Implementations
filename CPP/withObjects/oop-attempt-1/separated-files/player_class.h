#include<iostream>
#include<limits>

using namespace std;

class Player {
        public:
                int player_move(){
                        cout << "Player " << this->mark1 << ", Please select the spot to place your mark.\n";
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
                // data members

                int spot_to_fill = 0;
                int requested_spot = 0;
                char mark1 = 'X'; // this will later need to be defined
                                  // by initalization at the beginning
                                  // of two separate player objects
                char mark2 = 'O';
                int play_again_input = 0; // this may need to be moved
                                          // to details class, or it may
                                          // need to have a counterpart
                                          // there
};
