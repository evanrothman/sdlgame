#include "Game.h"

Game::Game(int width, int height){
  SDL_Init(SDL_INIT_VIDEO);
  this->width = width;
  this->height = height;
  window = SDL_CreateWindow("SDL3", width, height, 0);
  renderer = SDL_CreateRenderer(window, NULL);
  keyboard_state = SDL_GetKeyboardState(NULL);
}

