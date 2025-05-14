#include "Player.h"
#include "Game.h"

Player::Player(Game* game, float x, float y, float speed){
  this->game = game;
  body = {x, y, 100, 100};
  this->speed = speed;
  this->ks = SDL_GetKeyboardState(NULL);
}

void Player::move(int x, int y){
  body.x += x * speed;
  body.y += y * speed;
}

void Player::step(){
  int x = ks[SDL_SCANCODE_D] - ks[SDL_SCANCODE_A];
  int y = ks[SDL_SCANCODE_S] - ks[SDL_SCANCODE_W];
  
  move(x, y);
  
  SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderFillRect(game->renderer, &body);
}
