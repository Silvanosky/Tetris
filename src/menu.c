# include "gui.h"
# include "menu.h"

TTF_Font* load_font(char *path, size_t size) //"../bin/font/font.ttf"
{
  TTF_Font *font = NULL;
  font = TTF_OpenFont(path, size);
  if(!font) {
    printf("TTF_OpenFont: %s\n", TTF_GetError());
    exit(EXIT_FAILURE);
  }
  return font;
}

void createMenu()
{
  SDL_Surface *screen, *toBlit, *logo , *background = NULL;
  SDL_Rect _play = {430, 270, 0, 0}, _quit = {430, 330, 0, 0};
  SDL_Rect _logo = {257, 50, 0, 0}, _background = {0, 0, 0, 0};
  TTF_Font *font = NULL;
  SDL_Color white_color = {255, 255, 255, 0};
  screen = initWindow(960, 540);
  background = load_image("bin/sprites/background.bmp");
  SDL_BlitSurface(background, NULL, screen, &_background);
  logo = load_image("bin/sprites/logo.bmp");
  SDL_BlitSurface(logo, NULL, screen, &_logo);
  init_TTF();
  font = load_font("bin/font/font.ttf", 50);
  toBlit = TTF_RenderText_Blended(font, "PLAY", white_color);
  SDL_BlitSurface(toBlit, NULL, screen, &_play);
  toBlit = TTF_RenderText_Blended(font, "QUIT", white_color);
  SDL_BlitSurface(toBlit, NULL, screen, &_quit );
  SDL_Flip(screen);
  wait_for_keypressed();
}
