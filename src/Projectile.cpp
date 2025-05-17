#include "Projectile.h"
#include "Game.h"

Projectile::Projectile(Game* game, float x, float y, float speed){
  this->game = game;
  this->body = {x, y, 30, 30};
  this->speed = speed;
  this->type = "projectile";
}

void Projectile::step(){
  SDL_SetRenderDrawColor(game->renderer, 0xff, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderFillRect(game->renderer, &body);
}
