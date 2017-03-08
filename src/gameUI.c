# include "gameUI.h"
# include "menu.h"

SDL_Surface* createWindow(SDL_Surface *screen)
{
  SDL_Surface *board, *toBlit = NULL;
  SDL_Rect _board = {355, 20, 0, 0}, _back = {0 ,0 ,0 ,0};
  SDL_Rect _score = {20, 20, 0, 0}, _next = {650, 20, 0, 0};
  SDL_Rect _text = {35, 35, 0, 0};
  toBlit = load_image("bin/sprites/game_background.bmp");
  SDL_BlitSurface(toBlit, NULL, screen, &_back);
  board =  SDL_CreateRGBSurface(0, 250, 500, 32, 0, 0, 0, 0);
  SDL_FillRect(board, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  SDL_BlitSurface(board, NULL, screen, &_board);
  toBlit =  SDL_CreateRGBSurface(0, 200, 210, 32, 0, 0, 0, 0);
  SDL_BlitSurface(toBlit, NULL, screen, &_score);
  toBlit =  SDL_CreateRGBSurface(0, 100, 100, 32, 0, 0, 0, 0);
  SDL_BlitSurface(toBlit, NULL, screen, &_next);
  //Text
  TTF_Font *font = NULL;
  SDL_Color white_color = {255, 255, 255, 0};
  init_TTF();
  font = load_font("bin/font/font.ttf", 40);
  toBlit = TTF_RenderText_Blended(font, "Score : 0", white_color);
  SDL_BlitSurface(toBlit, NULL, screen, &_text);
  _text.y += 60;
  toBlit = TTF_RenderText_Blended(font, "Niveau : 1", white_color);
  SDL_BlitSurface(toBlit, NULL, screen, &_text);
  _text.y += 60;
  toBlit = TTF_RenderText_Blended(font, "Ligne(s) : 0", white_color);
  SDL_BlitSurface(toBlit, NULL, screen, &_text);
  toBlit = TTF_RenderText_Blended(font, "Next", white_color);
  _next.y += 105;
  _next.x += 17;
  SDL_BlitSurface(toBlit, NULL, screen, &_next);
  SDL_Flip(screen);
  wait_for_keypressed();
  return screen;
}

SDL_Surface* displayBoard(SDL_Surface *screen, int *board)
{
  SDL_Surface *game, *toBlit = NULL;
  SDL_Rect _board = {355, 20, 0, 0};
  game =  SDL_CreateRGBSurface(0, 250, 500, 32, 0, 0, 0, 0);
  SDL_FillRect(game, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  SDL_BlitSurface(game, NULL, screen, &_board);
  for (size_t i = 0; i < 10; i++)
  {
    _board.x = 355;
    for (size_t j = 2; j < 20; j++)
    {
      if (board[j * 10 + i])
      {
        toBlit = load_image("bin/sprites/cyan.bmp");
      }
      else
      {
        toBlit = load_image("bin/sprites/pink.bmp");
      }
      SDL_BlitSurface(toBlit, NULL, screen, &_board);
      _board.x += 25;
    }
    _board.y += 25;
  }
}