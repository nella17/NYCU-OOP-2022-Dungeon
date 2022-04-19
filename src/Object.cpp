#include "Object.hpp"

#include <iostream>
#include "helper.hpp"

Object::Object(std::string _name, Type _type): name(_name), type(_type) {}

void Object::set_name(std::string _name) { name = _name; }
void Object::set_type(Type _type) { type = _type; }
std::string Object::get_name() const { return name; }
Object::Type Object::get_type() const { return type; }
