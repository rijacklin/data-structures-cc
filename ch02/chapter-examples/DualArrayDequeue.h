#ifndef DUALARRAYDEQUEUE_H
#define DUALARRAYDEQUEUE_H

#include "./array.h"
#include "./ArrayStack.h"
#include <algorithm>
#include <iostream>
#include <string>

// ===
// DualArrayDequeue
// ===

/**
 * Achieves the same performance bounds as an ArrayDequeue by using two
 * ArrayStacks.
 *
 * Represents a List using two ArrayStacks. As an ArrayStack is fast when its
 * operations modify elements near the end, a DualArrayDequeue places two
 * ArrayStacks back-to-back so that operations are fast on either end.
 *
 * Ignoring the cost of calls to resize() and balance(), an ArrayDequeue
 * supports:
 * 
 * 	- get(i) and set(i, x) in O(1) time per operation; and
 * 	- add(i, x) and remove(i) in O(1 + min{i, n - i}) time per operation
 *
 * Further, beginning with an empty DualArrayDequeue, performing any sequence
 * of m add(i, x) and remove(i) operations results in a total of O(m) time
 * spent during all calls to resize() and balance().
 */
template <typename T>
class DualArrayDequeue {
public:
	ArrayStack<T> front;
	ArrayStack<T> back;

	DualArrayDequeue() {
		front.n = 0;
		back.n = 0;
	}

	// get(i)
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

	// set(x, i)
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

	// ===
	// BASICS
	// ===

	// size()
	// Calculates the number of elements conatined using the size() function of
	// the two ArrayStacks rather than storing a variable n.
	// Calls to get(i) and set(i, x), regardless of front or back, takes O(1)
	// time per operation.
	int size() {
		return front.size() + back.size();
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

	// remove()
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

	// Print a description of the data structure
	std::string typeDesc() {
        return "2.5 | DualArrayDeque: Building a Deque from Two Stacks";
    }

	// Test the data structure
	void test() {
		std::cout << "===" << std::endl;
		std::cout << this->typeDesc() << std::endl;
		std::cout << "===" << std::endl;
		std::cout << std::endl;

		this->add(0, 1);
		std::cout << "DualArrayDeque.add(index: 0, value: 1)" << std::endl;
		std::cout << "DualArrayDeque.size() =  " << this->size() << std::endl;
		std::cout << std::endl;

		this->printAllElements();

		this->add(1, 2);
		std::cout << "DualArrayDeque.add(index: 1, value: 2)" << std::endl;
		std::cout << "DualArrayDeque.size() =  " << this->size() << std::endl;
		std::cout << std::endl;

		this->printAllElements();

		this->add(2, 3);
		std::cout << "DualArrayDeque.add(index: 2, value: 3)" << std::endl;
		std::cout << "DualArrayDeque.size() =  " << this->size() << std::endl;
		std::cout << std::endl;

		this->printAllElements();

		this->remove(0);
		std::cout << "DualArrayDeque.remove(0)" << std::endl;
		std::cout << "DualArrayDeque.size() =  " << this->size() << std::endl;
		std::cout << std::endl;

		this->printAllElements();

		std::cout << "DualArrayDeque.get(index: 1) = " << this->get(1) << std::endl;
		std::cout << "DualArrayDeque.set(index: 1, value: 4) = " << this->set(1, 4) << std::endl;
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

#endif // DUALARRAYDEQUEUE_H
