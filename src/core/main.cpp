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
#include "SharedPtr.h"

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

	printf("\n\nSTEP 2\n\n");

	Transaction* tx1 = new DBTransaction();
	delete tx1;

	printf("\n\nSTEP 3\n\n");

	Transaction* tx2 = new DBTransaction();
	Transaction* tx3 = new Transaction();
	tx2->log();
	tx3->log();

	printf("\n\nSTEP 4\n\n");

	DBTransaction tx4;
	DBTransaction tmpDBTX;
	Transaction* tx5 = &tmpDBTX;
	tx4.log();
	tx5->log();

	printf("\n\n\n\n");

	delete tx2;

	printf("\n\n\n\nSTEP 5\n\n");

	{
		SharedPtr<Transaction> s1(new Transaction());
		s1.get()->log();

		{
			SharedPtr<Transaction> s2(s1);
			SharedPtr<Transaction> s3(s2);
			SharedPtr<Transaction> s4(s3);
			{
				SharedPtr<Transaction> s5(s2);
				s5 = s3;
			}
			SharedPtr<Transaction> s6 = s3;
			s6 = s4;
			s6 = s3;
			s6 = s2;
			s6 = s1;
			SharedPtr<Transaction> *ptr;
			ptr = &s6;
			s6 = *ptr;
		}
	}

	printf("\n\n\n\n END OF PROGRAM\n");
}



