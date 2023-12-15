#ifndef DUAL_ARRAY_DEQUE_H
#define DUAL_ARRAY_DEQUE_H

#include "array.h"
#include <iostream>

// Forward declaration of ArrayStack.
template <typename T>
class ArrayStack;

// Forward declaration of TestableDataStructure.
template <typename T>
class TestableDataStructure;

// Achieves the same performance bounds as an ArrayDequeue with two ArrayStacks.
template <typename T>
class DualArrayDeque : public TestableDataStructure<T> {
public:
	ArrayStack<T> front;
	ArrayStack<T> back;

	DualArrayDeque() {
		front.n = 0;
		back.n = 0;
	}

	// Calculates the number of elements conatined using the size() function of
	// the two ArrayStacks rather than storing a variable n.
	// Calls to get(i) and set(i, x), regardless of front or back, takes O(1)
	// time per operation.
	int size() {
		return front.size() + back.size();
	}

	// ===
	// BASICS
	// ===

	// The front ArrayStack stores the list of elements whose indices are
	// [0, ..., front.size() - 1], but stores them in reverse order.
	// The back ArrayStack stores the list of elements whose indices are
	// [front.size(), ..., size() - 1] in normal order.
	T get(int i) {
		// If i is contained in the front array, return the value from the
		// front array at front.size() - i - 1 as the values are stored in
		// reverse order.
		// Otherwise, return the value from the back array.
		if (i < front.size()) {
			return front.get(front.size() - i - 1);
		} else {
			return back.get(i - front.size());
		}
	}

	T set(int i, T x) {
		// If i is contained in the front array, set the value in the front
		// array.
		// Otherwise, set the value from the back array.
		if (i < front.size()) {
			return front.set(front.size() - i - 1, x);
		} else {
			return back.set(i - front.size(), x);
		}
	}

	// add(x)
	// Elements are added to either the front or back, as appropriate.
	//
	// Adding to the front occurs when i < n/4. Adding to the back occurs when
	// i >= 3n/4.
	//
	// When n/4 <= i <= 3n/4, we cannot be sure whether the operation affects
	// the front or back. Regardless, in either case, operation takes:
	// - O(n) = O(i) = O(n - i) time, since i >= n/4 and n - i > n/4.
	//
	// Therefore, the running time of add(i, x), ignoring the cost of calls to
	// balance(), is O(1 + min(i, n - i)).
	void add(int i, T x) {
		// If i is less than the size of front, add to front in reverse order.
		// Otherwise, add to the back.
		if (i < front.size()) {
			// The cost of this operation is:
			// - O(front.size() - (front.size() - i - 1) + 1) = O(i + 1)
			front.add(front.size() - i, x);
		} else {
			// The cost of this operation is:
			// - O(back.size() - (i  - front.size()) + 1) = O(n - i + 1)
			back.add(i - front.size(), x);
		}
		balance();
	}

	// Elements are removed from either the front or back, as appropriate.
	//
	// Removing from the front occurs when i < n/4. Removing from the back
	// occurs when i >= 3n/4.
	//
	// When n/4 <= i <= 3n/4, we cannot be sure whether the operation affects
	// the front or back. Regardless, in either case, operation takes:
	// - O(n) = O(i) = O(n - i) time, since i >= n/4 and n - i > n/4.
	//
	// Therefore, the running time of remove(), ignoring the cost of calls to
	// balance(), is O(1 + min(i, n - i)).
	T remove(int i) {
		T x;

		if (i < front.size()) {
			x = front.remove(front.size() - i - 1);
		} else {
			x = back.remove(i - front.size());
		}

		balance();

		return x;
	}

	// ===
	// GROWING / SHRINKING
	// ===

	// balance()
	// Ensures that	neither the front nor back becomes too big (or too small).
	// Unless there are fewer than two elements, each of front and back contain
	// at least n/4 elements.
	// If this is not the case, balance() moves elements between them so that
	// front and back both contain exactly [n/2] elements.
	//
	// If the balance() operation does rebalancing, then it moves O(n) elements
	// in O(n) time.
	// However, on average, balance() only spends a constant amount of time per
	// operation.
	void balance() {
		if (3 * front.size() < back.size() || 3 * back.size() < front.size()) {
			int n = front.size() + back.size();
			int nf = n/2;
			array<T> af(std::max(2 * nf, 1));
			
			for (int i = 0; i < nf; i++) {
				af[nf-i-1] = get(i);
			}

			int nb = n - nf;
			array<T> ab(std::max(2 * nb, 1));

			for (int i = 0; i < nb; i++) {
				ab[i] = get(nf+i);
			}

			front.a = af;
			front.n = nf;
			back.a = ab;
			back.n = nb;
		}
	}


	// ===
	// TESTING
	// ===

	std::string typeDesc() override;
	void test() override;
	void printAllElements() override;
};

#endif // DUAL_ARRAY_DEQUE_H
