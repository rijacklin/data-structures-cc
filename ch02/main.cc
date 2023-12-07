#include <iostream>
#include "./chapter-examples/ArrayStack.h"

using namespace std;

int main() {
	ArrayStack<int> stack;

	stack.add(0, 1);
	stack.add(1, 2);
	stack.add(2, 3);

	std::cout << "Size of ArrayStack: " << stack.size() << std::endl;

	std::cout << "Removed: " << stack.remove(1) << std::endl;

	std::cout << "Size of ArrayStack: " << stack.size() << std::endl;

	return 0;
}
