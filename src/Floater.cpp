#include <math.h>
#include "Floater.h"
#include "Game.h"

Floater::Floater(Game* game, float x, float y, float speed){
  this->game = game;
  body = {x, y, 30, 30};
  this->speed = speed;
  frame = 0.0;
}

void Floater::step(){
  body.y += sin(frame) * (double)speed;
  frame += 0.02;

  SDL_SetRenderDrawColor(game->renderer, 0xff, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderFillRect(game->renderer, &body);
}
