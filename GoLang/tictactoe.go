package main


import (
	"fmt"
)

func draw_vert_line() {
	fmt.Print("     |     |     \n")
}

func draw_val_line() {
        fmt.Print("  a  |  b  |  c  \n")
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

}

func main() {
	round_counter := 0
	for i <= 9 {
		draw_board()
		round_counter++
		// fmt.Println(round_counter)
	}
}
