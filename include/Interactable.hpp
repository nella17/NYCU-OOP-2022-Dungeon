#ifndef INTERACTABLE_H_INCLUDED
#define INTERACTABLE_H_INCLUDED

#include <string>
#include <memory>
#include "Object.hpp"

class Interactable;
using InteractablePtr = std::shared_ptr<Interactable>;

constexpr int LEAVE_KEY = 0x4C4C;

class Interactable: public Object {
public:
    Interactable(std::string _name, Object::Type _type): Object(_name, _type) {}
    virtual void print_status(InteractablePtr = nullptr) = 0;
    virtual void print_menu() = 0;
    virtual bool handle_key(int, ObjectPtr = nullptr) = 0;
    bool trigger_event(ObjectPtr);

private:
};

std::ostream& operator<<(std::ostream& os, const Interactable& interact);

#endif // INTERACTABLE_H_INCLUDED
