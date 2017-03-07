#ifndef FILE_HEADER_BOARD
#define FILE_HEADER_BOARD

#include <stdlib.h>
#include "piece.h"

typedef struct board{
	size_t h;
	size_t w;

	size_t lvl;

	size_t score;

	int* board_;

	piece* piece_;

};

board* init_board(size_t h, size_t w, size_t lvl);

void free_board(board* board_);

int loose(board* board_, piece* piece);

int isLineFull(board* board_, size_t y);

void removeLine(board* board_, size_t y);

#endif
