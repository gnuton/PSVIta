#ifndef VITATOUCH_H
#define VITATOUCH_H

#include <psp2/touch.h>
#include <string.h>
#include <core/Mathtools.hpp>

#define SLEEP_CLICK_NORMAL 150000
#define SLEEP_CLICK_EXTENDED 350000

#define MIN_DIST_TO_SCROLL_Y 2
#define MIN_DIST_TO_SCROLL_X 2

class VitaTouch{
	public:
		VitaTouch();
		void readTouch();
		SceTouchData touch_old[SCE_TOUCH_PORT_MAX_NUM];
		SceTouchData touch[SCE_TOUCH_PORT_MAX_NUM];
		vector2 getClickPoint();
		vector2 lastClickPoint;
		vector2 lastTouchPoint;
		bool clicking;
		bool scrolling;
		int scrollDirX ;
		int scrollDirY;

	private:
		void initTouch();
		
		vector2 emptyClickPoint;
		
};

#endif



