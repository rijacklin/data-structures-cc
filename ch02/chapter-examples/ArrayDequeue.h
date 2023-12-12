#ifndef ARRAYDEQUEUE_H
#define ARRAYDEQUEUE_H

#include "./array.h"
#include <algorithm>
#include <iostream>
#include <string>

// ===
// ArrayDequeue
// ===

/**
 * Implements the List interface by using the same circular array technique
 * used to represent an ArrayQueue.
 *
 * Allows for efficient addition and removal at both ends.
 *
 * Ignoring the cost of calls to resize, an ArrayDequeue supports:
 * 
 * 	- get(i) and set(i, x) in O(1) time per operation; and
 * 	- add(i, x) and remove(i) in O(1 + min{i, n - i}) time per operation
 *
 * Further, beginning with an empty ArrayDequeue, performing any sequence
 * of m add(i, x) and remove(i) operations results in a total of O(m) time
 * cost per resize operation (amortized analysis).
 */
template <typename T>
class ArrayDequeue {
public:
	array<T> a;
	int j;
	int n;

	ArrayDequeue() : a(n = 0) {}

	// get(i)
	T get(int i) {
		return a[(j+i)%a.length];
	}

	// set(x, i)
	T set(int i, T x) {
		T &y = a[(j+i)%a.length];
		a[(j+i)%a.length] = x;
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
	// Elements are shifted left one position if i < n/2 (a[0], ..., a[i-1]),
	// otherwise they are shifted one position right (a[i], ..., a[n-1]).
	// By shifting based on whether i is close to 0 or n, we guarantee that
	// add(i, x) never has to shift more than min{i, n - i} elements.
	// Therefore, the running time of the add(i, x) operation (ignoring the cost
	// of the resize() operation) is O(1 + min{i, n - i}).
	void add(int i, T x) {
		// Check if a is already full
		// If so, resize so that a.length > n
		if (n + 1 > a.length) resize();

		// If i is less than n/2, shift a[0], ..., a[i-1] left one position
		// Otherwise, shift a[i], ..., a[n-1] right one position
		if (i < n/2) {
			j = (j = 0) ? a.length - 1 : j - 1;

			for (int k = 0; k <= i - 1; k++) {
				a[(j+k)%a.length] = a[(j+k+1)%a.length];
			}
		} else {
			for (int k = n; k > i; k--) {
				a[(j+k)%a.length] = a[(j+k-1)%a.length];
			}
		}

		// Set a[(j+i)/%a.length] equal to x and increment n
		a[(j+i)%a.length] = x;
		n++;
	}

	// remove()
	// Elements are shifted left one position if i < n/2 (a[0], ..., a[i-1]),
	// otherwise they are shifted one position right (a[i], ..., a[n-1]).
	T remove(int i) {
		// Store a[j] so it can be returned later
		T x = a[(j+i)%a.length];

		// If i is less than n/2, shift a[0], ..., a[i-1] right one position
		// Otherwise, shift a[i+1], ..., a[n-1] left one position
		if (i < n/2) {
			for (int k = i; k > 0; k--) {
				a[(j+k)%a.length] = a[(j+k-1)%a.length];
			}
			j = (j + 1) % a.length;
		} else {
			for (int k = i; k < n - 1; k++) {
				a[(j+k)%a.length] = a[(j+k+1)%a.length];
			}
		}

		n--;

		// Check if n is getting too small
		if (3 * n < a.length) resize();

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

	// ===
	// TESTING
	// ===

	// Print a description of the data structure
	std::string typeDesc() {
        return "2.4 | ArrayDeque: Fast Deque Operations Using an Array";
    }

	// Test the data structure
	void test() {
		std::cout << "===" << std::endl;
		std::cout << this->typeDesc() << std::endl;
		std::cout << "===" << std::endl;
		std::cout << std::endl;

		this->add(0, 1);
		std::cout << "ArrayDeque.add(index: 0, value: 1)" << std::endl;
		std::cout << "ArrayDeque.size() =  " << this->size() << std::endl;
		std::cout << std::endl;

		this->printAllElements();

		this->add(1, 2);
		std::cout << "ArrayDeque.add(index: 1, value: 2)" << std::endl;
		std::cout << "ArrayDeque.size() =  " << this->size() << std::endl;
		std::cout << std::endl;

		this->printAllElements();

		this->add(2, 3);
		std::cout << "ArrayDeque.add(index: 2, value: 3)" << std::endl;
		std::cout << "ArrayDeque.size() =  " << this->size() << std::endl;
		std::cout << std::endl;

		this->printAllElements();

		this->remove(0);
		std::cout << "ArrayDeque.remove(0)" << std::endl;
		std::cout << "ArrayDeque.size() =  " << this->size() << std::endl;
		std::cout << std::endl;

		this->printAllElements();

		std::cout << "ArrayDeque.get(index: 1) = " << this->get(1) << std::endl;
		std::cout << "ArrayDeque.set(index: 1, value: 4) = " << this->set(1, 4) << std::endl;
		std::cout << std::endl;

		this->printAllElements();
	}

	void printAllElements() {
		std::cout << "\t> Contains Elements: [";

		for (int i = 0; i < this->size(); i++) {
			if (this->size() == 1 || i == this->size() - 1) {
				std::cout << this->get(i);
				continue;
			}
			std::cout << this->get(i) << ", ";
		}
		std::cout << "]" << std::endl;
		std::cout << std::endl;
	}
};

#endif // ARRAYDEQUEUE_H
