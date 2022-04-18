#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "helper.hpp"
using namespace std;

class Object;
using Object_ptr = shared_ptr<Object>;
using Objects_map = map<int,Object_ptr>;

class Object: public enable_shared_from_this<Object> {
public:
    enum class Type {
        Unknown = 0,
        Item,
        Player,
        Monster,
        NPC,
    };

    Object(string, Object::Type);

    /* pure virtual function */
    virtual bool triggerEvent(Object_ptr) = 0;

    /* Set & Get function*/
    void setName(string);
    void setType(Object::Type);
    string getName();
    Object::Type getType();

private:
    string name;
    Object::Type type;
};

#endif // OBJECT_H_INCLUDED
