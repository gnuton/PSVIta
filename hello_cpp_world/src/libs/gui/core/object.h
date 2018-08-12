#ifndef OBJECT_H
#define OBJECT_H
#include <set>

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
    Object(Object *parent);
    virtual ~Object();

    const Object* getParent() const { return parent; }
    void setParent(Object* parent) { this->parent = parent; }

    virtual bool isWidget() const = 0;
    virtual bool isWindow() const = 0;

protected:
   std::set<const Object *> children;

private:
    Object *parent;

};

#endif // OBJECT_H
