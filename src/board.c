#include <stdio.h>
#include <stdbool.h>  

#include "classes/board.h"
#include "pacman.c"

bool equal(const PointOnBoard* point1, const PointOnBoard* point2)
{
	return point1->x == point2->x;
}

Board* create_board(const unsigned int board_row_size, const unsigned int board_column_size) {
	Board* new_board = (Board*) malloc(sizeof(Board));
	new_board->pacman = create_pacman();
	new_board->board_row_size = board_row_size;
	new_board->board_column_size = board_column_size;

	return new_board;
}

void clean_board(Board* board) {
    free(board);
}

unsigned int get_row_quantity(Board* board) {
    return board->board_row_size;
}

unsigned int get_column_quantity(Board* board, const unsigned int index) {
    return board->board_column_size;
}
