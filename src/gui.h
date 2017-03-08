# ifndef GUI_H_
# define GUI_H_

# include <stdio.h>
# include <stdlib.h>
# include <SDL.h>
# include <SDL_image.h>
# include <SDL/SDL_ttf.h>

//Remove at the end
# include <err.h>

void init_SDL();

void init_TTF();

void wait_for_keypressed(void);

SDL_Surface* load_image(char *path);

SDL_Surface* initWindow(size_t x, size_t y);



# endif /* GUI_H_ */
