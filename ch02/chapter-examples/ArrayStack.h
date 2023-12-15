#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include "./array.h"
#include <iostream>

// Forward declaration of TestableDataStructure.
template <typename T>
class TestableDataStructure;

// Implements the List interface using a backing array.
template <typename T>
class ArrayStack : public TestableDataStructure<T> {
public:
	array<T> a;
	int n;

	ArrayStack() : a(n = 0) {}

	int size() {
		return n;
	}

	// === BASICS ===

	T get(int i) {
		// Return the value at index i.
		return a[i];
	}

	T set(int i, T x) {
		// Store the value of index i.
		T y = a[i];

		// Set a[i] equal to x and return the old value.
		a[i] = x;
		return y;
	}

	void add(int i, T x) {
		// Check if a is already full. If so, resize so that a.length > n.
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
		// Store the value of index i.
		T x = a[i];

		// Shift elements a[i+1:n-1] left one position (overwriting a[i]).
		for (int j = i; j < n-1; j++) {
			a[j] = a[j+1];
		}

		// Decrement n.
		n--;

		// Check if n is getting too small (less than 1/3 full).
		if (a.length >= 3*n) resize();

		return x;
	}

	// === GROWING / SHRINKING ===
	
	void resize() {
		// Create a new array of size 2n.
		array<T> b(std::max(2*n, 1));

		// Copy n elements from a to new array b.
		for (int i = 0; i < n; i++) {
			b[i] = a[i];
		}

		// Set backing array a to new backing array b.
		a = b;
	}

	// === TESTING ===

	std::string typeDesc() override;
	void test() override;
	void printAllElements() override ;
};

#endif // ARRAY_STACK_H
