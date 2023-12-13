#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "./array.h"
#include <iostream>

// ===
// ArrayStack
// ===
// Implements the List interface using a backing array.
template <typename T>
class ArrayStack {
public:
	array<T> a;
	int n;

	ArrayStack() : a(n = 0) {}

	// get(i)
	T get(int i) {
		return a[i];
	}

	// set(i, x)
	T set(int i, T x) {
		T y = a[i];
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

	// add(i, x)
	// The cost of this operation is proportional to the number elements that
	// need to be shifted to insert x
	// Therefore, this operation is O(n - i) (ignoring cost to resize a)
	void add(int i, T x) {
		// Check if a is already full
		// If so, resize so that a.length > n
		if (n + 1 > a.length) resize();

		// Shift elements a[i:n-1] right by one position
		for (int j = n; j > i; j--) {
			a[j] = a[j - 1];
		}

		// Set a[i] equal to x and increment n
		a[i] = x;
		n++;
	}

	// remove(i)
	// The cost of this operation is proportional to the number elements that
	// need to be shifted to insert x
	// Therefore, this operation is O(n - i) (ignoring cost to resize a)
	T remove(int i) {
		T x = a[i];

		// Shift elements a[i + 1:n -1] left one position (overwriting a[i])
		for (int j = i; j < n; j++) {
			a[j] = a[j + 1];
		}

		// Decrement n
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
		for (int i = 0; i < n; i++) {
			b[i] = a[i];
		}

		// Set backing array a to new backing array b
		a = b;
	}

	// ===
	// TESTING
	// ===

	// Print a description of the data structure
	std::string typeDesc() {
    	return "2.1 | ArrayStack: Fast Stack Operations Using an Array";
    }

	// Test the data structure
	void test() {
		std::cout << "===" << std::endl;
		std::cout << this->typeDesc() << std::endl;
		std::cout << "===" << std::endl;
		std::cout << std::endl;

		this->add(0, 1);
		std::cout << "ArrayStack.add(index: 0, value: 1)" << std::endl;
		std::cout << "ArrayStack.size() =  " << this->size() << std::endl;
		std::cout << std::endl;

		this->printAllElements();

		this->add(1, 2);
		std::cout << "ArrayStack.add(index: 1, value: 2)" << std::endl;
		std::cout << "ArrayStack.size() =  " << this->size() << std::endl;
		std::cout << std::endl;

		this->printAllElements();

		this->add(2, 3);
		std::cout << "ArrayStack.add(index: 2, value: 3)" << std::endl;
		std::cout << "ArrayStack.size() =  " << this->size() << std::endl;
		std::cout << std::endl;

		this->printAllElements();

		this->remove(0);
		std::cout << "ArrayStack.remove(index: 0)" << std::endl;
		std::cout << "ArrayStack.size() =  " << this->size() << std::endl;
		std::cout << std::endl;

		this->printAllElements();

		std::cout << "ArrayStack.get(index: 1) = " << this->get(1) << std::endl;

		this->set(1, 4);
		std::cout << "ArrayStack.set(index: 1, value: 4)" << std::endl;
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

#endif // ARRAYSTACK_H
