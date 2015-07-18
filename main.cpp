/*
 * main.cpp
 *
 *  Created on: Jul 18, 2015
 *      Author: thiago
 */

#include "Widget.h"

int main(int argc, char **argv) {

	Widget* wp;
	*wp = Widget();
	Widget w1 = *wp;
	Widget w2(w1);
	w2 = w1;
	w2 = *wp;
}



