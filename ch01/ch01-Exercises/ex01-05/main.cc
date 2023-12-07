#include <iostream>
#include <list>
#include <unordered_set>
using namespace std;

unordered_set<int> add(unordered_set<int> &bag, int x);

unordered_set<int> remove(unordered_set<int> &bag, int x);

int find(unordered_set<int> &bag, int x);

list<int> findAll(unordered_set<int> &bag, int x);

int main() {	
	unordered_set<int> bag;

	add(bag, 1);
	add(bag, 2);
	add(bag, 3);
	add(bag, 1);

	int i = find(bag, 1);
	std::cout << "Found: " << i << std::endl;
	std::cout << std::endl;

	list<int> list = findAll(bag, 1);
	std::cout << "Found the following elements: " << std::endl;
	for (auto it = list.begin(); it != list.end(); ++it) {
		std::cout << "\t* " << *it << std::endl;
	}

	return 0;
}

unordered_set<int> add(unordered_set<int> &bag, int x) {
	bag.insert(x);
	return bag;
}

unordered_set<int> remove(unordered_set<int> &bag, int x) {
	bag.erase(x);
	return bag;
}

int find(unordered_set<int> &bag, int x) {
	auto it = bag.find(x);
	return *it;
}

list<int> findAll(unordered_set<int> &bag, int x) {
	list<int> list;

	for (auto it = bag.begin(); it != bag.end(); ++it) {
		std::cout << *it << std::endl;
		// if (*it == x) {
		// 	list.insert(list.begin(), *it);
		// }
	}

	return list;
}
