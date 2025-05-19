#include <SDL3/SDL.h>
#include <vector>
#include <iostream>
#include "Object.h"
#include "Player.h"
#include "Projectile.h"
#include "Game.h"

void clear(SDL_Renderer* renderer){
  SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);
}

//Should be called every frame of the frame, returns 0 is quitting
int step(Game* game){
  //clear and setup
  clear(game->renderer);
  SDL_PumpEvents();
  for(int i = 0; i < game->objects.size(); i++){ 
    game->objects[i]->step();
  }
  
  SDL_RenderPresent(game->renderer);
  
  if(game->keyboard_state[SDL_SCANCODE_ESCAPE]){return 0;}
  return 1;
}

int main(){
  Game game(640, 480);
  game.objects.push_back(new Player(&game, 100, 100, 5));
  game.objects.push_back(new Projectile(&game, 300, 300, 0, 0));

  while(1){
    if(!step(&game)) return 0;
    SDL_Delay(10);
  }

  SDL_Quit();
  return 0;
}
