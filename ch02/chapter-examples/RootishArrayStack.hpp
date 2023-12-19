#ifndef ROOTISH_ARRAY_STACK_HPP
#define ROOTISH_ARRAY_STACK_HPP

#include <iostream>
#include <cmath>

// Forward declaration of ArrayStack
template <typename T>
class ArrayStack;

// Addresses the problem of wasted space by storing n elements in O(sqrt(n))
// arrays where at most O(sqrt(n)) array locations are unused at any time
template <typename T>
class RootishArrayStack {
public:
	ArrayStack<T*> blocks;
	int n;

	RootishArrayStack() : n(0) {}

	int size() {
		return n;
	}

	// Determine which block b contains i using a quadratic equation
	int i2b(int i) {
		double db = (-3.0 + sqrt(9 + 8*i)) / 2.0;
		int b = (int)ceil(db);
		return b;
	}

	// === BASICS ===

	T get(int i) {
		// Calculate which block contains the indexed value
		int b = i2b(i);

		// Calculate j (j = i - the index of the first element in the block)
		int j = i - b*(b + 1)/2;

		return blocks.get(b)[j];
	}

	T set(int i, T x) {
		// Calculate which block contains the indexed value
		int b = i2b(i);

		// Calculate j (j = i - the index of the first element in the block)
		int j = i - b*(b + 1)/2;

		// Store the current indexed value
		T y = blocks.get(b)[j];

		// Update the indexed element to the new value x and return the old value
		blocks.get(b)[j] = x;
		return y;
	}

	void add(int i, T x) {
		// Check size of blocks to determine if the data structure is full
		int r = blocks.size();

		// If full, the grow() operation adds an additional block
		if (r*(r + 1)/2 < n + 1) grow();

		n++;

		// Shift elements [i:n-1] one position to the right
		for (int j = n - 1; j > i; j--) {
			set(j, get(j - 1));
		}

		// Set the new value at the given index i
		set(i, x);
	}

	T remove(int i) {
		T x  = get(i);

		// Shift the elements [i+1:n-1] one position to the left
		for (int j = i; j < n - 1; j++) {
			set(j, get(j+1));
		}

		n--;

		// Check size of blocks to determine if empty blocks is greater than 1
		int r = blocks.size();

		// If so, remove all but one of the unused blocks
		if ((r - 2) * (r - 1)/2 >= n) shrink();

		return x;
	}

	// === GROWING / SHRINKING ===

	void grow() {
		// Add a new block to the data structure
		blocks.add(blocks.size(), new T[blocks.size() + 1]);
	}

	void shrink() {
		int r = blocks.size();

		// Remove all but one of the unused blocks
		while (r > 0 && (r - 2) * (r - 1)/2 >= n) {
			delete [] blocks.remove(blocks.size() - 1);
			r--;
		}
	}

	// === TESTING ===

	void test() {
		std::cout << "===" << std::endl;
		std::cout << "2.6 | RootishArrayStack: A Space-Efficient Array Stack" << std::endl;
		std::cout << "===" << std::endl;

		this->add(0, 1);
		std::cout << "RootishArrayStack.add(index: 0, value: 1)" << std::endl;
		std::cout << "RootishArrayStack.size() =  " << this->size() << std::endl;

		this->printAllElements();

		this->add(1, 2);
		std::cout << "RootishArrayStack.add(index: 1, value: 2)" << std::endl;
		std::cout << "RootishArrayStack.size() =  " << this->size() << std::endl;

		this->printAllElements();

		this->add(2, 3);
		std::cout << "RootishArrayStack.add(index: 2, value: 3)" << std::endl;
		std::cout << "RootishArrayStack.size() =  " << this->size() << std::endl;

		this->printAllElements();

		this->remove(0);
		std::cout << "RootishArrayStack.remove(0)" << std::endl;
		std::cout << "RootishArrayStack.size() =  " << this->size() << std::endl;

		this->printAllElements();

		std::cout << "RootishArrayStack.get(index: 1) = " << this->get(1) << std::endl;

		this->set(1, 4);
		std::cout << "RootishArrayStack.set(index: 1, value: 4)" << std::endl;

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

#endif // ROOTISH_ARRAY_STACK_HPP
