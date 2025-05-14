#include <SDL3/SDL.h>
#include "Player.h"

struct Game{
  SDL_Window* window; 
  SDL_Renderer* renderer;
  Player* player;
  const bool* keyboard_state;
};

//Initializes everything
void init(struct Game* game){
  SDL_Init(SDL_INIT_VIDEO);
  game->window = SDL_CreateWindow("SDL3", 640, 480, 0);
  game->renderer = SDL_CreateRenderer(game->window, NULL);
  game->player = new Player(100, 100, 5);
  game->keyboard_state = SDL_GetKeyboardState(NULL);
}

//Should be called every frame of the frame, returns 0 is quitting
int step(struct Game* game){
  Player* player = game->player;
  SDL_SetRenderDrawColor(game->renderer, 0xff, 0xff, 0xff, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(game->renderer);
  SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  player->drawSelf(game->renderer);
  SDL_RenderPresent(game->renderer);
  SDL_PumpEvents();
  const bool* ks = game->keyboard_state;
  if(ks[SDL_SCANCODE_ESCAPE]){return 0;}
  float x = ks[SDL_SCANCODE_D] - ks[SDL_SCANCODE_A];
  float y = ks[SDL_SCANCODE_S] - ks[SDL_SCANCODE_W];
  player->move(x, y);
  return 1;
}

int main(){
  struct Game game;
  init(&game);
  //This will eventually be a while loop
  while(1){
    if(!step(&game)) return 0;
    SDL_Delay(10);
  }
  SDL_Quit();
  return 0;
}
