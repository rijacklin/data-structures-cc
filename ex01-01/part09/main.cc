#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

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

	// Create random seed value
	std::default_random_engine rng(std::chrono::system_clock::now().time_since_epoch().count());

	// Randomize the vector
	std::shuffle(lines.begin(), lines.end(), rng);

	// Print the randomized lines from the vector
	for (int i = 0; i < lines.size(); i++) {
		std::cout << lines[i] << std::endl;
	}

	// Close file
	file.close();
	return 0;
}
