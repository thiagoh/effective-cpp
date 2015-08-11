/*
 * Widget.h
 *
 *  Created on: Aug 9, 2015
 *      Author: thiago
 */

#ifndef SRC_CORE_WIDGET_H_
#define SRC_CORE_WIDGET_H_

#include "WidgetImpl.h"
#include <algorithm>

/*
 * PImpl nice examples and explanations
 * http://cplusplus.bordoon.com/copyConstructors.html
 */

class Widget {
public:
	Widget(): p(new WidgetImpl()) {
	}
	Widget(const Widget& rhs): p(new WidgetImpl(*rhs.p)) {
	}
	Widget& operator=(const Widget& rhs) {

		if (this == &rhs) {
			return *this;
		}

		this->Widget::~Widget();

		p = new WidgetImpl(*rhs.p);
		return *this;
	}
	virtual ~Widget() {
		printf("\n\ndelete p!!\n\n");
		delete p;
	}
	void swap(Widget& rhs) {
		using std::swap;
		swap(p, rhs.p);
	}
	WidgetImpl& operator*() {
		return *p;
	}
	WidgetImpl* operator->() {
		return p;
	}
	void doSomethingWithCopy(const Widget rhs) {
		p->doSomethingWithCopy(*rhs.p);
	}
	void doSomethingWithoutCopy(const Widget& rhs) {
		p->doSomethingWithoutCopy(*rhs.p);
	}
private:
	WidgetImpl* p;
};

namespace std{

	template<>
	void swap<Widget>(Widget& w1, Widget& w2) {
		w1.swap(w2);
	}
}

void swap(Widget& w1, Widget& w2) {
	w1.swap(w2);
}

#endif /* SRC_CORE_WIDGET_H_ */
