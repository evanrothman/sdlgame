#include "Spawner.h"
#include <cmath>
Spawner::Spawner(Game* game) : Object(0, 0, 0, 0), game(game){
  frame = 0;
}

void Spawner::step(){
  if(frame++ % 3 == 0){
      game->createObject(new Projectile(game, 320, 240, 1, frame / 3.0));
  }
  if(frame > 1000){
    game->createObject(new Spawner2(game));
    game->destroy(this);
  }
}

Spawner2::Spawner2(Game* game) : Object(0, 0, 0, 0), game(game){
  frame = 0;
}

void Spawner2::step(){
  if(frame % 40 == 0){
    for(int i = 0; i < game->width; i += 60){
      game->createObject(new Projectile(game, i + ((frame % 80 == 0) ? 40 : 0),-w, 2, M_PI / 2));
    }
  }
  if(++frame > 1000){
    game->createObject(new Spawner(game));
    game->destroy(this);
  }
}
