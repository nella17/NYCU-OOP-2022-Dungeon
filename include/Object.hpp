#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <string>
#include <map>
#include <memory>

class Object;
using Object_ptr = std::shared_ptr<Object>;
using Objects_map = std::map<int,Object_ptr>;

class Object: public std::enable_shared_from_this<Object> {
public:
    enum class Type {
        Unknown = 0,
        Item,
        Equipment,
        Potion,
        Key,
        Lock,
        Player,
        Monster,
        NPC,
    };

    Object(std::string, Object::Type);

    /* pure virtual function */
    virtual bool triggerEvent(Object_ptr) = 0;

    /* Set & Get function*/
    void setName(std::string);
    void setType(Object::Type);
    std::string getName();
    Object::Type getType();

private:
    std::string name;
    Object::Type type;
};

#endif // OBJECT_H_INCLUDED
