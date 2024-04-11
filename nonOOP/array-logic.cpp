/*
 *
 *
 *
 *
 */

#include<iostream>
#include<array>

using namespace std;

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

void show_all_winning_rows(array<array<char,3>,8>, array<char, 9>){
	for (int i = 0; i <= 7; i++){
		cout << "\n\nSolution number: " << i + 1 << "\n";
		for (int j = 0; j <= 2; j++){
			cout << "Element: " << matching_rows_of_three[i][j] << "\n";
			// cout << "This is: " << win_spot[j] << "/n";
			// array<char,3> win_spot[j] = j;
			// if win_spots 1,2,3 are identical, return true; else false
			// Problem is, this really can't be done without more
			// loops, and it needs to be abstracted away from a
			// function which merely shows winning rows and into
			// a function which checks if the three elements of
			// each winning combination are identical; in which
			// case I need three temporary variables which change
			// each time through the i loop to show the three
			// variables at the j level and checks if they are
			// identical, making three in a row
		}
	}
}

int main(){
	show_all_winning_rows(matching_rows_of_three, board_spots);
return 0;
}
