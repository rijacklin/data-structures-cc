#ifndef ROOTISHARRAYSTACK_H
#define ROOTISHARRAYSTACK_H

#include "./array.h"
#include "./ArrayStack.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

// ===
// RootishArrayStack
// ===

/**
 * Addresses the problem of wasted space by storing n elements in O(sqrt(n))
 * arrays where at most O(sqrt(n)) array locations are unused at any time.
 *
 * As all the remaining array locations are used to store data, these data
 * structures waste at most O(sqrt(n)) space when storing n elements.
 *
 * This data structure stores its elements in a list of r arrays called `blocks`
 * that are numbered [0, 1, ..., r - 1]. Block b contains b + 1 elements.
 *
 * Therefore, all r blocks contain a total of:
 *
 * 		1 + 2 + 3 + ... + r = r(r + 1) / 2
 *
 * elements.
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
class RootishArrayStack {
public:
	ArrayStack<T*> blocks;
	int n;

	RootishArrayStack() : n(0) {}

	int i2b(int i) {
		double db = (-3.0 + sqrt(9 + 8*i)) / 2.0;
		int b = (int)ceil(db);
		return b;
	}

	// get(i)
	T get(int i) {
		int b = i2b(i);
		int j = i - b*(b+1)/2;
		return blocks.get(b)[j];
	}

	// set(x, i)
	T set(int i, T x) {
		int b = i2b(i);
		int j = i - b*(b+1)/2;
		T &y = blocks.get(b)[j];
		blocks.get(b)[j] = x;
		return y;
	}

	// ===
	// BASICS
	// ===

	// size()
	int size() {
		return n;
	}

	// add(x)
	void add(int i, T x) {
		int r = blocks.size();

		if (r*(r + 1)/2 < n + 1) grow();

		n++;
		
		for (int j = n - 1; j > i; j--) {
			set(j, get(j - 1));
		}

		set(i, x);
	}

	// remove()
	T remove(int i) {
		T x  = get(i);

		for (int j = i; j < n - 1; j++) {
			set(j, get(j+1));
		}

		n--;

		int r = blocks.size();

		if ((r - 2) * (r - 1)/2 >= n) shrink();

		return x;
	}

	// ===
	// GROWING / SHRINKING
	// ===

	// grow()
	void grow() {
		blocks.add(blocks.size(), new T[blocks.size() + 1]);
	}

	// shrink()
	void shrink() {
		int r = blocks.size();

		while (r > 0 && (r - 2) * (r - 1)/2 >= n) {
			delete [] blocks.remove(blocks.size() - 1);
			r--;
		}
	}

	// ===
	// TESTING
	// ===

	// Print a description of the data structure
	std::string typeDesc() {
        return "2.6 | RootishArrayStack: A Space-Efficient Array Stack";
    }

	// Test the data structure
	void test() {
		std::cout << "===" << std::endl;
		std::cout << this->typeDesc() << std::endl;
		std::cout << "===" << std::endl;
		std::cout << std::endl;

		this->add(0, 1);
		std::cout << "RootishArrayStack.add(index: 0, value: 1)" << std::endl;
		std::cout << "RootishArrayStack.size() =  " << this->size() << std::endl;
		std::cout << std::endl;

		this->printAllElements();

		this->add(1, 2);
		std::cout << "RootishArrayStack.add(index: 1, value: 2)" << std::endl;
		std::cout << "RootishArrayStack.size() =  " << this->size() << std::endl;
		std::cout << std::endl;

		this->printAllElements();

		this->add(2, 3);
		std::cout << "RootishArrayStack.add(index: 2, value: 3)" << std::endl;
		std::cout << "RootishArrayStack.size() =  " << this->size() << std::endl;
		std::cout << std::endl;

		this->printAllElements();

		this->remove(0);
		std::cout << "RootishArrayStack.remove(0)" << std::endl;
		std::cout << "RootishArrayStack.size() =  " << this->size() << std::endl;
		std::cout << std::endl;

		this->printAllElements();

		std::cout << "RootishArrayStack.get(index: 1) = " << this->get(1) << std::endl;
		std::cout << "RootishArrayStack.set(index: 1, value: 4) = " << this->set(1, 4) << std::endl;
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

#endif // ROOTISHARRAYSTACK_H
