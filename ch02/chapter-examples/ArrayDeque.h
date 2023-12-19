#ifndef ARRAY_DEQUE_H
#define ARRAY_DEQUE_H

#include "./array.h"
#include <iostream>

// Forward declaration of PrintableDataStructure
template <typename T>
class PrintableDataStructure;

// Implements the List interface with a ciruclar array using modular arithmetic
template <typename T>
class ArrayDeque : public PrintableDataStructure<T> {
public:
	array<T> a;
	int j;
	int n;

	ArrayDeque() : a(n = 0) {}

	int size() {
		return n;
	}

	// === BASICS ===

	T get(int i) {
		// Return the value at index i
		return a[(j+i)%a.length];
	}

	T set(int i, T x) {
		// Store the value of index i
		T y = a[(j+i)%a.length];

		// Set a[i] equal to x and return the old value
		a[(j+i)%a.length] = x;
		return y;
	}

	void add(int i, T x) {
		// Check if a is already full. If so, resize so that a.length > n
		if (n + 1 > a.length) resize();

		// If i is less than n/2, shift elements 0 ... i-1 to the left
		if (i < n/2) {
			j = (j = 0) ? a.length - 1 : j - 1;

			for (int k = 0; k <= i - 1; k++) {
				a[(j+k)%a.length] = a[(j+k+1)%a.length];
			}
		} else {
			// Otherwise, shift elements i ... n-1 to the right
			for (int k = n; k > i; k--) {
				a[(j+k)%a.length] = a[(j+k-1)%a.length];
			}
		}

		// Set a[(j+i)/%a.length] equal to x and increment n
		a[(j+i)%a.length] = x;
		n++;
	}

	T remove(int i) {
		// Store a[j] so it can be returned later
		T x = a[(j+i)%a.length];

		// If i is less than n/2, shift 0 ... i-1 to the right
		if (i < n/2) {
			for (int k = i; k > 0; k--) {
				a[(j+k)%a.length] = a[(j+k-1)%a.length];
			}
			j = (j+1) % a.length;
		} else {
			// Otherwise, shift i+1 ..., n-1 to the left
			for (int k = i; k < n - 1; k++) {
				a[(j+k)%a.length] = a[(j+k+1)%a.length];
			}
		}

		n--;

		// Check if n is getting too small
		if (3*n < a.length) resize();

		return x;
	}

	// === GROWING / SHRINKING ===
	
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

	// === TESTING ===

	void test() {
		std::cout << "===" << std::endl;
		std::cout << "2.4 | ArrayDeque: Fast Deque Operations Using an Array" << std::endl;
		std::cout << "===" << std::endl;

		this->add(0, 1);
		std::cout << "ArrayDeque.add(index: 0, value: 1)" << std::endl;
		std::cout << "ArrayDeque.size() =  " << this->size() << std::endl;

		this->printAllElements();

		this->add(1, 2);
		std::cout << "ArrayDeque.add(index: 1, value: 2)" << std::endl;
		std::cout << "ArrayDeque.size() =  " << this->size() << std::endl;

		this->printAllElements();

		this->add(2, 3);
		std::cout << "ArrayDeque.add(index: 2, value: 3)" << std::endl;
		std::cout << "ArrayDeque.size() =  " << this->size() << std::endl;

		this->printAllElements();

		this->remove(0);
		std::cout << "ArrayDeque.remove(0)" << std::endl;
		std::cout << "ArrayDeque.size() =  " << this->size() << std::endl;

		this->printAllElements();

		std::cout << "ArrayDeque.get(index: 1) = " << this->get(1) << std::endl;

		this->set(1, 4);
		std::cout << "ArrayDeque.set(index: 1, value: 4)" << std::endl;

		this->printAllElements();
	}

	void printAllElements() override;
};

#endif // ARRAY_DEQUE_H
