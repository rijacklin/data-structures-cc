#ifndef RANDOM_QUEUE_HPP
#define RANDOM_QUEUE_HPP

#include "../chapter-examples/Array.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

// Implements FIFO Queue interface with a ciruclar array using modular arithmetic
// https://en.cppreference.com/w/cpp/numeric/random/srand
// https://en.cppreference.com/w/cpp/numeric/random/rand
template <typename T>
class RandomQueue {
public:
	Array<T> a;
	int j;
	int n;

	RandomQueue() : a(n = 0) {}

	int size() {
		return n;
	}

	T get(int i) {
		return a[i];
	}

	T set(int i, T x) {
		T y = a[i];
		a[i] = x;
		return y;
	}

	bool add(T x) {
		if (n+1 > a.length) resize();

		a[(j+n)%a.length] = x;
		n++;

		return true;
	}

	T remove() {
		// Seed the RNG with the current time
		std::srand(std::time(0));

		// Generate random number
		int randomIdx = std::rand() % this->size();

		std::cout << "Removing at index " << randomIdx << ": " << std::endl;

		// Store current value at random index
		T x = a[randomIdx];

		// Shift elements a[i+1:n-1] left one position (overwriting a[i])
		for (int j = randomIdx; j < n-1; j++) {
			a[j] = a[j+1];
		}

		// j = randomIdx % a.length;
		n--;

		if (a.length >= 3*n) resize();

		return x;
	}

	void resize() {
		Array<T> b(std::max(2*n, 1));

		for (int k = 0; k < n; k++) {
			b[k] = a[(j+k)%a.length];
		}

		a = b;
		j = 0;
	}

	// === TESTING ===

	void test() {
		std::cout << "===" << std::endl;
		std::cout << "RandomQueue: An Array-Based Queue" << std::endl;
		std::cout << "===" << std::endl;

		std::cout << "Adding 6 Elements" << std::endl;

		this->add(9);
		this->add(1);
		this->add(2);
		this->add(7);
		this->add(3);
		this->add(5);
		this->printAllElements();

		this->remove();
		this->printAllElements();
		this->remove();
		this->printAllElements();
		this->remove();
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

#endif // RANDOM_QUEUE_HPP
