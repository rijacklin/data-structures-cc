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
	string line;
	vector<string> lines;
	ifstream file;

	// Open file from disk
	file.open("../../text3.txt");

	// Check if file is open
	if (!file.is_open()) {
		std::cerr << "Unable to open file" << std::endl;
		return 0;
	}

	// Read the lines from the file and push each into a vector of strings
	while (getline(file, line)) {
		lines.push_back(line);
	}

	// Sort the vector by string length
	sort(lines.begin(), lines.end(), compareLength);

	// Print the lines, sorted by length, without duplicates
	for (int i = 0; i < lines.size(); i++) {
		std::cout << lines[i] << std::endl;
	}

	// Close file
	file.close();
	return 0;
}
