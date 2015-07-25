/*
 * Transaction.h
 *
 *  Created on: Jul 25, 2015
 *      Author: thiago
 */

#ifndef SRC_CORE_TRANSACTION_H_
#define SRC_CORE_TRANSACTION_H_

class Transaction {
public:
	Transaction();
	virtual ~Transaction();

	virtual void log() = 0;
};

#endif /* SRC_CORE_TRANSACTION_H_ */
