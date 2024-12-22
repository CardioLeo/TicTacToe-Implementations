/*
 *
 *
 *
 *
 */

#include<iostream>
#include<array>

using namespace std;

// bool game_over = false;

array<char,9> board_spots = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

array<array<char,3>,8> matching_rows_of_three = {
	{
		{board_spots[0], board_spots[1], board_spots[2]},
		{board_spots[3], board_spots[4], board_spots[5]}, 
		{board_spots[6], board_spots[7], board_spots[8]},
        	{board_spots[0], board_spots[3], board_spots[6]},
		{board_spots[1], board_spots[4], board_spots[7]},
        	{board_spots[2], board_spots[5], board_spots[8]},
		{board_spots[0], board_spots[4], board_spots[8]},
        	{board_spots[2], board_spots[4], board_spots[6]}
	}
};

void announce_three_in_a_row(){
        cout << "That's three in a row!\n\nCurrent Player wins!\n";
        // game_over = true;
}


array<char,3> make_three_temp_spots(int i) {
	int j = 0;
	array<char,3> match_array = {
		matching_rows_of_three[i][j],
        	matching_rows_of_three[i][j+1],
        	matching_rows_of_three[i][j+2]
	};
	return match_array;
	// cout << "Temp_spots 1, 2, and 3 are " << "\n" << temp_spot_1 << "\n" << temp_spot_2 << "\n" << temp_spot_3 << "\n";

}

bool check_temp_spots_match(array<char,3> match_array){
	cout << match_array[0] << "\n" << match_array[1] << "\n" << match_array[2] << "\n";
	if (match_array[0] == match_array[1] && match_array[1] == match_array[2]){
		announce_three_in_a_row();
		return true;
	}
	return false;
}

void show_all_winning_rows(array<array<char,3>,8>, array<char, 9>){
	for (int i = 0; i <= 7; i++){
		cout << "\n\nSolution number: " << i + 1 << "\n";
		array<char,3> match = make_three_temp_spots(i);
		check_temp_spots_match(match);
		// }
		// game_over = check_temp_spots_match(match);

	}
}

int main(){
		show_all_winning_rows(matching_rows_of_three, board_spots);
return 0;}
