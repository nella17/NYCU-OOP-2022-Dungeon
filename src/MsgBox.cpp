#include "MsgBox.hpp"

std::vector<std::string> MsgBox::msg{};

void MsgBox::add(std::string s) {
    if (s.empty()) return;
    msg.emplace_back(s);
}

std::ostream& MsgBox::output(std::ostream& os) {
    for (auto&& s : msg)
        os << s << '\n';
    msg.clear();
    return os;
}

std::ostream& operator<<(std::ostream& os, const MsgBox&) {
    return MsgBox::output(os);
}
