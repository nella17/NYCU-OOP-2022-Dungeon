#include "Interactable.hpp"

#include <stdexcept>
#include "helper.hpp"

bool Interactable::trigger_event(ObjectPtr obj) {
    throw std::runtime_error("You can't use " + obj->get_name() + " on " + get_name() + ".");
}

std::ostream& operator<<(std::ostream& os, const Interactable& interact) {
    auto s = enum_name(interact.get_type()) + '(' + interact.get_name() + ')';
    return os << s;
}
