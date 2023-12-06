#include <iostream>
#include <fstream>
#include <set>
#include <string>
using namespace std;

int main() {
	string line;
	set<string> lines;
	ifstream file;

	// Open file from disk
	file.open("../../text3.txt");

	// Check if file is open
	if (!file.is_open()) {
		std::cerr << "Unable to open file" << std::endl;
		return 0;
	}

	// Read the lines from the file
	while (getline(file, line)) {
		// Check if the set contains the current line
		if (*lines.find(line) == line) {
			std::cout << *lines.find(line) << std::endl;
			continue;
		}

		// Insert the line
		lines.insert(line);

		// Break from loop if end of file
		if (file.eof()) break;
	}

	// Close file
	file.close();
	return 0;
}
