#ifndef LISTVIEW_H
#define LISTVIEW_H

#include "View.h"

class ListView : public View
{
public:
    ListView();
    int Display() override;
};

#endif // LISTVIEW_H
