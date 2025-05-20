#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL.h>
#include "Game.h"

class Player : public Object{
private:
  Game* game;
  float speed;
  const bool* ks;
  
  bool checkCollision(Object* object);
  void move(int x, int y);
public:
  int hp;
  Player(Game* game, float x, float y, float speed);
  void step();
};

#endif
