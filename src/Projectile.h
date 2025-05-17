#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SDL3/SDL.h>
#include "Game.h"

class Projectile : public Object{
private:
  Game* game;
  float speed;
  float angle;
public:
  Projectile(Game* game, float x, float y, float speed);
  void step();
};

#endif
