#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

struct Game{
  SDL_Window* window; 
  SDL_Renderer* renderer;
  SDL_FRect rectangle;
};

//Initializes everything
void init(struct Game* game){
  SDL_Init(SDL_INIT_VIDEO);
  game->window = SDL_CreateWindow("SDL3", 640, 480, 0);
  game->renderer = SDL_CreateRenderer(game->window, NULL);
  game->rectangle = {100, 100, 100, 100};
}

//Should be called every frame of the frame
void step(struct Game* game){
    SDL_SetRenderDrawColor(game->renderer, 0xff, 0xff, 0xff, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(game->renderer);
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(game->renderer, &game->rectangle);
    SDL_RenderPresent(game->renderer);
    game->rectangle.x++;
    game->rectangle.y++;
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
