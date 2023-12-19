#ifndef ARRAY_STACK_HPP
#define ARRAY_STACK_HPP

#include "Array.hpp"
#include <iostream>

// Implements the List interface using a backing array
template <typename T>
class ArrayStack {
public:
	Array<T> a;
	int n;

	ArrayStack() : a(n = 0) {}

	int size() {
		return n;
	}

	// === BASICS ===

	T get(int i) {
		// Return the value at index i
		return a[i];
	}

	T set(int i, T x) {
		// Store the value of index i
		T y = a[i];

		// Set a[i] equal to x and return the old value
		a[i] = x;
		return y;
	}

	void add(int i, T x) {
		// Check if a is already full. If so, resize so that a.length > n
		if (n + 1 > a.length) resize();

		// Shift elements a[i:n-1] right by one position.
		for (int j = n; j > i; j--) {
			a[j] = a[j-1];
		}

		// Set a[i] equal to x and increment n.
		a[i] = x;
		n++;
	}

	T remove(int i) {
		// Store the value of index i
		T x = a[i];

		// Shift elements a[i+1:n-1] left one position (overwriting a[i])
		for (int j = i; j < n-1; j++) {
			a[j] = a[j+1];
		}

		// Decrement n
		n--;

		// Check if n is getting too small (less than 1/3 full)
		if (a.length >= 3*n) resize();

		return x;
	}

	// === GROWING / SHRINKING ===
	
	void resize() {
		// Create a new array of size 2n
		Array<T> b(std::max(2*n, 1));

		// Copy n elements from a to new array b
		for (int i = 0; i < n; i++) {
			b[i] = a[i];
		}

		// Set backing array a to new backing array b
		a = b;
	}

	// === TESTING ===

	void test() {
		std::cout << "===" << std::endl;
		std::cout << "2.1 | ArrayStack: Fast Stack Operations Using an Array" << std::endl;
		std::cout << "===" << std::endl;

		this->add(0, 1);
		std::cout << "ArrayStack.add(index: 0, value: 1)" << std::endl;
		std::cout << "ArrayStack.size() =  " << this->size() << std::endl;

		this->printAllElements();

		this->add(1, 2);
		std::cout << "ArrayStack.add(index: 1, value: 2)" << std::endl;
		std::cout << "ArrayStack.size() =  " << this->size() << std::endl;

		this->printAllElements();

		this->add(2, 3);
		std::cout << "ArrayStack.add(index: 2, value: 3)" << std::endl;
		std::cout << "ArrayStack.size() =  " << this->size() << std::endl;

		this->printAllElements();

		this->remove(0);
		std::cout << "ArrayStack.remove(index: 0)" << std::endl;
		std::cout << "ArrayStack.size() =  " << this->size() << std::endl;

		this->printAllElements();

		std::cout << "ArrayStack.get(index: 1) = " << this->get(1) << std::endl;

		this->set(1, 4);
		std::cout << "ArrayStack.set(index: 1, value: 4)" << std::endl;

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

#endif // ARRAY_STACK_HPP
