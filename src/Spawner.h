#ifndef SPAWNER_H
#define SPAWNER_H

#include "Game.h"
#include "Projectile.h"

class Spawner : public Object{
  Game* game;
  int frame;
 
public:
  Spawner(Game* game);
  void step();
};
#endif
