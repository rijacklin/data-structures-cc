#ifndef ROOTISHARRAYSTACK_H
#define ROOTISHARRAYSTACK_H

#include "./ArrayStack.h"
#include <cmath>

// ===
// RootishArrayStack
// ===
// Addresses the problem of wasted space by storing n elements in O(sqrt(n))
// arrays where at most O(sqrt(n)) array locations are unused at any time.
template <typename T>
class RootishArrayStack {
public:
	ArrayStack<T*> blocks;
	int n;

	RootishArrayStack() : n(0) {}

	// i2b(i)
	// Determine which block b contains i using a quadratic equation.
	int i2b(int i) {
		double db = (-3.0 + sqrt(9 + 8*i)) / 2.0;
		int b = (int)ceil(db);
		return b;
	}

	// get(i)
	T get(int i) {
		// Calculate which block contains the indexed value.
		int b = i2b(i);

		// Get the index j of the value within the block and return the value.
		int j = i - b*(b + 1)/2;
		return blocks.get(b)[j];
	}

	// set(i, x)
	T set(int i, T x) {
		// Calculate which block contains the indexed value.
		int b = i2b(i);

		// Calculate the index within the block.
		int j = i - b*(b + 1)/2;

		// Store the current indexed value
		T y = blocks.get(b)[j];

		// Update the indexed element to the new value x and return the old value.
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

	// add(i, x)
	// Ignoring the cost of the grow() operation, the cost of add(i, x) is
	// dominated by shifting values and is therefore O(1 + n - i).
	void add(int i, T x) {
		// Check size of blocks to determine if the data structure is full.
		// If full, the grow() operation adds an additional block.
		int r = blocks.size();
		if (r*(r + 1)/2 < n + 1) grow();

		n++;

		// Shift elements [i:n-1] one position to the right.
		for (int j = n - 1; j > i; j--) {
			set(j, get(j - 1));
		}

		// Set the new value at the given index i.
		set(i, x);
	}

	// remove(i)
	// Ignoring the cost of the shrink() operation, the cost of remove(i) is
	// dominated by shifting values and is therefore O(n - i).
	T remove(int i) {
		T x  = get(i);

		// Shift the elements [i+1:n] one position to the left.
		for (int j = i; j < n - 1; j++) {
			set(j, get(j+1));
		}

		n--;

		// Check size of blocks to determine if the data structure contains more
		// than one empty block.
		// If so, the shrink() operation removes all but one of the unused
		// blocks.
		int r = blocks.size();
		if ((r - 2) * (r - 1)/2 >= n) shrink();

		return x;
	}

	// ===
	// GROWING / SHRINKING
	// ===

	// grow()
	// Adds a new block to the data structure.
	void grow() {
		blocks.add(blocks.size(), new T[blocks.size() + 1]);
	}

	// shrink()
	// Removes unused blocks from the data structure.
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

		this->set(1, 4);
		std::cout << "RootishArrayStack.set(index: 1, value: 4)" << std::endl;
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
