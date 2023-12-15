#ifndef FAST_ARRAY_STACK_H
#define FAST_ARRAY_STACK_H

#include "./array.h"
#include <iostream>

// Forward declaration of TestableDataStructure.
template <typename T>
class TestableDataStructure;

// Implements the List interface using a backing array.
template <typename T>
class FastArrayStack : TestableDataStructure<T> {
public:
	array<T> a;
	int n;

	FastArrayStack() : a(n = 0) {}

	int size() {
		return n;
	}

	// ===
	// BASICS
	// ===

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

	// The cost of this operation is proportional to the number elements that
	// need to be shifted to insert x.
	// Therefore, this operation is O(n - i) (ignoring cost to resize a).
	void add(int i, T x) {
		// Check if a is already full. If so, resize so that a.length > n.
		if (n + 1 > a.length) resize();

		// Shift elements a[i:n-1] right by one position efficiently.
		std::copy_backward(a.a + i, a.a + n, a.a + n + 1);

		// Set a[i] equal to x and increment n
		a[i] = x;
		n++;
	}

	// The cost of this operation is proportional to the number elements that
	// need to be shifted to insert x.
	// Therefore, this operation is O(n - i) (ignoring cost to resize a).
	T remove(int i) {
		// Store the value of index i.
		T x = a[i];

		// Shift elements a[i+1:n-1] left by one position efficiently.
		std::copy_backward(a.a + i, a.a + n, a.a + n - 1);

		// Decrement n.
		n--;

		// Check if n is getting too small (less than 1/3 full).
		if (a.length >= 3 * n) resize();

		return x;
	}

	// ===
	// GROWING / SHRINKING
	// ===
	
	// If the array is full before an add(i, x) operation, or more than 2/3
	// empty after a remove(i) operation, then resize the array to be half.
	void resize() {
		// Create a new array of size 2n.
		array<T> b(std::max(1, 2 * n));

		// Copy n elements from a to b using efficient std::copy algorithm.
		std::copy(a.a + 0, a.a +n, b.a + 0);

		// Set backing array a to new backing array b.
		a = b;
	}

	// ===
	// TESTING
	// ===

	std::string typeDesc() override;
	void test() override;
	void printAllElements() override;
};

#endif // FAST_ARRAY_STACK_H
