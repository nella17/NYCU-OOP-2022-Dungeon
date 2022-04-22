#include "MsgBox.hpp"

#include <iostream>

std::vector<std::string> MsgBox::msg{};

void MsgBox::add(std::string s) {
    if (s.empty()) return;
    msg.emplace_back(s);
}

void MsgBox::clear() {
    msg.clear();
}

std::ostream& MsgBox::output(std::ostream& os) {
    for (auto&& s : msg)
        os << '\n' << s;
    clear();
    return os;
}

std::ostream& operator<<(std::ostream& os, const MsgBox&) {
    return MsgBox::output(os);
}
