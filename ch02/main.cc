#include <iostream>
#include <typeinfo>
#include <type_traits>

#include "./chapter-examples/ArrayStack.h"
#include "./chapter-examples/FastArrayStack.h"
#include "./chapter-examples/ArrayQueue.h"
#include "./chapter-examples/ArrayDequeue.h"
#include "./chapter-examples/DualArrayDequeue.h"
#include "./chapter-examples/RootishArrayStack.h"

using namespace std;

int main() {
	RootishArrayStack<int> stack;
	stack.test();

	return 0;
}
