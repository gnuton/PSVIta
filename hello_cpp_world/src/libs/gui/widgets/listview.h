#ifndef LISTVIEW_H
#define LISTVIEW_H

#include "view.h"

class ListView : public View
{
public:
    ListView(View* parent);
    int draw() override;
};

#endif // LISTVIEW_H
