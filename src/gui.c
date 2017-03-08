# include "gui.h"

void init_SDL()
{
  // Init only the video part
  if( SDL_Init(SDL_INIT_VIDEO)==-1 )
  {
    // If it fails, die with an error message
    errx(1,"Could not initialize SDL: %s.\n", SDL_GetError());
  }
  // We don't really need a function for that ...
}

void init_TTF()
{
  if(TTF_Init() == -1)
    {
      fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n",
      TTF_GetError());
      exit(EXIT_FAILURE);
    }
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

SDL_Surface* load_image(char *path)
{
  SDL_Surface          *img;
  // Load an image using SDL_image with format detection
  img = IMG_Load(path);
  if (!img)
    // If it fails, die with an error message
    errx(3, "can't load %s: %s", path, IMG_GetError());
  return img;
}

SDL_Surface* initWindow(size_t x, size_t y)
{
  SDL_Surface *screen = NULL;
  SDL_Rect _screen;
  _screen.x = _screen.y = 0;
  //Init the window and display plain color
  SDL_putenv("SDL_VIDEO_WINDOW_POS=center");
  screen = SDL_SetVideoMode(x, y, 0,
    SDL_HWSURFACE|SDL_ANYFORMAT|SDL_DOUBLEBUF); //1368, 768
  SDL_WM_SetCaption ("Tetris", NULL);
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  SDL_Flip(screen);
  return screen;
  //Titre fenetr//SDL_FreeSurface(screen);
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
