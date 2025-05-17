#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <SDL3/SDL.h>

class Object{
public:
  SDL_FRect body;
  std::string type;
  virtual void step();
};

#endif
