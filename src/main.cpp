#include <SDL3/SDL.h>
#include "Player.h"
#include "Game.h"

//Initializes everything
void init(Game* game){
}

void clear(SDL_Renderer* renderer){
  SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);
}

//Should be called every frame of the frame, returns 0 is quitting
int step(Game* game){
  //clear and setup
  clear(game->renderer);
  SDL_PumpEvents();
  
  game->player->step();
  
  SDL_RenderPresent(game->renderer);
  
  if(game->keyboard_state[SDL_SCANCODE_ESCAPE]){return 0;}
  return 1;
}

int main(){
  Game game;
  init(&game);
  
  while(1){
    if(!step(&game)) return 0;
    SDL_Delay(10);
  }

  SDL_Quit();
  return 0;
}
