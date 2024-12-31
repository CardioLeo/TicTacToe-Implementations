package main

import (
	"fmt"
)

// section for board-related values & functions

var Line_Values [9]rune

func Set_Game_Values() {
        Line_Values = [9]rune{'1', '2', '3', '4', '5', '6', '7', '8', '9'}
}

var winning_rows = [8][3]int8 {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {6, 4, 2},
}

func Find_Winning_Rows() bool {
        var winning_row_found bool = false
        // announce_three_in_a_row(winning_row_found)
        var temp1, temp2, temp3 int8
        for i := 0; i < 8; i++ {
                temp1 = winning_rows[i][0]
                temp2 = winning_rows[i][1]
                temp3 = winning_rows[i][2]
                temp_bool := (Line_Values[temp1] == Line_Values[temp2] && Line_Values[temp2] == Line_Values[temp3])
                if (temp_bool) {
                        winning_row_found = true // I thought of making this just temp_bool,
                                                        // but decided the if statement was more readable
                        return winning_row_found
                }
        }
        return winning_row_found
}

func draw_vert_line() {
        fmt.Print("     |     |     \n")
}

func draw_horiz_line() {
        fmt.Print("_____|_____|_____\n")
}

func Draw_Board() {
        fmt.Println()
        draw_vert_line()
        fmt.Printf("  %c  |  %c  |  %c  \n", Line_Values[0], Line_Values[1], Line_Values[2])
        draw_horiz_line()
        draw_vert_line()
	fmt.Printf("  %c  |  %c  |  %c  \n", Line_Values[3], Line_Values[4], Line_Values[5])
        draw_horiz_line()
        draw_vert_line()
        fmt.Printf("  %c  |  %c  |  %c  \n", Line_Values[6], Line_Values[7], Line_Values[8])
        draw_vert_line()
        fmt.Println()
}

func main() {
}
