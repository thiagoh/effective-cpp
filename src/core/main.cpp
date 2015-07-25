/*
 * main.cpp
 *
 *  Created on: Jul 18, 2015
 *      Author: thiago
 */
#include <stdio.h>
#include <iostream>
#include "Transaction.h"
#include "DBTransaction.h"
#include "Widget.h"
#include "TextBlock.h"

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

	printf("\n\n\n\n\n\n\n");

	TextBlock tb("Hello");
	const TextBlock ctb("const Hello");

	std::cout << tb[0] << std::endl;
	std::cout << ctb[0] << std::endl;

	tb[0] = 'x';
	//ctb[0] = 'x';

	std::cout << tb[0] << std::endl;
	std::cout << ctb[0] << std::endl;

	printf("\n\n\n\n\n\n\n");

	Transaction* dbTx = new DBTransaction();
//	Transaction* tx = dbTx;

//	delete tx;
	delete dbTx;

	printf("\n\n\n\n\n\n\n");
}



