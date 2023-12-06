#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool compareLength(const string& a, const string& b) {
	return a.length() < b.length();
}

int main() {
	ifstream file;
	file.open("../../text.txt");

	// Check if file is open
	if (!file.is_open()) {
		std::cerr << "Unable to open file" << std::endl;
		return 0;
	}

	string line;
	vector<string> lines;

	// Read the lines from the file and push each into a vector of strings
	while (getline(file, line)) {
		lines.push_back(line);
	}

	// Print the even lines
	std::cout << "|| EVEN LINES ||" << std::endl;
	for (int i = 0; i < lines.size(); i++) {
		if ((i + 1) % 2 == 0) {
			std::cout << lines[i] << std::endl;
		}
	}

	// Print the odd lines
	std::cout << "|| ODD LINES ||" << std::endl;
	for (int i = 0; i < lines.size(); i++) {
		if ((i + 1) % 2 != 0) {
			std::cout << lines[i] << std::endl;
		}
	}

	// Close file
	file.close();
	return 0;
}
