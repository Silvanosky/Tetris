# include "gameUI.h"
# include "menu.h"


SDL_Surface** load_sprites()
{
  SDL_Surface **sp = malloc( 7 * sizeof(SDL_Surface*));
  sp[0] = load_image("bin/sprites/blue.bmp");
  sp[1] = load_image("bin/sprites/cyan.bmp");
  sp[2] = load_image("bin/sprites/green.bmp");
  sp[3] = load_image("bin/sprites/yellow.bmp");
  sp[4] = load_image("bin/sprites/pink.bmp");
  sp[5] = load_image("bin/sprites/red.bmp");
  sp[6] = load_image("bin/sprites/purple.bmp");
  return sp;
}

SDL_Surface* drawScore(SDL_Surface *screen, int score)
{
    SDL_Surface *toBlit = NULL;
    SDL_Rect _score = {20, 20, 0, 0};
    SDL_Rect _text = {35, 35, 0, 0};
    toBlit =  SDL_CreateRGBSurface(0, 200, 210, 32, 0, 0, 0, 0);
    SDL_BlitSurface(toBlit, NULL, screen, &_score);

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
    SDL_Flip(screen);
    return screen;
}



SDL_Surface* createWindow(SDL_Surface *screen)
{
  SDL_Surface /**board,*/ *toBlit = NULL;
  SDL_Rect /*_board = {355, 20, 0, 0},*/ _back = {0 ,0 ,0 ,0};
  SDL_Rect _score = {20, 20, 0, 0}, _next = {650, 20, 0, 0};
  SDL_Rect _text = {35, 35, 0, 0};
  toBlit = load_image("bin/sprites/game_background.bmp");
  SDL_BlitSurface(toBlit, NULL, screen, &_back);
  //board =  SDL_CreateRGBSurface(0, 250, 500, 32, 0, 0, 0, 0);
  //SDL_FillRect(board, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  //SDL_BlitSurface(board, NULL, screen, &_board);
  //toBlit =  SDL_CreateRGBSurface(0, 200, 210, 32, 0, 0, 0, 0);
  //SDL_BlitSurface(toBlit, NULL, screen, &_score);
  toBlit =  SDL_CreateRGBSurface(0, 100, 100, 32, 0, 0, 0, 0);
  SDL_BlitSurface(toBlit, NULL, screen, &_next);
  //Text
  TTF_Font *font = NULL;
  SDL_Color white_color = {255, 255, 255, 0};
  init_TTF();
  font = load_font("bin/font/font.ttf", 40);
/*  toBlit = TTF_RenderText_Blended(font, "Score : 0", white_color);
  SDL_BlitSurface(toBlit, NULL, screen, &_text);
  _text.y += 60;
  toBlit = TTF_RenderText_Blended(font, "Niveau : 1", white_color);
  SDL_BlitSurface(toBlit, NULL, screen, &_text);
  _text.y += 60;
  toBlit = TTF_RenderText_Blended(font, "Ligne(s) : 0", white_color);
  SDL_BlitSurface(toBlit, NULL, screen, &_text);*/
  toBlit = TTF_RenderText_Blended(font, "Next", white_color);
  _next.y += 105;
  _next.x += 17;
  SDL_BlitSurface(toBlit, NULL, screen, &_next);
  SDL_Flip(screen);
  screen = drawScore(screen, 50);
  return screen;
}



SDL_Surface* drawBoard(SDL_Surface *screen, SDL_Rect _board,  board *board, SDL_Surface **sp)
{
  SDL_Surface *game, *toBlit = NULL;
  //SDL_Rect _board = {355, 20, 0, 0};
  game =  SDL_CreateRGBSurface(0, 250, 500, 32, 0, 0, 0, 0);
  SDL_FillRect(game, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  SDL_BlitSurface(game, NULL, screen, &_board);
  for (size_t i = 0; i < 10; i++)
  {
    _board.y = 20;
    for (size_t j = 2; j < 22; j++)
    {
      //warnx(j * 10 + i);
      if (board->board_[j * 10 + i] == 0)
      {
        _board.y +=25;
        continue;
      }
      switch (board->board_[j * 10 + i]) {
        case 1:
          toBlit = sp[board->board_[j * 10 + i]];
          break;
        case 2:
          toBlit = sp[board->board_[j * 10 + i]];
          break;
        case 3:
          toBlit = sp[board->board_[j * 10 + i]];
          break;
        case 4:
          toBlit = sp[board->board_[j * 10 + i]];
          break;
        case 5:
          toBlit = sp[board->board_[j * 10 + i]];
          break;
        case 6:
          toBlit = sp[board->board_[j * 10 + i]];
          break;
        default:
          break;
      }
      SDL_BlitSurface(toBlit, NULL, screen, &_board);
      _board.y += 25;
    }
    _board.x += 25;
  }
  SDL_Flip(screen);
  return screen;
}

SDL_Surface* drawPiece(SDL_Surface *screen, piece* p, SDL_Surface **sp)
{
  SDL_Surface* toBlit = NULL;
  SDL_Rect _board;
  _board.x = 355 + 25 * p->x;
  _board.y = 20 + 25 * p->y;
  toBlit = sp[p->id];
  shape* shape_ = p->shapes_[p->c_i];
  for (size_t i = 0; i < shape_->h; i++)
  {
    _board.y = 20 + 25 * p->y;
    for (size_t j = 0; j < shape_->w; j++)
    {
      //warnx(j * 10 + i);
      if (shape_->form[j * (shape_->w) + i] == 0)
      {
        _board.y +=25;
        continue;
      }
      SDL_BlitSurface(toBlit, NULL, screen, &_board);
      _board.y += 25;
    }
    _board.x += 25;
  }

}

SDL_Surface* displayBoard(SDL_Surface *screen, board *board, SDL_Surface **sp)
{
  SDL_Rect _board = {355, 20, 0, 0};
  drawBoard(screen, _board, board, sp);
  SDL_Flip(screen);
  return screen;
}
