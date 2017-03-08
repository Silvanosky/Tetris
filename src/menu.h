# ifndef MENU_H_
# define MENU_H_

# include "gui.h"

TTF_Font* load_font(char *path, size_t size); //"../bin/font/font.ttf"

void createMenu();

void eventManager();

# endif /* MENU_H_ */
