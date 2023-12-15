#ifndef TESTABLE_DATA_STRUCTURE_H
#define TESTABLE_DATA_STRUCTURE_H

#include <iostream>

template <typename T>
class TestableDataStructure {
public:
	virtual std::string typeDesc() = 0;
	virtual void test() = 0;
	virtual void printAllElements() = 0;

	virtual ~TestableDataStructure() {}
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
class FastArrayStack;

template <typename T>
class ArrayQueue;

template <typename T>
class ArrayDeque;

template <typename T>
class DualArrayDeque;

template <typename T>
class RootishArrayStack;

// ===
// ArrayStack Testing Implementation
// ===

// Print a description of the data structure.
template <typename T>
inline std::string ArrayStack<T>::typeDesc() {
	return "2.1 | ArrayStack: Fast Stack Operations Using an Array";
}

// Test the data structure.
template <typename T>
inline void ArrayStack<T>::test() {
	std::cout << "===" << std::endl;
	std::cout << this->typeDesc() << std::endl;
	std::cout << "===" << std::endl;

	this->add(0, 1);
	std::cout << "ArrayStack.add(index: 0, value: 1)" << std::endl;
	std::cout << "ArrayStack.size() =  " << this->size() << std::endl;

	this->printAllElements();

	this->add(1, 2);
	std::cout << "ArrayStack.add(index: 1, value: 2)" << std::endl;
	std::cout << "ArrayStack.size() =  " << this->size() << std::endl;

	this->printAllElements();

	this->add(2, 3);
	std::cout << "ArrayStack.add(index: 2, value: 3)" << std::endl;
	std::cout << "ArrayStack.size() =  " << this->size() << std::endl;

	this->printAllElements();

	this->remove(0);
	std::cout << "ArrayStack.remove(index: 0)" << std::endl;
	std::cout << "ArrayStack.size() =  " << this->size() << std::endl;

	this->printAllElements();

	std::cout << "ArrayStack.get(index: 1) = " << this->get(1) << std::endl;

	this->set(1, 4);
	std::cout << "ArrayStack.set(index: 1, value: 4)" << std::endl;

	this->printAllElements();
}

// Print all elements in the data structure.
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

// ===
// FastArrayStack Testing Implementation
// ===

// Print a description of the data structure.
template <typename T>
inline std::string FastArrayStack<T>::typeDesc() {
	return "2.2 | FastArrayStack: An Optimized ArrayStack";
}

// Test the data structure.
template <typename T>
inline void FastArrayStack<T>::test() {
	std::cout << "===" << std::endl;
	std::cout << this->typeDesc() << std::endl;
	std::cout << "===" << std::endl;

	this->add(0, 1);
	std::cout << "FastArrayStack.add(index: 0, value: 1)" << std::endl;
	std::cout << "FastArrayStack.size() =  " << this->size() << std::endl;

	this->printAllElements();

	this->add(1, 2);
	std::cout << "FastArrayStack.add(index: 1, value: 2)" << std::endl;
	std::cout << "FastArrayStack.size() =  " << this->size() << std::endl;

	this->printAllElements();

	this->add(2, 3);
	std::cout << "FastArrayStack.add(index: 2, value: 3)" << std::endl;
	std::cout << "FastArrayStack.size() =  " << this->size() << std::endl;

	this->printAllElements();

	this->remove(0);
	std::cout << "FastArrayStack.remove(index: 0)" << std::endl;
	std::cout << "FastArrayStack.size() =  " << this->size() << std::endl;

	this->printAllElements();

	std::cout << "FastArrayStack.get(index: 1) = " << this->get(1) << std::endl;

	this->set(1, 4);
	std::cout << "FastArrayStack.set(index: 1, value: 4)" << std::endl;

	this->printAllElements();
}

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

// ===
// ArrayQueue Testing Implementation
// ===

// Print a description of the data structure.
template <typename T>
inline std::string ArrayQueue<T>::typeDesc() {
	return "2.3 | ArrayQueue: An Array-Based Queue";
}

// Test the data structure.
template <typename T>
inline void ArrayQueue<T>::test() {
	std::cout << "===" << std::endl;
	std::cout << this->typeDesc() << std::endl;
	std::cout << "===" << std::endl;

	this->add(1);
	std::cout << "ArrayQueue.add(value: 1)" << std::endl;
	std::cout << "ArrayQueue.size() =  " << this->size() << std::endl;

	this->printAllElements();

	this->add(2);
	std::cout << "ArrayQueue.add(value: 2)" << std::endl;
	std::cout << "ArrayQueue.size() =  " << this->size() << std::endl;

	this->printAllElements();

	this->add(3);
	std::cout << "ArrayQueue.add(3)" << std::endl;
	std::cout << "ArrayQueue.size() =  " << this->size() << std::endl;

	this->printAllElements();

	this->remove();
	std::cout << "ArrayQueue.remove()" << std::endl;
	std::cout << "ArrayQueue.size() =  " << this->size() << std::endl;

	this->printAllElements();

	std::cout << "ArrayQueue.get(index: 1) = " << this->get(1) << std::endl;

	this->set(1, 4);
	std::cout << "ArrayQueue.set(index: 1, value: 4)" << std::endl;

	this->printAllElements();
}

// Print all elements in the data structure.
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

// ===
// ArrayDeque Testing Implementation
// ===

// Print all elements in the data structure.
template <typename T>
inline std::string ArrayDeque<T>::typeDesc() {
	return "2.4 | ArrayDeque: Fast Deque Operations Using an Array";
}

// Test the data structure.
template <typename T>
inline void ArrayDeque<T>::test() {
	std::cout << "===" << std::endl;
	std::cout << this->typeDesc() << std::endl;
	std::cout << "===" << std::endl;

	this->add(0, 1);
	std::cout << "ArrayDeque.add(index: 0, value: 1)" << std::endl;
	std::cout << "ArrayDeque.size() =  " << this->size() << std::endl;

	this->printAllElements();

	this->add(1, 2);
	std::cout << "ArrayDeque.add(index: 1, value: 2)" << std::endl;
	std::cout << "ArrayDeque.size() =  " << this->size() << std::endl;

	this->printAllElements();

	this->add(2, 3);
	std::cout << "ArrayDeque.add(index: 2, value: 3)" << std::endl;
	std::cout << "ArrayDeque.size() =  " << this->size() << std::endl;

	this->printAllElements();

	this->remove(0);
	std::cout << "ArrayDeque.remove(0)" << std::endl;
	std::cout << "ArrayDeque.size() =  " << this->size() << std::endl;

	this->printAllElements();

	std::cout << "ArrayDeque.get(index: 1) = " << this->get(1) << std::endl;

	this->set(1, 4);
	std::cout << "ArrayDeque.set(index: 1, value: 4)" << std::endl;

	this->printAllElements();
}

// Print all elements in the data structure.
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

// ===
// DualArrayDeque Testing Implementation
// ===

// Print a description of the data structure.
template <typename T>
inline std::string DualArrayDeque<T>::typeDesc() {
	return "2.5 | DualArrayDeque: Building a Deque from Two Stacks";
}

// Test the data structure.
template <typename T>
inline void DualArrayDeque<T>::test() {
	std::cout << "===" << std::endl;
	std::cout << this->typeDesc() << std::endl;
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

// Print all elements in the data structure.
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

// ===
// RootishArrayStack Testing Implementation
// ===

// Print a description of the data structure
template <typename T>
inline std::string RootishArrayStack<T>::typeDesc() {
	return "2.6 | RootishArrayStack: A Space-Efficient Array Stack";
}

// Test the data structure
template <typename T>
inline void RootishArrayStack<T>::test() {
	std::cout << "===" << std::endl;
	std::cout << this->typeDesc() << std::endl;
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

// Print all elements in the data structure.
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

#endif // TESTABLE_DATA_STRUCTURE_H
