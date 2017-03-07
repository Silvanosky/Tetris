# include "gui.h"

void init_SDL(void)
{
  // Init only the video part
  if( SDL_Init(SDL_INIT_VIDEO)==-1 )
  {
    // If it fails, die with an error message
    errx(1,"Could not initialize SDL: %s.\n", SDL_GetError());
  }
  // We don't really need a function for that ...
}

void wait_for_keypressed(void)
{
  SDL_Event             event;
  // Infinite loop, waiting for event
  for (;;) {
    // Take an event
    SDL_PollEvent( &event );
    // Switch on event type
    switch (event.type)
    {
      // Someone pressed a key -> leave the function
      case SDL_KEYDOWN: return;
      default: break;
    }
  // Loop until we got the expected event
  }
}

SDL_Surface* initWindow(size_t x, size_t y)
{
  SDL_Surface *screen = NULL;
  SDL_Rect _screen;
  _screen.x = _screen.y = 0;
  //Init the window and display plain color
  screen = SDL_SetVideoMode(x, y, 0,
    SDL_HWSURFACE|SDL_ANYFORMAT|SDL_DOUBLEBUF); //1368, 768
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  SDL_Flip(screen);
  return screen;
  //SDL_FreeSurface(screen);
}

void test()
{
  init_SDL();
  SDL_Surface *screen = NULL;
  screen = initWindow(1368, 768);
  wait_for_keypressed();
  SDL_FreeSurface(screen);
  SDL_Quit();
}
