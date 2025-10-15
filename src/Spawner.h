#include "Game.h"
#include "Projectile.h"

#ifndef SPAWNER_H
#define SPAWNER_H

class Spawner : public Object{
  Game* game;
  int frame;
 
public:
  Spawner(Game* game);
  void step();
};
#endif

#ifndef SPAWNER2_H
#define SPAWNER2_H

class Spawner2 : public Object{
  Game* game;
  int frame;

public:
  Spawner2(Game* game);
  void step();
};
#endif
