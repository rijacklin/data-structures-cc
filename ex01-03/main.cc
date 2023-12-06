#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector> 
using namespace std;

bool isMatchedString(string str) {
	// Create vectors of opening and closing brackets
	vector<char> opening_chars = { '{', '(', '[' };
	vector<char> closing_chars = { '}', ')', ']' };

	// Create a stack to implement the matched string operations
	stack<char> matched_stack;

	// Loop through the sequence of chars and check whether each is an opening
	// or closing bracket
	for (int i = 0; i < sizeof(str) / sizeof(char); i++) {
		if (find(opening_chars.begin(), opening_chars.end(), str[i]) != opening_chars.end()) {
			// Push the opening bracket onto the stack
			matched_stack.push(str[i]);
		} else if (find(closing_chars.begin(), closing_chars.end(), str[i]) != closing_chars.end()) {
			// If first bracket is a closing bracket, return false
			if (matched_stack.empty()) return false;

			// Create an interator over the vector of closing chars to get
			// its index in the vector
			auto it = find(closing_chars.begin(), closing_chars.end(), str[i]);
			int index = distance(closing_chars.begin(), it);

			// If the top char on the stack matches the closing brace, pop it
			// off the stack
			// Otherwise, break out of the loop
			if (opening_chars[index] == matched_stack.top()) {
				matched_stack.pop();
			} else {
				break;
			}
		}
	}

	return matched_stack.empty();
}

int main() {
	string str = "{{()[]}}";

	// Print to console the result of the operations
	if (isMatchedString(str)) {
		std::cout << "Matched string" << std::endl;
	} else {
		std::cerr << "Not a matched string" << std::endl;
	}

	return 0;
}
