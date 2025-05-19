#include "Player.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>

Player::Player(Game* game, float x, float y, float speed)
  : Object(x, y, 100, 100), game(game), speed(speed){ 
  ks = SDL_GetKeyboardState(NULL);
  type = "player";
  hp = 10;
}

void Player::move(int dx, int dy){
  x = std::clamp((double)x + dx * speed, 0.0, (double)game->width);
  y = std::clamp((double)y + dy * speed, 0.0, (double)game->height);
  body.x = x - (w / 2);
  body.y = y - (h / 2);
}

void Player::destroy(int i){
  delete game->objects[i];
  game->objects[i] = NULL;
}

bool Player::checkCollision(Object* other){
  return (std::abs(other->x - x) < 65) && (std::abs(other->y - y) < 65);
}

void Player::step(){
  int dx = ks[SDL_SCANCODE_D] - ks[SDL_SCANCODE_A];
  int dy = ks[SDL_SCANCODE_S] - ks[SDL_SCANCODE_W];
  move(dx, dy);
  
  for(int i = 0; i < game->objects.size(); i++){
    Object* o = game->objects[i];
    if(o){
      if(o->getType() == "projectile"){
        if(checkCollision(o)){
          destroy(i);
          if(--hp < 1) destroy(0);
        }
      }
    }
  }
  SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 0xff);
  SDL_RenderFillRect(game->renderer, &body);
}
