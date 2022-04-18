#include "Object.hpp"

Object::Object(string _name, Type _type): name(_name), type(_type) {}

void Object::setName(string _name) { name = _name; }
void Object::setType(Type _type) { type = _type; }
string Object::getName() { return name; }
Object::Type Object::getType() { return type; }
