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
 *
 * To destroy an object call Object::destroy() which will emit requestDestroy to the parent.
 * The parent will run onRequestChildDestroy which will:
 * - emit destroying signal
 * - remove the child from the list of children
 * The destructor will be automatically invoked when the shared_ptr count reaches zero.
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

    virtual void destroy() final;

    /**
     * Signal emitted and catched only by the parent.
     * The parent remove the child from its list and destroys it
     */

    Signal<Object*> requestDestroy;

    /**
     * Signal emitted by the child object when it's destroying itself
     */
    Signal<Object*> destroying;

    /**
     * This slots gets called when a child is asking to be destroyed
     * @param child a pointer to the child be destroyed
     */
    virtual void onRequestChildDestroy(Object* child);

    /**
     * Disconnect the slots connected to this instance signals
     */
    void disconnectAll();

protected:
    std::set<Object *> children;

private:
    bool removeChild(Object* child);
    bool addChild(Object* child);


    std::map<Object*, int> requestDestroyMap;
    Object *parent;

};

#endif // OBJECT_H
