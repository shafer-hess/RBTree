//#include <stdio>
#include <string>
#include "Node.h"

using namespace std;

int main() {

	Node<string, int> * n = new Node<string, int>();

	color c = n->getColor();

	cout << (c == 0 ? "RED" : "BLACK") << endl;

	n->setKey("double");
	n->setColor(BLACK);

	string k = n->getKey();
	c = n->getColor();

	cout << k << endl;
	cout << (c == 0 ? "RED" : "BLACK") << endl;

	delete n;


}

