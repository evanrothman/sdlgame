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

//Should be called every frame of the frame
void step(struct Game* game){
    SDL_SetRenderDrawColor(game->renderer, 0xff, 0xff, 0xff, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(game->renderer);
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(game->renderer, &game->rectangle);
    SDL_RenderPresent(game->renderer);
    SDL_PumpEvents();
    const bool* keyboard_state = game->keyboard_state;
    game->rectangle.x += keyboard_state[SDL_SCANCODE_D] - keyboard_state[SDL_SCANCODE_A];
}

int main(){
  int i;
  struct Game game;
  init(&game);
  //This will eventually be a while loop
  for(i = 0; i < 200; i++){
    step(&game);
    SDL_Delay(20);
  }
  SDL_Quit();
  return 1;
}
