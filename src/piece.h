#ifndef FILE_HEADER_PIECE
#define FILE_HEADER_PIECE

typedef struct s_shape{

	size_t h;
	size_t w;
	char* form;

} shape;

typedef struct s_piece{

	size_t x;
	size_t y;

	size_t c_i;

	size_t n;
	shape* shapes_;	

} piece;

#endif
