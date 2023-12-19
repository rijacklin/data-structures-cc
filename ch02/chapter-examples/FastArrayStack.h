#ifndef FAST_ARRAY_STACK_H
#define FAST_ARRAY_STACK_H

#include "./array.h"
#include <iostream>

// Forward declaration of PrintableDataStructure
template <typename T>
class PrintableDataStructure;

// Implements the List interface using a backing array
template <typename T>
class FastArrayStack : PrintableDataStructure<T> {
public:
	array<T> a;
	int n;

	FastArrayStack() : a(n = 0) {}

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

		// Shift elements a[i:n-1] right by one position efficiently
		std::copy_backward(a.a + i, a.a + n, a.a + n + 1);

		// Set a[i] equal to x and increment n
		a[i] = x;
		n++;
	}

	T remove(int i) {
		// Store the value of index i
		T x = a[i];

		// Shift elements a[i+1:n-1] left by one position efficiently
		std::copy_backward(a.a + i, a.a + n, a.a + n - 1);

		// Decrement n
		n--;

		// Check if n is getting too small (less than 1/3 full)
		if (a.length >= 3 * n) resize();

		return x;
	}

	// === GROWING / SHRINKING ===
	
	void resize() {
		// Create a new array of size 2n
		array<T> b(std::max(1, 2 * n));

		// Copy n elements from a to b using efficient std::copy algorithm
		std::copy(a.a + 0, a.a +n, b.a + 0);

		// Set backing array a to new backing array b
		a = b;
	}

	// === TESTING ===

	void test() {
		std::cout << "===" << std::endl;
		std::cout << "2.2 | FastArrayStack: An Optimized ArrayStack" << std::endl;
		std::cout << "===" << std::endl;

		this->add(0, 1);
		std::cout << "FastArrayStack.add(index: 0, value: 1)" << std::endl;
		std::cout << "FastArrayStack.size() =  " << this->size() << std::endl;

		this->printAllElements();

		this->add(1, 2);
		std::cout << "FastArrayStack.add(index: 1, value: 2)" << std::endl;
		std::cout << "FastArrayStack.size() =  " << this->size() << std::endl;

		this->printAllElements();

		this->add(2, 3);
		std::cout << "FastArrayStack.add(index: 2, value: 3)" << std::endl;
		std::cout << "FastArrayStack.size() =  " << this->size() << std::endl;

		this->printAllElements();

		this->remove(0);
		std::cout << "FastArrayStack.remove(index: 0)" << std::endl;
		std::cout << "FastArrayStack.size() =  " << this->size() << std::endl;

		this->printAllElements();

		std::cout << "FastArrayStack.get(index: 1) = " << this->get(1) << std::endl;

		this->set(1, 4);
		std::cout << "FastArrayStack.set(index: 1, value: 4)" << std::endl;

		this->printAllElements();
	}

	void printAllElements() override;
};

#endif // FAST_ARRAY_STACK_H
