#ifndef FILE_HEADER_PIECE
#define FILE_HEADER_PIECE

#include <stdlib.h>
#include "board.h"

typedef struct shape {

	size_t h;
	size_t w;
	int* form;

} shape;

struct piece {

	size_t x;
	size_t y;

	size_t c_i;

	size_t n;
	shape* shapes_;

};

typedef struct piece piece;

int checkPosition(board *board_, piece *piece_);

#endif
