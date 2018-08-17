#include <utils/Logger.h>
#include "Object.h"

Object::Object(Object *parent){
    setParent(parent);
}

Object::~Object() {
    disconnectAll();

    for (auto child : children) {
        delete child;
    }
    children.clear();
}

const Object* Object::getParent() const {
    return this->parent;
}

void Object::setParent(Object* parent) {
    if (this->parent)
        parent->removeChild(this);

    this->parent = parent;
    if (this->parent)
        this->parent->addChild(this);
}

bool Object::removeChild(Object* child) {
    if (!child)
        return false;

    return this->children.erase(child);
}

bool Object::addChild(Object* child) {
    if (!child)
        return false;
    this->children.insert(child);
    child->disconnectAll();
    child->requestDestroy.connectMember(this, &Object::onRequestChildDestroy);
    return true;
}

void Object::destroy() {
    requestDestroy.emit(this);
}

void Object::onRequestChildDestroy(Object* child) {
    if (children.find(child) == children.end())
        return;
    child->destroying.emit(child);
    bool removed = removeChild(child);
    Logger::getInstance()->Debug(FORMAT("Child " << child << (removed? " has been correctly removed" : " has not been removed")));
}

void Object::disconnectAll() {
    destroying.disconnectAll();
    requestDestroy.disconnectAll();
}
