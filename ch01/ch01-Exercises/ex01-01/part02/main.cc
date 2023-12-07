#include <iostream>
#include <fstream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string line;
	stack<string> lines;
	ifstream file;

	// Open file from disk
	file.open("../../text.txt");

	// Track lines of file
	int lineCount = 0;
	const int maxLines = 50;

	// Check if file is open
	if (!file.is_open()) {
		std::cerr << "Unable to open file" << std::endl;
		return 1;
	}

	// Read the first 50 lines from the file and push them onto the stack
	while (getline(file, line)) {
		lines.push(line);
		lineCount++;

		// When 50 lines are read or end of file is reached
		if (lineCount == maxLines || file.eof()) {
			while (!lines.empty()) {
				std::cout << lines.top() << std::endl;
				lines.pop();
			}

			// Reset line count
			lineCount = 0;

			// Break from loop if end of file
			if (file.eof()) break;
		}
	}

	// Close file
	file.close();
	return 0;
}
