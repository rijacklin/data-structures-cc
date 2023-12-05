#include <iostream>
#include <fstream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ifstream file;
	file.open("../../text.txt");

	// Check if file is open for reading operation
	if (!file.is_open()) {
		std::cerr << "Unable to open file" << std::endl;
		return 1;
	}

	string line;
	stack<string> lines;

	// Read each line from file and push it onto the stack
	while (getline(file, line)) {
		lines.push(line);
	}

	// Close the file
	file.close();

	// Pop each element off the stack
	while (!lines.empty()) {
		std::cout << lines.top() << std::endl;
		lines.pop();
	}

	return 0;
}
