#include "Object.hpp"

Object::Object(string _name, Type _tag): name(_name), tag(_tag) {}

void Object::setName(string _name) { name = _name; }
void Object::setTag(Type _tag) { tag = _tag; }
string Object::getName() { return name; }
Object::Type Object::getTag() { return tag; }
