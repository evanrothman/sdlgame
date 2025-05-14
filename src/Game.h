#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>
#include "Player.h"

class Game{
public:
  SDL_Window* window;
  SDL_Renderer* renderer;
  Player* player;
  const bool* keyboard_state;

  Game();
};

#endif
