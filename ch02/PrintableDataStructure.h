#ifndef PRINTABLE_DATA_STRUCTURE_H
#define PRINTABLE_DATA_STRUCTURE_H

#include <iostream>

template <typename T>
class PrintableDataStructure {
public:
	virtual void printAllElements() = 0;

	virtual ~PrintableDataStructure() {}
};

#include "./chapter-examples/ArrayStack.h"
#include "./chapter-examples/FastArrayStack.h"
#include "./chapter-examples/ArrayQueue.h"
#include "./chapter-examples/ArrayDeque.h"
#include "./chapter-examples/DualArrayDeque.h"
#include "./chapter-examples/RootishArrayStack.h"

template <typename T>
class ArrayStack;

template <typename T>
inline void ArrayStack<T>::printAllElements() {
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

template <typename T>
class FastArrayStack;

// Print all elements in the data structure.
template <typename T>
inline void FastArrayStack<T>::printAllElements() {
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

template <typename T>
class ArrayQueue;

template <typename T>
inline void ArrayQueue<T>::printAllElements() {
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

template <typename T>
class ArrayDeque;

template <typename T>
inline void ArrayDeque<T>::printAllElements() {
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

template <typename T>
class DualArrayDeque;

template <typename T>
inline void DualArrayDeque<T>::printAllElements() {
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

template <typename T>
class RootishArrayStack;

template <typename T>
inline void RootishArrayStack<T>::printAllElements() {
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

#endif // PRINTABLE_DATA_STRUCTURE_H
