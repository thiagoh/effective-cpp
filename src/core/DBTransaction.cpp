/*
 * DBTransaction.cpp
 *
 *  Created on: Jul 25, 2015
 *      Author: thiago
 */

#include "DBTransaction.h"
#include <stdio.h>

DBTransaction::DBTransaction() {

}

DBTransaction::~DBTransaction() {
	printf("DBTransaction::~DBTransaction() running\n");
}

void DBTransaction::log() {
	printf("DBTransaction::log() running\n");
}
