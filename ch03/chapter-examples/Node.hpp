#ifndef NODE
#define NODE

template <typename T>
class Node {
public:
	T x;
	Node *next;
	Node(T x0) {
		x = x0;
		next = 0;
	}
};

#endif // NODE
