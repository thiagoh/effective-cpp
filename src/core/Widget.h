/*
 * Widget.h
 *
 *  Created on: Aug 9, 2015
 *      Author: thiago
 */

#ifndef SRC_CORE_WIDGET_H_
#define SRC_CORE_WIDGET_H_

class Widget {
public:
	Widget();
	virtual ~Widget();
private:
	WidgetImpl* p;
};

#endif /* SRC_CORE_WIDGET_H_ */
