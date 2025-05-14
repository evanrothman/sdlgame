#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL.h>

class Player{
private:
  struct Game* game;
  float speed;
  SDL_FRect body;
  const bool* ks;
public:
  Player(struct Game* game, float x, float y, float speed);
  void step();
  void move(int x, int y);
  int* getLocation();
};

#endif
