#include "gameplay.h"

void handleInput(int* Proceed, int* x, int* y)
{
	SDL_Event event;
	// Take an event
	SDL_WaitEvent(&event);
	// Switch on event type
	switch (event.type)
	{
	  	// Someone pressed a key -> leave the function
	  	case SDL_QUIT: /* Quit */
			*Proceed = 0;
			break;
	  	case SDL_KEYDOWN: /* Si appui sur une touche */
			switch (event.key.keysym.sym)
			{
			  	case SDLK_SPACE: // key_space : launch the recognition
					//Rotation
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
			  		*Proceed = 0;
			  		break;
			  	default: break;
			}
			break;
	  	default: break;
	}
}

void play(SDL_Surface* screen)
{
	time_t lastTime = time(NULL);

	board* board = init_board(22, 10, 0);
	//board->piece_ = TODO

	int Proceed = 1;
	createWindow(screen);
	while(Proceed)
	{
		int dx = 0;
		int dy = 0;
		
		handleInput(&Proceed, &dx, &dy);
		
		piece* p = board->piece_;
		p->x += dx;
		p->y += dy;

		if(!checkPosition(board, p))
		{
			p->x -= dx;
			p->y -= dy;
		}

		//Process
		double sec = difftime(time(NULL), lastTime);
		if(sec > 1.5)
		{
			p->y += 1;

			if(!checkPosition(board, p))
			{
				fixPosition(board, p);

				//TODO check line
				//TODO new piece
			}
			lastTime = time(NULL);
		}	
		
		displayBoard(screen, board->board_);//TODO show piece
	}
}
