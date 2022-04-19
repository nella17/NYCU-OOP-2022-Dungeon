#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <string>
#include <map>
#include <memory>
class Record;

class Object;
using ObjectPtr = std::shared_ptr<Object>;
using ObjectsMap = std::map<int,ObjectPtr>;

class Object: public std::enable_shared_from_this<Object> {
    friend class Record;
public:
    enum class Type {
        None = 0,
        Item,
        Equip,
        Potion,
        Key,
        Lock,
        Player,
        Monster,
        NPC,
    };

    Object(std::string, Object::Type);

    /* pure virtual function */
    virtual bool trigger_event(ObjectPtr) = 0;

    /* Set & Get function*/
    void set_name(std::string);
    void set_type(Object::Type);
    std::string get_name() const;
    Object::Type get_type() const;

private:
    std::string name;
    Object::Type type;
};

#endif // OBJECT_H_INCLUDED
