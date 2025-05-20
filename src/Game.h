#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>
#include <vector>
#include "Object.h"

class Game{
public:
  SDL_Window* window;
  SDL_Renderer* renderer;
  int height;
  int width;
  std::vector<Object*> objects;
  const bool* keyboard_state;
  
  void createObject(Object* o);
  Game(int width, int height);
};

#endif
