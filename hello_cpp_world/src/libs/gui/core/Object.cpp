#include <utils/Logger.h>
#include "Object.h"

Object::Object(std::shared_ptr<Object> parent){
    setParent(parent);
}

Object::~Object() {
    disconnectAll();
    children.clear();
}

const std::shared_ptr<Object> Object::getParent() const {
    return this->parent;
}

void Object::setParent(std::shared_ptr<Object> parent) {
    if (this->parent)
        parent->removeChild(shared_from_this());

    this->parent = parent;
    if (this->parent)
        this->parent->addChild(shared_from_this());
}

bool Object::removeChild(std::shared_ptr<Object> child) {
    if (!child)
        return false;

    return this->children.erase(child);
}

bool Object::addChild(std::shared_ptr<Object> child) {
    if (!child)
        return false;
    this->children.insert(child);
    child->requestDestroy.connectMember(this, &Object::onRequestChildDestroy);
    return true;
}

void Object::destroy() {
    requestDestroy.emit(shared_from_this());
}

void Object::onRequestChildDestroy(std::shared_ptr<Object> child) {
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
