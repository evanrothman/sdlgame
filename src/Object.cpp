#include "Object.h"
#include <iostream>

Object::Object(float x, float y, float h, float w)
  : x(x), y(y), h(h), w(w){
  body = {x - (w / 2), y - (h / 2), w, h};
  type = "object";
}

std::string Object::getType() const{
  return this->type;
}

void Object::step(){
  //nothing
}
