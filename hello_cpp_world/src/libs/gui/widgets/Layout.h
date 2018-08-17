#ifndef LAYOUT_H
#define LAYOUT_H

#include "utils/macros.h"

class Layout {
public:
    virtual void addWidget() = 0;
};

class VerticalLayout : public  Layout {
    NO_COPY_AND_ASSIGN(VerticalLayout)

public:
    void addWidget() override;
};

#endif
