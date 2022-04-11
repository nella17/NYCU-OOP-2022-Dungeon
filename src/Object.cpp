#include "Object.hpp"

Object::Object(string _name, string _tag): name(_name), tag(_tag) {}

void Object::setName(string _name) { name = _name; }
void Object::setTag(string _tag) { tag = _tag; }
string Object::getName() { return name; }
string Object::getTag() { return tag; }
