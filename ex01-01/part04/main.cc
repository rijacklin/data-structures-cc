#include <iostream>
#include <fstream>
#include <set>
#include <string>
using namespace std;

int main() {
	ifstream file;
	file.open("../../text3.txt");

	// Check if file is open
	if (!file.is_open()) {
		std::cerr << "Unable to open file" << std::endl;
		return 1;
	}

	string line;
	set<string> lines;

	// Read the lines from the file
	while (getline(file, line)) {
		// Check if the set contains the current line
		if (lines.find(line) == lines.end()) {
			// If the set doesn't contain the line, insert and write to output
			lines.insert(line);
			std::cout << line << std::endl;
		}

		// Break from loop if end of file
		if (file.eof()) break;
	}

	// Close file
	file.close();
	return 0;
}
