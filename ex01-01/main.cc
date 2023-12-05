#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

int main() {
	ifstream file;
	file.open("text.txt");

	// Check if file is open for reading operation
	if (!file.is_open()) {
		std::cerr << "Unable to open file" << std::endl;
		return 1;
	}

	string line;
	set<string> set;

	// Read lines from file and write to std output
	while (getline(file, line)) {
		set.insert(line);
	}

	// Reverse through the set using an iterator and print each line
	for (std::set<string>::reverse_iterator it = set.rbegin(); it != set.rend(); ++it) {
		std::cout << *it << std::endl;
	}

	// Close the file
	file.close();
	return 0;
}
