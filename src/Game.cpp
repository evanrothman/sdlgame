#include "Game.h"

Game::Game(){
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("SDL3", 640, 480, 0);
  renderer = SDL_CreateRenderer(window, NULL);
  keyboard_state = SDL_GetKeyboardState(NULL);
}

