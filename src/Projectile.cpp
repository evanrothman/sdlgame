#include "Projectile.h"
#include <cmath>

Projectile::Projectile(Game* game, float x, float y, float speed, float angle)
  : Object(x, y, 20, 20), game(game), speed(speed), angle(angle){
  type = "projectile";
}

void Projectile::step(){
  x += speed * cos(angle);
  y += speed * sin(angle);
  body.x = x - (w / 2);
  body.y = y - (h / 2);
  SDL_SetRenderDrawColor(game->renderer, 0xff, 0, 0, 0xff);
  SDL_RenderFillRect(game->renderer, &body);
}
