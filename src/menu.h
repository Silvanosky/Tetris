# ifndef MENU_H_
# define MENU_H_

# include "gui.h"
# include "gameplay.h"

TTF_Font* load_font(char *path, size_t size); //"../bin/font/font.ttf"

SDL_Surface* createMenu();

void eventManager();

# endif /* MENU_H_ */
