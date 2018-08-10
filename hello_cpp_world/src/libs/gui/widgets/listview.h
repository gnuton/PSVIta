#ifndef LISTVIEW_H
#define LISTVIEW_H

#include "view.h"

class ListView : public View
{
public:
    ListView();
    int Draw() override;
};

#endif // LISTVIEW_H
