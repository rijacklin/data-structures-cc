#ifndef FASTARRAYSTACK_H
#define FASTARRAYSTACK_H

#include "./array.h"
#include <algorithm>

// ===
// FastArrayStack
// ===

/**
 * Implements the List interface using a backing array.
 * Ignoring the cost of calls to resize, an ArrayStack supports:
 * 
 * 	- get(i) and set(i, x) in O(1) time per operation; and
 * 	- add(i, x) and remove(i) in O(1 + n - i) time per operation
 *
 * Further, beginning with an empty ArrayStack, performing any sequence
 * of m add(i, x) and remove(i) operations results in a total of O(m) time
 * cost per resize operation (amortized analysis).
 *
 * Stack operations push(x) and pop() can be implemented as add(n, x) and
 * remove(n -1), respectively, in O(1) amortized time.
 */
template <typename T>
class FastArrayStack {
private:
	array<T> a;
	int n;

public:
	FastArrayStack() : a(n = 0) {}

	// get(i)
	T get(int i) {
		return a[i];
	}

	// set(x, i)
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

		// Shift elements a[i:n-1] right by one position efficiently
		std::copy_backward(a.a + i, a.a + n, a.a + n + 1);

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

		// Shift elements a[i:n-1] left by one position efficiently
		std::copy_backward(a.a + i, a.a + n, a.a + n - 1);

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
		array<T> b(std::max(1, 2 * n));

		// Copy n elements from a to b using efficient std::copy algorithm
		std::copy(a.a + 0, a.a +n, b.a + 0);

		// Set backing array a to new backing array b
		a = b;
	}
};

#endif // FASTARRAYSTACK_H
