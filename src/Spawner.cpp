#include "Spawner.h"
#include <cmath>
Spawner::Spawner(Game* game) : Object(0, 0, 0, 0), game(game){
  frame = 0;
}

void Spawner::step(){
  if(frame++ % 60 == 0){
    for(double i = 0; i < M_PI * 2; i += M_PI / 10){
      game->createObject(new Projectile(game, 320, 240, 1, i + frame / 10));
    }
  }
}
