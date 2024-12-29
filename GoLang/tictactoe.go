package main

import (
	"fmt"
)

// type line_values struct {
//      '1', '2', '3', '4', '5', '6', '7', '8', '9' rune
// }

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
		fmt.Print(line_values[i])
		fmt.Print("-")
	}
	fmt.Println()
}

func main() {
	round_counter := 0
	for round_counter <= 9 {
		draw_board()
		round_counter++
	}
}
