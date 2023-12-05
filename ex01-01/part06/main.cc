#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
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

	// Read the lines from the file
	while (getline(file, line)) {
		// Push each line into a Vector of string
		lines.push_back(line);
	}

	// Sort the vector by string length
	sort(lines.begin(), lines.end(), compareLength);

	for (int i = 0; i < lines.size(); i++) {
		std::cout << lines[i] << std::endl;
	}

	// Close file
	file.close();
	return 0;
}
