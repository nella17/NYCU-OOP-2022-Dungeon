#ifndef MSGBOX_H_INCLUDED
#define MSGBOX_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

class MsgBox {
    friend class Record;
public:
    static void add(std::string);
    static void clear();
    static std::ostream& output(std::ostream&);
private:
    static std::vector<std::string> msg;
};

std::ostream& operator<<(std::ostream&, const MsgBox&);

#endif // MSGBOX_H_INCLUDED
