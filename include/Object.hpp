#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <iostream>
#include <string>
#include <map>
#include <memory>
using namespace std;

class Object;
using Object_ptr = shared_ptr<Object>;
using Objects_map = map<int,Object_ptr>;

class Object: public enable_shared_from_this<Object> {
public:
    Object(string, string);

    /* pure virtual function */
    virtual bool triggerEvent(Object_ptr) = 0;

    /* Set & Get function*/
    void setName(string);
    void setTag(string);
    string getName();
    string getTag();

private:
    string name;
    string tag;
};

#endif // OBJECT_H_INCLUDED
