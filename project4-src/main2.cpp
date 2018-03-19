#include <iostream>
#include <random>
#include "RBTree.h"

using namespace std;

int main() {
	mt19937 rng(250386u);
	uniform_int_distribution<> randInt(-1000000, 1000000);
	uniform_real_distribution<float> randFloat(0.0, 10.0);

	int n = 100;
	RBTree<int, float> rbt;
	for(int i = 0; i < n; i++) {
		rbt.insert(randInt(rng), randFloat(rng));
	}
	
	rbt.inorder(cout);
	return 0;

}
