#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

struct Game{
  SDL_Window* window; 
  SDL_Renderer* renderer;
  SDL_FRect rectangle;
  const bool* keyboard_state;
};

//Initializes everything
void init(struct Game* game){
  SDL_Init(SDL_INIT_VIDEO);
  game->window = SDL_CreateWindow("SDL3", 640, 480, 0);
  game->renderer = SDL_CreateRenderer(game->window, NULL);
  game->rectangle = {100, 100, 100, 100};
  game->keyboard_state = SDL_GetKeyboardState(NULL);
}

//Should be called every frame of the frame, returns 0 is quitting
int step(struct Game* game){
  SDL_SetRenderDrawColor(game->renderer, 0xff, 0xff, 0xff, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(game->renderer);
  SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderFillRect(game->renderer, &game->rectangle);
  SDL_RenderPresent(game->renderer);
  SDL_PumpEvents();
  const bool* ks = game->keyboard_state;
  if(ks[SDL_SCANCODE_ESCAPE]){return 0;}
  game->rectangle.x += ks[SDL_SCANCODE_D] - ks[SDL_SCANCODE_A];
  game->rectangle.y += ks[SDL_SCANCODE_S] - ks[SDL_SCANCODE_W];
  return 1;
}

int main(){
  struct Game game;
  init(&game);
  //This will eventually be a while loop
  while(1){
    if(!step(&game)) return 1;
    SDL_Delay(20);
  }
  SDL_Quit();
  return 1;
}
