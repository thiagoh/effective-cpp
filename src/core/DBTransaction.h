/*
 * DBTransaction.h
 *
 *  Created on: Jul 25, 2015
 *      Author: thiago
 */

#ifndef SRC_CORE_DBTRANSACTION_H_
#define SRC_CORE_DBTRANSACTION_H_

#include "Transaction.h"

class DBTransaction: public Transaction {
public:
	DBTransaction();
	virtual ~DBTransaction();

	void log();
};

#endif /* SRC_CORE_DBTRANSACTION_H_ */
