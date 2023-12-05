#include <iostream>
#include <fstream>
#include <queue>
#include <string>
using namespace std;

int main() {
	ifstream file;
	file.open("../../text2.txt");

	// Track lines of file
	int lineCount = 0;
	const int maxLines = 42;

	// Check if file is open
	if (!file.is_open()) {
		std::cerr << "Unable to open file" << std::endl;
		return 1;
	}

	string line;
	queue<string> lines;

	// Read the lines from the file
	while (getline(file, line)) {
		lineCount++;
		lines.push(line);

		// When 42 lines are read, check for blank lines.
		// If there's a blank line, print the line 42 lines previous
		// (this line will be on the top of queue).
		if (lineCount > maxLines) {
			// Check if line is empty and print either the line
			// or line at front of stack.
			if (!line.empty()) {
				std::cout << line << std::endl;
			} else {
				std::cout << lines.front() << std::endl;
			}

			// Dequeue oldest line
			lines.pop();
		} else {
			std::cout << line << std::endl;
		}

		// Break from loop if end of file
		if (file.eof()) break;
	}

	// Close file
	file.close();
	return 0;
}
