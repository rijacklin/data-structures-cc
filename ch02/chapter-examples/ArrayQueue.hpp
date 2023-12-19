#ifndef ARRAY_QUEUE_HPP
#define ARRAY_QUEUE_HPP

#include "Array.hpp"
#include <iostream>

// Implements FIFO Queue interface with a ciruclar array using modular arithmetic
template <typename T>
class ArrayQueue {
public:
	Array<T> a;
	int j;
	int n;

	ArrayQueue() : a(n = 0) {}

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

	bool add(T x) {
		// Check if a is already full. If so, resize so that a.length > n
		if (n+1 > a.length) resize();

		// Set a[(j+n)/%a.length] equal to x and increment n
		a[(j+n)%a.length] = x;
		n++;

		return true;
	}

	T remove() {
		// Store a[j] so it can be returned later
		T x = a[j];

		// Increment j (modulo a.length) and decrement n
		j = (j+1) % a.length;

		// Decrement n
		n--;

		// Check if n is getting too small
		if (a.length >= 3*n) resize();

		return x;
	}

	// === GROWING / SHRINKING ===

	void resize() {
		// Create a new array that is double the size of the backing array
		Array<T> b(std::max(2*n, 1));

		// Copy n elements from a to b
		for (int k = 0; k < n; k++) {
			b[k] = a[(j+k)%a.length];
		}

		// Set backing array a to new backing array b
		a = b;

		// Set the value of j back to 0
		j = 0;
	}

	// === TESTING ===

	void test() {
		std::cout << "===" << std::endl;
		std::cout << "2.3 | ArrayQueue: An Array-Based Queue" << std::endl;
		std::cout << "===" << std::endl;

		this->add(1);
		std::cout << "ArrayQueue.add(value: 1)" << std::endl;
		std::cout << "ArrayQueue.size() =  " << this->size() << std::endl;

		this->printAllElements();

		this->add(2);
		std::cout << "ArrayQueue.add(value: 2)" << std::endl;
		std::cout << "ArrayQueue.size() =  " << this->size() << std::endl;

		this->printAllElements();

		this->add(3);
		std::cout << "ArrayQueue.add(3)" << std::endl;
		std::cout << "ArrayQueue.size() =  " << this->size() << std::endl;

		this->printAllElements();

		this->remove();
		std::cout << "ArrayQueue.remove()" << std::endl;
		std::cout << "ArrayQueue.size() =  " << this->size() << std::endl;

		this->printAllElements();

		std::cout << "ArrayQueue.get(index: 1) = " << this->get(1) << std::endl;

		this->set(1, 4);
		std::cout << "ArrayQueue.set(index: 1, value: 4)" << std::endl;

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

#endif // ARRAY_QUEUE_HPP
