#include "iostream"
#include "SLList.hpp"

int main() {
	SLList<int> list_stack;
	list_stack.testStack();

	SLList<int> list_queue;
	list_queue.testQueue();

	return 0;
}
