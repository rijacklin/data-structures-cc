#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector> 
using namespace std;

int main() {
	char opening_chars[] = { '{', '(', '[' };
	char closing_chars[] = { '}', ')', ']' };

	map<int, char> open;

	// Create an array that will initialize the matched_string vector 
	// and an integer to calculate the number of elements using pointers
	char sequence[] = { '{', '{', '(', ')', '[', ']', '}', '}' };
	int n = sizeof(sequence) / sizeof(sequence[0]);

	// Create the matched_string vector
	vector<char> matched_string(sequence, sequence + n);

	// Create a stack to implement the matched string operations
	stack<char> matched_stack;

	char *opening_index;
	char *closing_index;

	// Loop through the sequence of chars and check whether each is an opening
	// or closing bracket
	for (int i = 0; i < matched_string.size(); i++) {
		if (find(begin(opening_chars), end(opening_chars), matched_string[i]) != end(opening_chars)) {
			opening_index = find(begin(opening_chars), end(opening_chars), matched_string[i]);
			// Assign the index and bracket character to the map of open chars
			// and push the char onto the stack
			open[i] = opening_chars[distance(opening_chars, opening_index - 0)];
			matched_stack.push(matched_string[i]);
		} else if (find(begin(closing_chars), end(closing_chars), matched_string[i]) != end(closing_chars)) {
			closing_index = find(begin(closing_chars), end(closing_chars), matched_string[i]);

			std::cout << matched_string[i] << std::endl;
			std::cout << open[distance(closing_chars, closing_index)] << std::endl;
			return 0;

			if (open[distance(closing_chars, closing_index)]) {
				open.erase(opening_chars[*closing_index - 0]);
				matched_stack.pop();
			}
		}

		if (opening_index) {
		} else if (closing_index) {
			// If there is a matching opening bracket, remove it from the map
			// and pop the corresponding opening char off the stack
		}
	}

	// Print to console result of the operations
	if (matched_stack.empty()) {
		std::cout << "Matched string" << std::endl;
	} else {
		std::cerr << "Not a matched string" << std::endl;
	}

	return 0;
}
