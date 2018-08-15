#ifndef OBJECT_H
#define OBJECT_H
#include <set>
#include "Signal.h"

/**
 * @brief The Object class
 * The Object class is the base class of all objects in this lib.
 * It's an abstract class so it must be subclassed.
 * Object have parent and children. They live in a tree.
 * The tree should help developers to prevent memory leaks since
 * deleting the parents will delete the children.
 */

class Object
{
public:
    explicit Object(Object *parent);
    virtual ~Object();

    virtual const Object* getParent() const final;
    virtual void setParent(Object* parent) final;

    virtual bool isWidget() const = 0;
    virtual bool isWindow() const = 0;

    virtual bool removeChild(Object* child) final;
    virtual bool addChild(Object* child) final;

    Signal<const Object*> destroyed;

protected:
    std::set<Object *> children;

private:
    Object *parent;

};

#endif // OBJECT_H
