#include "Player.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>

Player::Player(Game* game, float x, float y, float speed)
  : Object(x, y, 100, 100), game(game), speed(speed){ 
  this->ks = SDL_GetKeyboardState(NULL);
  this->type = "player";
}

void Player::move(int dx, int dy){
  x = std::clamp((double)x + dx * speed, 0.0, (double)game->width);
  y = std::clamp((double)y + dy * speed, 0.0, (double)game->height);
  body.x = x - (w / 2);
  body.y = y - (h / 2);
}

bool Player::checkCollision(Object* other){
  return (std::abs(other->x - x) < 65) && (std::abs(other->y - y) < 65);
}

void Player::step(){
  int dx = ks[SDL_SCANCODE_D] - ks[SDL_SCANCODE_A];
  int dy = ks[SDL_SCANCODE_S] - ks[SDL_SCANCODE_W];
  move(dx, dy);
  
  for(Object* o: game->objects){
    if(o->getType() == "projectile"){
     if(checkCollision(o)){
        game->objects.erase(game->objects.begin() + (&o - &game->objects[0]));
        delete o;
      }
    }
  }
  SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 0xff);
  SDL_RenderFillRect(game->renderer, &body);
  SDL_SetRenderDrawColor(game->renderer, 0xff, 0, 0, 0xff);
  SDL_RenderPoint(game->renderer, x, y);
}
