#include "Player.h"

Player::Player(float x, float y, float speed){
  body = {x, y, 100, 100};
  this->speed = speed;

}

void Player::move(float x, float y){
  body.x += x * speed;
  body.y += y * speed;
}

void Player::drawSelf(SDL_Renderer* renderer){
  SDL_RenderFillRect(renderer, &body);
}
