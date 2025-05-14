#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL.h>
#include "Game.h"

class Player : public Object{
private:
  Game* game;
  float speed;
  SDL_FRect body;
  const bool* ks;
public:
  Player(Game* game, float x, float y, float speed);
  void step();
  void move(int x, int y);
};

#endif
