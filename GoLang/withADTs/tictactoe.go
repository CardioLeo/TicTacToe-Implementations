/*
 * Author: William Z Chadwick
 * Date Created: 12/28/2024
 * Date Modified: 12/29/2024
 * Description: Basic TicTacToe written in GoLang
 * Usage: 
*/

package main

import (
	"fmt"
	"board" // "board_pkg/board"
)

// Section for game data functions

// type Game_Data struct
var player_marks [2]rune = [2]rune{'X', 'O'}

func place_mark(move int8, mark rune) {
	Line_Values[move] = mark
}

// I should probably create an ADT for the above data, then create
// an interface which enables me to pass around just the values I need

func change_player_turn(round_counter int8) rune {
        var mark rune
	if (round_counter % 2 == 1) {
                mark = player_marks[1]
        } else {
                mark = player_marks[0]
	}
	return mark
}

func tell_game_data(round_counter int8) rune {
	mark :=	change_player_turn(round_counter)
	fmt.Printf("The current Player turn is: %c", mark)
	fmt.Println()
	fmt.Printf("The current round number is: %d", round_counter)
	fmt.Println()
	fmt.Println()
	return mark
}

func announce_winner_found(game_over bool, mark rune) {
        if game_over {
                fmt.Printf("Wow, Player %c got three in a row!\nThat's a Win!\n\n", mark)
        }
}


func wrong_input_for_move(input_error int8) {
	switch input_error {
	case 1:
		fmt.Println("Hmmm, looks like that's not a valid move\nPlease try a number between 1 and 9")
	case 2:
		fmt.Println("Oops, that spot is already taken\n")
	}
}

func move_minus_one() int8 {
	var minus_one int8
	fmt.Scanln(&minus_one)
	minus_one = minus_one - 1
	return minus_one
}

func ask_player_move() int8 {
	var move int8
	fmt.Println("Pick a spot between 1 and 9 to place your mark.\n")
	move = move_minus_one()
	return move
}

func test_player_move(move int8) int8 {
        if (move < 0 || move >= 9) {
                wrong_input_for_move(1)
                return ask_player_move()
        } else if (Line_values[move] == 'X' || Line_values[move] == 'O') {
                wrong_input_for_move(2)
                return ask_player_move()
        }
	return move
}

func player_move() int8 {
	var move int8 = ask_player_move()
	var tested_move int8 = test_player_move(move)
	return tested_move
}

// divide for play_game function, separate from the other sections

func play_game(){
        var game_over bool = false
	var round_counter int8 = 0
	Set_Game_Values()
        Draw_Board()
	for (round_counter <= 8 && !game_over) {
		mark := tell_game_data(round_counter)
		move := player_move()
		place_mark(move, mark)
		Draw_Board()
		game_over = Find_Winning_Rows()
		announce_winner_found(game_over, mark)
                round_counter++
        }
}

func ask_to_play_again() {
	var answer int8
	fmt.Println("Game over! --- Would you like to play again?\nIf yes, press 1; if no, press 2\n")
	fmt.Scanln(&answer)
	if (answer >= 3 || answer <= 0) {
		fmt.Println("\nHuh, that input isn't right; try 1 or 2\n")
		ask_to_play_again()
	} else if (answer == 1) {
		fmt.Println("\n\nWow, you want to play again, huh? Okay....\n")
		play_game()
		ask_to_play_again()
	} else {
		fmt.Println("\n\n\nGoodbye!\n\n")
	}
}

func main() {
	play_game()
	ask_to_play_again()
}
