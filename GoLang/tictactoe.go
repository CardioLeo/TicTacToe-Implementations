package main

import (
	"fmt"
)

// section for board-related values & functions

var line_values [9]rune = [9]rune{'1', '2', '3', '4', '5', '6', '7', '8', '9'}

func draw_vert_line() {
	fmt.Print("     |     |     \n")
}

func draw_val_line() {
        fmt.Printf("  %c  |  %c  |  %c  \n", line_values[0], line_values[1], line_values[2])
	// pass a slice of line_values to this func
	// then use that slice to print the values each round
}

func draw_horiz_line() {
	fmt.Print("_____|_____|_____\n")
}

func draw_board() {
	fmt.Println()
	for i := 0; i <= 1; i++ {
		draw_vert_line()
		draw_val_line()
		draw_horiz_line()
	}
	draw_vert_line()
	draw_val_line()
	draw_vert_line()
	fmt.Println()

	// test printing values
	/*
	for i := 0; i < len(line_values); i++ {
		fmt.Printf("%c", line_values[i])
		fmt.Print("-")
	}
	fmt.Println()
	*/
}

// Section for game data functions

// type Game_Data struct
var player_marks [2]rune = [2]rune{'X', 'O'}
var mark rune

// I should probably create an ADT for the above data, then create
// an interface which enables me to pass around just the values I need

func change_player_turn(round_counter int8) {
        if (round_counter % 2 == 1) {
                mark = player_marks[0]
        } else {
                mark = player_marks[1]
	}
	// test:
	// fmt.Printf("%c", mark)
	// fmt.Println()
}

func tell_game_data(round_counter int8) {
	change_player_turn(round_counter)
	fmt.Printf("The current Player turn is: %c", mark)
	fmt.Println()
	fmt.Printf("The current round number is: %d", round_counter)
	fmt.Println()
	fmt.Println()
}

func wrong_input_for_move() {
	fmt.Println("Hmmm, looks like that's not a valid move\nPlease try a number between 1 and 9")
}

func ask_player_move() rune {
	var move rune
	fmt.Println("Pick a spot between 1 and 9 to place your mark.\n")
	fmt.Scanln(&move)
	if (move <= 0 || move >= 10) {
		wrong_input_for_move()
		ask_player_move()
	}
	return move
	// test:
	// fmt.Println("\nYou chose move: ", move)
}

// divide for play_game function, separate from the other sections

func play_game(){
        var round_counter int8 = 0
        for round_counter <= 9 {
                draw_board()
                tell_game_data(round_counter)
		ask_player_move()
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
