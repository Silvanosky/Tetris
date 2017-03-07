#include "board.h"

board* init_board(size_t h, size_t w, size_t lvl)
{
	board* board_ = malloc(1 * sizeof(board));
	board_->h = h;
	board_->w = w;
	board_->lvl = lvl;

	board_->score = 0;
	board_->board_ = malloc(h * w * sizeof(int));
	for(int i = 0; i < h*w; i++)
		board_->board_[i] = 0;

	board_->piece_ = NULL;

	return board_;
}

void free_board(board* board)
{
	free(board_->board_);
	free_piece(board_->piece_);
	free(board);
}

int loose(board* board, piece* piece)
{
	shape* shape = piece->shapes_[piece.c_i];
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

void removeLine(board* board, size_t y)
{
	for(size_t y = y; y >= 0; y--)
	{
		for(size_t x = board->w; x >= 0; x--)
		{
			
		}
	}
}
