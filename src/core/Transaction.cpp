/*
 * Transaction.cpp
 *
 *  Created on: Jul 25, 2015
 *      Author: thiago
 */

#include "Transaction.h"
#include <stdio.h>

Transaction::Transaction() {

}

Transaction::~Transaction() {
	printf("Transaction::~Transaction() running\n");
}

void Transaction::log() {
	printf("Transaction::log() running\n");
}
