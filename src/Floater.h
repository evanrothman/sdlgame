#ifndef FLOATER_H
#define FLOATER_H

#include <SDL3/SDL.h>
#include "Game.h"

class Floater : public Object{
private:
  Game* game;
  float speed;
  SDL_FRect body;
  double frame;
public:
  Floater(Game* game, float x, float y, float speed);
  void step();
};

#endif
