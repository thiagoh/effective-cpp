/*
 * Widget.cpp
 *
 *  Created on: Jul 18, 2015
 *      Author: thiago
 */

#include <stdio.h>
#include <unistd.h>
#include "Widget.h"

Widget::Widget() {
	printf("widget constructor\n");
}

Widget::Widget(const Widget& rhs) {
	printf("widget copy constructor\n");
}

Widget::~Widget() {
	printf("widget destructor\n");
}

Widget& Widget::operator=(const Widget& rhs) {
	printf("widget assign operator\n");
	return *this;
}

void Widget::doSomethingWithCopy(const Widget rhs) {
	printf("executing doSomethingWithCopy\n");
	sleep(1);
}

void Widget::doSomethingWithoutCopy(const Widget& rhs) {
	printf("executing doSomethingWithoutCopy\n");
}
