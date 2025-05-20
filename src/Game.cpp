#include "Game.h"

Game::Game(int width, int height){
  SDL_Init(SDL_INIT_VIDEO);
  this->width = width;
  this->height = height;
  window = SDL_CreateWindow("SDL3", width, height, 0);
  renderer = SDL_CreateRenderer(window, NULL);
  keyboard_state = SDL_GetKeyboardState(NULL);
}

void Game::createObject(Object* o){
  for(int i = 0; i < objects.size(); i++){
    if(objects[i] == NULL){
      objects[i] = o;
      return;
    }
  }
  objects.push_back(o);
}

void Game::destroy(int i){
  delete objects[i];
  objects[i] = NULL;
}

void Game::destroy(Object* o){
  for(int i = 0; i < objects.size(); i++){
    if(o == objects[i]){
      destroy(i);
      return;
    }
  }
}
