/*
 * Widget.h
 *
 *  Created on: Jul 18, 2015
 *      Author: thiago
 */

#ifndef WIDGET_H_
#define WIDGET_H_

class Widget {
public:
	Widget();
	Widget(const Widget& rhs);
	virtual ~Widget();

	Widget& operator=(const Widget& rhs);
};

#endif /* WIDGET_H_ */
