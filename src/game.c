#include "game.h"

board* init_board(size_t h, size_t w, size_t lvl)
{
	board* board_ = malloc(1 * sizeof(board));
	board_->h = h;
	board_->w = w;
	board_->lvl = lvl;

	board_->score = 0;
	board_->board_ = malloc(h * w * sizeof(int));
	for(size_t i = 0; i < h*w; i++)
		board_->board_[i] = 0;

	board_->piece_ = NULL;

	return board_;
}

void free_board(board* board)
{
	free(board->board_);
	free(board->piece_);
	free(board);
}

int loose(board* board, piece* piece)
{
	shape* shape = piece->shapes_[piece->c_i];
	for(size_t x = 0; x < shape->w; x++)
	{
		for(size_t y = 0; y < shape->h; y++)
		{
			if(shape->form[y*shape->w + x] 
				&& board->board_[(y + piece->y) * board->w + (x + piece->x)])
				return 1;
		}
	}
	return 0;
}

int isLineFull(board* board, size_t y)
{
	for(size_t x = 0; x < board->w; x++)
	{
		if(!board->board_[y * board->w + x])
			return 0;
	}
	return 1;
}

void removeLine(board* board, size_t ly)
{
	for(size_t y = ly; y > (size_t)0; y--)
	{
		for(size_t x = board->w; x > (size_t)-1; x--)
		{
			board->board_[y * board->w + x] = 
				board->board_[(y-1) * board->w + x];
		}
	}

	for(size_t x = 0; x < board->w; x++)
	{
		board->board_[x] = 0;
	}
}

int checkPosition(board *board_, piece *piece) 
{
	shape* shape_ = piece->shapes_[piece->c_i];
	for (size_t y = 0; y < shape_->h; y++) 
	{
		for (size_t x = 0; x < shape_->w; x++) 
		{
			if (piece->x + x >= board_->w || piece->x + x <= (size_t)-1)
				return 0;
			if (piece->y + y >= board_->h)
				return 0;
			if (shape_->form[y * shape_->w + x] 
				&& board_->board_[(y + piece->y) * board_->w + (x + piece->x)])
				return 0;	
		}
	}
	return 1;
}
