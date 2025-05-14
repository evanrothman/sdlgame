#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>
#include <vector>
#include "Object.h"

class Game{
public:
  SDL_Window* window;
  SDL_Renderer* renderer;
  std::vector<Object*> objects;
  const bool* keyboard_state;

  Game();
};

#endif
