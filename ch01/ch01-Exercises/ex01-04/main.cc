#include <iostream>
#include <stack>
#include <queue>
using namespace std;

stack<int> reverseStack(stack<int> s) {
	// Create a queue
	queue<int> q;

	// Loop through the stack, push each element onto the queue, and pop
	// the element off the stack
	while (!s.empty()) {
		q.push(s.top());
		s.pop();
	}

	// Loop through the queue, print the elements in opposite order, and pop
	// the elements off the queue
	while (!q.empty()) {
		s.push(q.front());
		q.pop();
	}

	return s;
}

int main() {
	// Create a stack and push elments into it
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	reverseStack(s);

	while (!s.empty()) {
		std::cout << s.top() << std::endl;
		s.pop();
	}

	return 0;
}
