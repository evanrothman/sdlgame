#include "Projectile.h"

Projectile::Projectile(Game* game, float x, float y, float speed, float angle)
  : Object(x, y, 30, 30), game(game), speed(speed), angle(angle){
  type = "projectile";
}

void Projectile::step(){
  SDL_SetRenderDrawColor(game->renderer, 0xff, 0, 0, 0xff);
  SDL_RenderFillRect(game->renderer, &body);
}
