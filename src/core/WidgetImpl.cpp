/*
 * Widget.cpp
 *
 *  Created on: Jul 18, 2015
 *      Author: thiago
 */

#include "WidgetImpl.h"

#include <stdio.h>
#include <unistd.h>

WidgetImpl::WidgetImpl() {
	printf("widget constructor\n");
}

WidgetImpl::WidgetImpl(const WidgetImpl& rhs) {
	printf("widget copy constructor\n");
}

WidgetImpl::~WidgetImpl() {
	printf("widget destructor\n");
}

WidgetImpl& WidgetImpl::operator=(const WidgetImpl& rhs) {
	printf("widget assign operator\n");
	return *this;
}

void WidgetImpl::doSomethingWithCopy(const WidgetImpl rhs) {
	printf("executing doSomethingWithCopy\n");
}

void WidgetImpl::doSomethingWithoutCopy(const WidgetImpl& rhs) {
	printf("executing doSomethingWithoutCopy\n");
}
