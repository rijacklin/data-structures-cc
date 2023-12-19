#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cassert>

template <typename T>
class Array {
public:
	T *a;
	int length;

	// Initializer
	Array(int len) {
		// Set the length of new array
		length = len;

		// Set a as new array of size length
		a = new T[length];
	}

	// Indexing - override [] operator
	T& operator[](int i) {
		// Ensure that the index is not less than zero and not larger than the
		// length of the array
		assert(i >= 0 && i < length);
		return a[i];
	}

	// Assignment - override = operator
	Array<T>& operator=(Array<T> &b) {
		// If a is not NULL, free the exiting memory for a
		if (a != NULL) delete[] a;

		// Copy the pointer from the source array
		a = b.a;

		// Set the source array's pointer to NULL (avoid double deletion)
		b.a = NULL;

		// Copy the length of the source array
		length = b.length;

		// Return a reference to the current object (allowing chaining
		// assignments)
		return *this;
	}
};

#endif // ARRAY_HPP
