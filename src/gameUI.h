# ifndef GAMEUI_H_
# define GAMEUI_H_

# include "gui.h"
# include "game.h"


SDL_Surface** load_sprites();

SDL_Surface* createWindow(SDL_Surface *screen);

SDL_Surface* displayBoard(SDL_Surface *screen, board* board, SDL_Surface **sp);

# endif /* GAMEUI_H_ */
