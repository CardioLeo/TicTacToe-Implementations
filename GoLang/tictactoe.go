package main

import (
	"fmt"
	// "bytes"
)

var line_values [9]rune = [9]rune{'1', '2', '3', '4', '5', '6', '7', '8', '9'}

func draw_vert_line() {
	fmt.Print("     |     |     \n")
}

func draw_val_line() {
        fmt.Print("  a  |  b  |  c  \n")
	// pass a slice of line_values to this func
	// then use that slice to print the values each round
}

func draw_horiz_line() {
	fmt.Print("_____|_____|_____\n")
}

func draw_board() {
	fmt.Println()
	draw_vert_line()
	draw_val_line()
	draw_horiz_line()
	draw_vert_line()
	draw_val_line()
	draw_horiz_line()
        draw_vert_line()
	draw_val_line()
	draw_vert_line()
	fmt.Println()

	// test printing values
	for i := 0; i < len(line_values); i++ {
		fmt.Printf("%c", line_values[i])
		fmt.Print("-")
	}
	fmt.Println()
}

// divide for game data functions

// type Game_Data struct
var player_marks [2]rune = [2]rune{'X', 'O'}
// var round_counter int8 = 0
var mark rune

func get_player_turn(round_counter int8) {
        if (round_counter % 2 == 1) {
                mark = player_marks[0]
        } else {
                mark = player_marks[1]
	}
	fmt.Printf("%c", mark)
	fmt.Println()
}

func tell_game_data(round_counter int8) {
	get_player_turn(round_counter)
	fmt.Printf("The current Player turn is: %c", mark)
	fmt.Println()
	fmt.Printf("The current round number is: %d", round_counter)
	fmt.Println()
	fmt.Println()
}

// divide for play_game function, separate from the other sections

func play_game(){
        var round_counter int8 = 0
        for round_counter <= 9 {
                draw_board()
                tell_game_data(round_counter)
                round_counter++
        }
}

func ask_to_play_again() {
	var answer int8
	fmt.Scanln(&answer)
	if (answer >= 3 || answer <= 0) {
		fmt.Println("\n\nHuh, that input isn't right; try 1 or 2\n\n")
		ask_to_play_again()
	} else if (answer == 1) {
		fmt.Println("\n\n\n\nWow, you want to play again, huh? Okay....\n\n")
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
