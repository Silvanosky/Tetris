#include "gameplay.h"

void handleInput(int* proceed, int* x, int* y, int* r)
{
	SDL_Event event;
	// Take an event
    if(!SDL_PollEvent(&event))
	{
		return;
	}
		
	// Switch on event type
	switch (event.type)
	{
	  	// Someone pressed a key -> leave the function
	  	case SDL_QUIT: /* Quit */
			*proceed = 0;
			break;
	  	case SDL_KEYDOWN: /* Si appui sur une touche */
			switch (event.key.keysym.sym)
			{
			  	case SDLK_SPACE: // key_space : launch the recognition
					*r += 1;
					break;
				case SDLK_UP:
					//TODO down bottom
					break;
				case SDLK_DOWN:
					*y += 1;
					break;
				case SDLK_RIGHT:
					*x += 1;
					break;
				case SDLK_LEFT:
					*x -= 1;
					break;
			  	case SDLK_ESCAPE:
			  		*proceed = 0;
			  		break;
			  	default: break;
			}
			break;
	  	default: break;
	}
}

void handleMovement(board* board, piece* p, int* currentScore,
 int dx, int dy, int dr)
{
	if (dy == 1)
		softDrop(currentScore);
	else 
		hardDrop(currentScore, dy); 
	
	p->c_i += dr;
	if(!checkPosition(board, p))
	{
		p->c_i -= dr;
		return;//Can't rotate so return;
	}

	p->x += dx;
	p->y += dy;
	
	if(!checkPosition(board, p))
	{
		p->x -= dx;
		p->y -= dy;
		return;
	}	
}

void checkGravity(board* b, piece* p, int* currentScore)
{
	static time_t lastTime = -1;
	if(lastTime == -1)
		lastTime = time(NULL);

	shape* shape = p->shapes_[p->c_i];
	
	double sec = difftime(time(NULL), lastTime);
	if(sec > 1.5)
	{
		p->y += 1;

		if(!checkPosition(b, p))
		{
			p->y -= 1;
			printf("Fix position");
			fixPosition(b, p);

			size_t nbLine = 0;
			for(size_t y = p->y; y < p->y + shape->w; y++)
			{	
				if(isLineFull(b, y))
				{
					nbLine++;
					removeLine(b, y);//TODO opti remove
				}
			}
			computeScore(currentScore, nbLine, b->lvl);
			free(p);
			b->piece_ = init_piece(getRandom(), 5);
		}
		lastTime = time(NULL);
	}
}

void play(SDL_Surface* screen)
{
	board* board = init_board(22, 10, 0);
	board->piece_ = init_piece(getRandom(), 5);//TODO dynamic x
	int *currentScore = malloc(sizeof (int));
	*currentScore = 0;

	int proceed = 1;
	createWindow(screen);
	while(proceed)
	{
		int dx = 0, dy = 0, dr = 0; 

		handleInput(&proceed, &dx, &dy, &dr);

		piece* p = board->piece_;

		handleMovement(board, p, currentScore,  dx, dy, dr);
	
		checkGravity(board, p, currentScore);

		printf("%ld %ld/n", p->x, p->y);
		
		displayBoard(screen, board);//TODO show piece
	}
}
