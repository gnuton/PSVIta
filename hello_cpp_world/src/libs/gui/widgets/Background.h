#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <core/Texture.h>
#include "View.h"

class Background : public View
{
public:
    explicit Background(std::shared_ptr<Object> parent);

    void draw() override;
private:
	Texture img_bg;
};
#endif

