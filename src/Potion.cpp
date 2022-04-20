#include "Potion.hpp"

#include <iostream>
#include "helper.hpp"

Potion::Potion(std::string _name, Type _type, int _value):
        Item(_name, Object::Type::Potion), type(_type), value(_value) {}

std::string Potion::name_of_type() const {
    return enum_name(get_type()) + "(" + enum_name(type) + ")";
}

std::ostream& Potion::show_info(std::ostream& os) const {
    return os
        << "value(" << value << ")";
}

int Potion::get_value() const { return value; }
