#include <iostream>
#include <stack>
#include <vector> 
using namespace std;

int main() {
	// Create an array that the dyck_word vector will be created from
	// and an integer to calculate the number of elements in n using pointers
	int dyck_sequence[] = { 1, 1, -1, -1 };
	int n = sizeof(dyck_sequence) / sizeof(dyck_sequence[0]);

	// Create the dyck_word vector
	vector<int> word(dyck_sequence, dyck_sequence + n);

	// Create a stack to implement the dyck word operations
	stack<int> word_stack;
	int dyck_prop = 0;

	// Loop through the dyck_word and perform the corresponding stack operations
	for (int i = 0; i < word.size(); i++) {
		if (word[i] == 1) {
			word_stack.push(dyck_prop);
		} else if (word[i] == -1){
			// If the dyck word sequence is about to become negative, print
			// message and return.
			// (Otherwise, seg fault would occur due to `pop` operation being
			// performed on empty stack)
			if (word_stack.empty()) {
				std::cout << "Is not a Dyck word" << std::endl;
				return 1;
			}

			word_stack.pop();
		}
	}

	// Print to console result of dyck word operations
	if (word_stack.empty()) {
		std::cout << "Is a Dyck word" << std::endl;
	} else {
		std::cout << "Is not a Dyck word" << std::endl;
	}

	return 0;
}
