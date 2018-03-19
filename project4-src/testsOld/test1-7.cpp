#include <iostream>
#include <random>
#include <RBTree.h>
#include "validate.h"
using namespace std;

int main() {
	// Initialize random number generator (with a fixed seed)
	mt19937 rng(1010101u);
	uniform_int_distribution<> randInt(-30, 0xC0FFEE);
	uniform_int_distribution<> randLen(3, 10);
	uniform_int_distribution<char> randChar('a', 'z');

	// Create a tree, insert a number of elements
	int n = 72;
	int k = randInt(rng);
	RBTree<int, string> rbt;
	for (int i = 0; i < n; i++) {
		// Make a random string
		int l = randLen(rng);
		string e;
		for (int j = 0; j < l; j++)
			e.push_back(randChar(rng));

		if (i == 44)
			rbt.insert(k, e);
		else
			rbt.insert(randInt(rng), e);
	}

	// Search for the special key
	Node<int, string>* node = rbt.search(k);
	if (node == NULL) return 1;

	// Delete the key
	node = NULL;
	rbt.del(k);

	// Search for it again to make sure it's gone
	node = rbt.search(k);

	return !(validate(rbt) && rbt.size() == n-1 && node == NULL);
}
