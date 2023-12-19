#ifndef DUAL_ARRAY_DEQUE_H
#define DUAL_ARRAY_DEQUE_H

#include "array.h"
#include <iostream>

// Forward declaration of ArrayStack
template <typename T>
class ArrayStack;

// Forward declaration of PrintableDataStructure
template <typename T>
class PrintableDataStructure;

// Achieves the same performance bounds as an ArrayDequeue with two ArrayStacks
template <typename T>
class DualArrayDeque : public PrintableDataStructure<T> {
public:
	ArrayStack<T> front;
	ArrayStack<T> back;

	DualArrayDeque() {
		front.n = 0;
		back.n = 0;
	}

	int size() {
		// Calculates the number of elements containse in the two ArrayStacks
		return front.size() + back.size();
	}

	// === BASICS ===

	T get(int i) {
		// If i is less than front.size(), value is contained in the front array
		if (i < front.size()) {
			// Return the value at front.size() - i - 1
			return front.get(front.size() - i - 1);
		} else {
			// Otehrwise, return the value in the back array, i - front.size()
			return back.get(i - front.size());
		}
	}

	T set(int i, T x) {
		// If i is less than front.size(), set the value in the front array
		if (i < front.size()) {
			return front.set(front.size() - i - 1, x);
		} else {
			// Otherwise, set the value in the back array, i - front.size()
			return back.set(i - front.size(), x);
		}
	}

	void add(int i, T x) {
		// If i is less than the size of front, add to front in reverse order
		if (i < front.size()) {
			front.add(front.size() - i, x);
		} else {
			// Otherwise, add to the back array
			back.add(i - front.size(), x);
		}

		// Balance the two arrays
		balance();
	}

	T remove(int i) {
		T x;

		// If i is less than the size of front, remove from the front array
		if (i < front.size()) {
			x = front.remove(front.size() - i - 1);
		} else {
			// Otherwise, remove from the back array
			x = back.remove(i - front.size());
		}

		// Balance the two arrays
		balance();

		// Return the removed value
		return x;
	}

	// === GROWING / SHRINKING ===

	void balance() {
		// Check if either array is 3 times smaller than the other
		if (3*front.size() < back.size() || 3*back.size() < front.size()) {
			// Calculate the total number of elements in the two arrays
			int n = front.size() + back.size();

			// Create the front array with a size of 2n
			int nf = n/2;
			array<T> af(std::max(2 * nf, 1));
			
			// Copy the elements from the front array in reverse order
			for (int i = 0; i < nf; i++) {
				af[nf-i-1] = get(i);
			}

			// Create the back array with the remaining 2n elements
			int nb = n - nf;
			array<T> ab(std::max(2 * nb, 1));

			// Copy the elements from the back array
			for (int i = 0; i < nb; i++) {
				ab[i] = get(nf+i);
			}

			// Set the front and back arrays to the new arrays
			front.a = af;
			front.n = nf;
			back.a = ab;
			back.n = nb;
		}
	}

	// === TESTING ===

	void test() {
		std::cout << "===" << std::endl;
		std::cout << "2.5 | DualArrayDeque: Building a Deque from Two Stacks" << std::endl;
		std::cout << "===" << std::endl;

		this->add(0, 1);
		std::cout << "DualArrayDeque.add(index: 0, value: 1)" << std::endl;
		std::cout << "DualArrayDeque.size() =  " << this->size() << std::endl;

		this->printAllElements();

		this->add(1, 2);
		std::cout << "DualArrayDeque.add(index: 1, value: 2)" << std::endl;
		std::cout << "DualArrayDeque.size() =  " << this->size() << std::endl;

		this->printAllElements();

		this->add(2, 3);
		std::cout << "DualArrayDeque.add(index: 2, value: 3)" << std::endl;
		std::cout << "DualArrayDeque.size() =  " << this->size() << std::endl;

		this->printAllElements();

		this->remove(0);
		std::cout << "DualArrayDeque.remove(0)" << std::endl;
		std::cout << "DualArrayDeque.size() =  " << this->size() << std::endl;

		this->printAllElements();

		std::cout << "DualArrayDeque.get(index: 1) = " << this->get(1) << std::endl;

		this->set(1, 4);
		std::cout << "DualArrayDeque.set(index: 1, value: 4)" << std::endl;

		this->printAllElements();
	}

	void printAllElements() override;
};

#endif // DUAL_ARRAY_DEQUE_H
