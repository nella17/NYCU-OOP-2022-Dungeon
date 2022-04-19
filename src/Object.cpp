#include "Object.hpp"

#include <iostream>
#include "helper.hpp"

Object::Object(std::string _name, Type _type): name(_name), type(_type) {}

void Object::setName(std::string _name) { name = _name; }
void Object::setType(Type _type) { type = _type; }
std::string Object::getName() { return name; }
Object::Type Object::getType() { return type; }
