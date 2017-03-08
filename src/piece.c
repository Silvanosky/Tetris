#include "piece.h"

int checkPosition(board *board_, piece *piece) 
{
	shape shape_ = piece->shapes_[0];
	for (size_t y = 0; y < shape_.h; y++) 
	{
		for (size_t x = 0; x < shape_.w; x++) 
		{
			if (piece->x + x >= board_->w || piece->x + x < 0)
				return 0;
			if (piece->y + y >= board_->h)
				return 0;
			if (shape_.form[y * shape_.w + x] 
				&& board_->board_[(y + piece->y) * board_->w + (x + piece->x)])
				return 0;	
		}
	}
	return 1;
}

