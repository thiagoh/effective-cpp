/*
 * main.cpp
 *
 *  Created on: Jul 18, 2015
 *      Author: thiago
 */
#include <stdio.h>
#include "Widget.h"

int main(int argc, char **argv) {

	Widget* wp;
	*wp = Widget();
	Widget w1 = *wp;
	Widget w2(w1);
	w2 = w1;
	w2 = *wp;
	printf("START w2.doSomethingWithCopy(w1);\n");
	w2.doSomethingWithCopy(w1);
	printf("END w2.doSomethingWithCopy(w1);\n");
	printf("START w2.doSomethingWithoutCopy(w1);\n");
	w2.doSomethingWithoutCopy(w1);
	printf("END w2.doSomethingWithoutCopy(w1);\n");
}



