#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL.h>

class Player{
private:
  float speed;
  SDL_FRect body;
public:
  Player(float x, float y, float speed);
  void drawSelf(SDL_Renderer* renderer);
  void move(float x, float y);
  int* getLocation();
};

#endif
