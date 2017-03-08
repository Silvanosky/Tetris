#include <stdlib.h>
#include <stdio.h>

# include "menu.h"
# include "gameUI.h"


int main()
{
	SDL_Surface *screen = NULL;
	screen = createMenu();
	eventManager(screen);
	return 0;
}
