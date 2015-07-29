/*
 * SharedPtr.h
 *
 *  Created on: Jul 27, 2015
 *      Author: thiago
 */

#ifndef SRC_CORE_SHAREDPTR_H_
#define SRC_CORE_SHAREDPTR_H_

#include <stdio.h>

/*
 * Implementing a simple smart pointer in C++
 * http://www.codeproject.com/Articles/15351/Implementing-a-simple-smart-pointer-in-c
 */

template<typename T>
class SharedPtr {
public:
	SharedPtr(T* ptr):
		_ptr(ptr), _c(0) {
		_c = new Counter(0);
		_c->addRef();
	}

	SharedPtr(const SharedPtr<T>& rhs) :
		_ptr(rhs._ptr), _c(rhs._c) {
		_addRef(rhs);
	}

	SharedPtr<T>& operator=(const SharedPtr<T>& rhs) {
		if (this == &rhs) {
			printf("I've fallen into identity test!\n");
			return *this;
		}
		_c->releaseRef();
		_addRef(rhs);
		return *this;
	}

	T& operator*() {
		return *this;
	}

	T* operator->() {
		return this;
	}

	virtual ~SharedPtr() {
		_c->releaseRef();
		if (_c->get() == 0) {
			delete _ptr;
			delete _c;
			printf("DO deleting ptr\n");
		} else {
			printf("NOT deleting ptr\n");
		}
	}

	T* get() {
		return _ptr;
	}
private:

	void _addRef(const SharedPtr<T>& rhs) {
		_ptr = rhs._ptr;
		_c = rhs._c;
		_c->addRef();
	}

	class Counter {
	public:
		Counter(unsigned int c): _refs(c) {
			printf("Counter ctor\n");
		};
		Counter(const Counter& rhs): _refs(rhs._refs) {
			printf("Counter copy ctor\n");
		};

		~Counter() {
		}
		unsigned int get() {
			return _refs;
		}
		void addRef() {
			++_refs;
		}

		void releaseRef() {
			--_refs;
		}

	private:
		unsigned int _refs;
	};
	T* _ptr;
	Counter* _c;
};

#endif /* SRC_CORE_SHAREDPTR_H_ */
