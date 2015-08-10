/*
 * Widget.h
 *
 *  Created on: Jul 18, 2015
 *      Author: thiago
 */

#ifndef WIDGET_H_
#define WIDGET_H_

class WidgetImpl {
public:
	WidgetImpl();
	WidgetImpl(const WidgetImpl& rhs);
	virtual ~WidgetImpl();

	void doSomethingWithCopy(const WidgetImpl rhs);
	void doSomethingWithoutCopy(const WidgetImpl& rhs);

	WidgetImpl& operator=(const WidgetImpl& rhs);
};

#endif /* WIDGET_H_ */
