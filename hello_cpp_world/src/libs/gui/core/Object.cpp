#include "Object.h"

Object::Object(Object *parent){
    this->setParent(parent);
}

Object::~Object() {
    for (auto child : children) {
        delete child;
    }
    children.clear();
    this->destroyed.emit(this);
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
    else
        return this->children.erase(child);
}

bool Object::addChild(Object* child) {
    if (!child)
        return false;
    this->children.insert(child);
    return true;
}
