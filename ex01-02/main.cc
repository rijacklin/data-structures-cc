#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream file;
	file.open("../text.txt");

	// Check if file is open
	if (!file.is_open()) {
		std::cerr << "Unable to open file" << std::endl;
		return 1;
	}

	return 0;
}
