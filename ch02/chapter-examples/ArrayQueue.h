#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include "./array.h"
#include <algorithm>
#include <iostream>
#include <string>

// ===
// ArrayQueue
// ===

/**
 * Implements the (FIFO) Queue interface using a backing array.
 * Allows for efficient addition to one end of the sequence and removal from
 * the other end.
 *
 * Elements are removed (using remove()) in the same order they are added (using
 * add(x))
 *
 * Ignoring the cost of calls to resize, an ArrayStack supports:
 * 
 * 	- add(x) and remove() in O(1) time per operation
 *
 * Further, beginning with an empty ArrayQueue, performing any sequence
 * of m add(i, x) and remove(i) operations results in a total of O(m) time
 * cost per resize operation (amortized analysis).
 *
 * Using modular arithmetic, array queue simulates an infinite array as
 * i % a.length always gives a value in the range 0, ..., a.length - 1.
 *
 * Array a is treated like a circular array in which indices larger than
 * a.length - 1 "wrap around" to the beginning of the array.
 */
template <typename T>
class ArrayQueue {
public:
	array<T> a;
	int j;
	int n;

	ArrayQueue() : a(n = 0) {}

	// Print a description of the data structure
	std::string typeDesc() {
        return "2.3 | ArrayQueue: An Array-Based Queue";
    }

	// Test the data structure
	void test() {
		std::cout << "===" << std::endl;
		std::cout << this->typeDesc() << std::endl;
		std::cout << "===" << std::endl;

		this->add(1);
		std::cout << "ArrayQueue.add(1)" << std::endl;
		std::cout << "ArrayQueue.size() =  " << this->size() << std::endl;
		std::cout << std::endl;

		this->add(2);
		std::cout << "ArrayQueue.add(2)" << std::endl;
		std::cout << "ArrayQueue.size() =  " << this->size() << std::endl;
		std::cout << std::endl;

		this->add(3);
		std::cout << "ArrayQueue.add(3)" << std::endl;
		std::cout << "ArrayQueue.size() =  " << this->size() << std::endl;
		std::cout << std::endl;

		std::cout << "ArrayQueue.remove() = " << this->remove() << std::endl;
		std::cout << "ArrayQueue.size() =  " << this->size() << std::endl;
		std::cout << std::endl;

		std::cout << "ArrayQueue.get(1) = " << this->get(1) << std::endl;
		std::cout << "ArrayQueue.set(1, 4) = " << this->set(1, 4) << std::endl;
	}

	// get(i)
	T get(int i) {
		return a[i];
	}

	// set(i, x)
	T set(int i, T x) {
		T &y = a[i];
		a[i] = x;
		return y;
	}

	// ===
	// BASICS
	// ===

	// size()
	int size() {
		return n;
	}

	// add(x)
	bool add(T x) {
		// Check if a is already full
		// If so, resize so that a.length > n
		if (n + 1 > a.length) resize();

		// Set a[(j+n)/%a.length] equal to x and increment n
		a[(j+n)%a.length] = x;
		n++;

		return true;
	}

	// remove()
	T remove() {
		// Store a[j] so it can be returned later
		T x = a[j];

		// Increment j (modulo a.length) and decrement n
		j = (j + 1) % a.length;
		n--;

		// Check if n is getting too small
		if (a.length >= 3 * n) resize();

		return x;
	}

	// ===
	// GROWING / SHRINKING
	// ===
	
	// resize()
	// Operation is O(n)
	void resize() {
		// Create a new array that is double the size of the backing array
		array<T> b(std::max(2 * n, 1));

		// Copy n elements from a to b
		for (int k = 0; k < n; k++) {
			b[k] = a[(j+k)%a.length];
		}

		// Set backing array a to new backing array b
		a = b;

		// Set the value of j back to 0
		j = 0;
	}
};

#endif // ARRAYQUEUE_H
