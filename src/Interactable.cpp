#include "Interactable.hpp"

#include "helper.hpp"

std::ostream& operator<<(std::ostream& os, const Interactable& interact) {
    auto s = enum_name(interact.get_type()) + '(' + interact.get_name() + ')';
    return os << s;
}
