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

#include <memory>

class Object : public std::enable_shared_from_this<Object>
{
public:
    explicit Object(std::shared_ptr<Object> parent);
    virtual ~Object();

    virtual const std::shared_ptr<Object> getParent() const final;
    virtual void setParent(std::shared_ptr<Object> parent) final;

    virtual bool isWidget() const = 0;
    virtual bool isWindow() const = 0;

    virtual bool removeChild(std::shared_ptr<Object> child) final;
    virtual bool addChild(std::shared_ptr<Object> child) final;

    virtual void destroy() final;

    Signal<std::shared_ptr<Object>> requestDestroy;
    Signal<std::shared_ptr<Object>> destroying;

    virtual void onRequestChildDestroy(std::shared_ptr<Object> child);

    void disconnectAll();

protected:
    std::set<std::shared_ptr<Object>> children;

private:
    std::shared_ptr<Object> parent;

};

#endif // OBJECT_H
