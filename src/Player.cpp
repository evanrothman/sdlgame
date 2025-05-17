#include "Player.h"
#include "Game.h"
#include <algorithm>
#include <iostream>
#include <cmath>

Player::Player(Game* game, float x, float y, float speed){
  this->game = game;
  body = {x, y, 100, 100};
  this->speed = speed;
  this->ks = SDL_GetKeyboardState(NULL);
  this->type = "player";
}

void Player::move(int x, int y){
  body.x = std::clamp((double)body.x + x * speed, 0.0, game->width - 100.0);
  body.y = std::clamp((double)body.y + y * speed, 0.0, game->height - 100.0);
}

bool Player::checkCollision(Object* other){
  return (std::abs(other->body.x - this->body.x) < 65) && (std::abs(other->body.y - this->body.y) < 65);
}

void Player::step(){
  int x = ks[SDL_SCANCODE_D] - ks[SDL_SCANCODE_A];
  int y = ks[SDL_SCANCODE_S] - ks[SDL_SCANCODE_W];
  
  move(x, y);
  
  for(Object* o: game->objects){
    if(o->type == "projectile"){
      if(checkCollision(o)){
        body.x = 500;
        body.y = 500;
      }
    }
  }
  
  SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderFillRect(game->renderer, &body);
}
