/*
 * VSharedPtr.h
 *
 *  Created on: Jul 27, 2015
 *      Author: Thiago Andrade
 */

#ifndef SRC_CORE_VERBOSESHAREDPTR_H_
#define SRC_CORE_VERBOSESHAREDPTR_H_

#include <stdio.h>

/*
 * Implementing a simple smart pointer in C++
 * http://www.codeproject.com/Articles/15351/Implementing-a-simple-smart-pointer-in-c
 */

template<typename T>
class VSharedPtr {
public:
	VSharedPtr(T* ptr) :
			_ptr(ptr), _c(0) {
		_c = new Counter(0);
		_c->addRef();
	}

	VSharedPtr(const VSharedPtr<T>& rhs) :
			_ptr(rhs._ptr), _c(rhs._c) {
		_addRef(rhs);
	}

	VSharedPtr<T>& operator=(const VSharedPtr<T>& rhs) {
		if (this == &rhs) {
			printf("I've fallen into identity test!\n");
			return *this;
		}
		_c->releaseRef();
		_addRef(rhs);
		return *this;
	}

	T& operator*() {
		return *_ptr;
	}

	T* operator->() {
		return _ptr;
	}

	virtual ~VSharedPtr() {
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

	void _addRef(const VSharedPtr<T>& rhs) {
		_ptr = rhs._ptr;
		_c = rhs._c;
		_c->addRef();
	}

	class Counter {
	public:
		Counter(unsigned int c) :
				_refs(c) {
			printf("Counter ctor\n");
		}
		Counter(const Counter& rhs) :
				_refs(rhs._refs) {
			printf("Counter copy ctor\n");
		}
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
	// This members order matters
	T* _ptr;
	Counter* _c;
};

#endif /* SRC_CORE_VERBOSESHAREDPTR_H_ */
