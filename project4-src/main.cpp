//#include <stdio>
#include <string>
#include "Node.h"
#include "RBTree.h"

using namespace std;

int main() {

	Node<int, string> * n = new Node<int, string>();

	color c = n->getColor();

	cout << (c == 0 ? "RED" : "BLACK") << endl;

	n->setKey(1);
	n->setColor(BLACK);

	int k = n->getKey();
	c = n->getColor();

	cout << k << endl;
	cout << (c == 0 ? "RED" : "BLACK") << endl;

	RBTree<int, string> * tree = new RBTree<int,string>();
	tree->insert(2, "hello");
	
	color c2 = tree->getRoot()->getColor();
	cout << (c2 == 0 ? "RED" : "BLACK") << endl;

	Node<int, string> * n2 = new Node<int, string>();
	n2->setKey(2);
	n2->setElement("new");

	tree->insert(n2->getKey(), n2->getElement());

	color c3 = tree->getRoot()->getRight()->getColor();
	cout << (c3 == 0 ? "RED" : "BLACK") << endl;
	cout << tree->getRoot()->getRight()->getKey() << endl;
	cout << tree->getRoot()->getRight()->getElement() << endl;

	cout << endl << endl << endl;	

	tree->inorder(cout);

//	delete n;


}

