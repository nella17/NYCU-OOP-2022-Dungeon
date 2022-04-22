#include "Interactable.hpp"

#include <stdexcept>
#include "helper.hpp"

bool Interactable::trigger_event(ObjectPtr obj) {
    throw std::runtime_error("You can't use " + obj->get_name() + " on " + get_name() + ".");
}

std::string Interactable::get_name_type() const {
    return enum_name(get_type()) + '(' + get_name() + ')';
}

std::ostream& operator<<(std::ostream& os, const Interactable& interact) {
    return os << interact.get_name_type();
}
