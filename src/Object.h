#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <SDL3/SDL.h>

class Object{
public:
  float x, y, h, w;
  SDL_FRect body;
  
  Object(float x, float y, float h, float w);
  std::string type;
  std::string getType() const;
  virtual void step();
};

#endif
