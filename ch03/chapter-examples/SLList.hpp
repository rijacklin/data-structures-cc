#ifndef SL_LIST_HPP
#define SL_LIST_HPP

#include "Node.hpp"
#include <iostream>

template <typename T>
class SLList {
public:
	Node<T> *head;
	Node<T> *tail;
	int n;

	SLList() : n(0) {}

	// Implements Stack operation push() by pushing at the head of the list
	// Runs in constant time - O(1)
	T push(T x) {
		// Creates a new node with element x
		Node<T> *u= new Node<T>(x);

		// Set the pointer to the next node as the previous head of the list
		if (n != 0) {
			u->next = head;
		}

		// Make the newly created node u the head of the list
		head = u;

		// If the list is empty, set u as the head of the list as well
		if (n == 0) {
			tail = u;
		}

		// Increment the number of elements in the list
		n++;

		return x;
	}

	// Implements Stack operation pop() by popping off the head of the list
	// Runs in constant time - O(1)
	T pop() {
		// Check if the list is empty before removing
		if (n == 0) return 0;

		// Remove the head of the list
		T x = head->x;
		Node<T> *u = head;
		head = head->next;
		delete u;

		// Decrement n, and if the list becomes empty, remove the tail
		if (--n == 0) {
			tail = 0;
		}

		return x;
	}

	// Implements FIFO queue operation add(x) - Additions at tail of list
	// Runs in constant time - O(1)
	bool add(T x) {
		// Creates a new node with element x
		Node<T> *u= new Node<T>(x);

		// If the list is empty (tail = head = 0), make u the head of the list
		if (n == 0) {
			head = u;
		} else {
			// Otherwise, make u the next element that the tail points to
			tail->next = u;
		}

		// Make u the tail of the list
		tail = u;

		// Increment n
		n++;

		return true;
	}

	// Implements FIFO queue operation remove() - Removals from head of list
	// Runs in constant time - O(1)
	T remove() {
		// Check if the list is empty before removing
		if (n == 0) return 0;
		T x = head->x;

		// Remove the head of the list
		Node<T> *u = head;
		head = head->next;
		delete u;

		// Decrement n, and if the list becomes empty, remove the tail
		if (--n == 0) {
			tail = 0;
		}

		return x;
	}

	// === TESTING ===

	void testStack() {
		std::cout << "===" << std::endl;
		std::cout << "3.1 | SLList: A Singly-Linked List ";
		std::cout << "> Testing pop/push Stack operations" << std::endl;
		std::cout << "===" << std::endl;
		std::cout << std::endl;

		this->push(1);
		std::cout << "SLList.push(value: 1)" << std::endl;
		printAllElements();

		this->push(2);
		std::cout << "SLList.push(value: 2)" << std::endl;
		printAllElements();

		this->push(3);
		std::cout << "SLList.push(value: 3)" << std::endl;
		printAllElements();

		this->pop();
		std::cout << "SLList.pop()" << std::endl;
		printAllElements();

		this->pop();
		std::cout << "SLList.pop()" << std::endl;
		printAllElements();
	}

	void testQueue() {
		std::cout << "===" << std::endl;
		std::cout << "3.1 | SLList: A Singly-Linked List ";
		std::cout << "> Testing add/remove Queue operations" << std::endl;
		std::cout << "===" << std::endl;
		std::cout << std::endl;

		this->add(1);
		std::cout << "SLList.add(value: 1)" << std::endl;
		printAllElements();

		this->add(2);
		std::cout << "SLList.add(value: 2)" << std::endl;
		printAllElements();

		this->add(3);
		std::cout << "SLList.add(value: 3)" << std::endl;
		printAllElements();

		this->remove();
		std::cout << "SLList.remove()" << std::endl;
		printAllElements();

		this->remove();
		std::cout << "SLList.remove()" << std::endl;
		printAllElements();
	}

	void printAllElements() {
		std::cout << "\t> Contains Elements: [";

		Node<T> *a = this->head;

		while (a != 0) {
			if (n == 1 || a->next == 0) {
				std::cout << a->x;
				break;
			} else {
				std::cout << a->x << ", ";
				a = a->next;
			}
		}
		std::cout << "]" << std::endl;

		std::cout << "\t Head = " << this->head->x;
		std::cout << " Tail = " << this->tail->x << std::endl;

		std::cout << std::endl;
	}
};

#endif // SL_LIST_HPP
