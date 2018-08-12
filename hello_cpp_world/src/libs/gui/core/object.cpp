#include "object.h"

Object::Object(Object *parent){
    this->setParent(parent);
}

Object::~Object() {
    for (auto child : children) {
        delete child;
    }
    children.clear();
}
