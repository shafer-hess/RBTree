#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

enum color {RED, BLACK};

template <typename Key, typename Element>
class Node {
private:
	// Add class members here

public:
	// Implement each of these methods
	Node() {}

	// These implementations are only to get the skeleton
	// code to compile. Ignore the warnings they generate
	// until you replace their implementations with your own
	const Key& getKey() const { Key k; return k; }
	const Element& getElement() const { Element e; return e; }
	Element& getElement() { Element e; return e; }

	color getColor() const { return RED; }
	Node* getParent() { return NULL; }
	Node* getLeft() { return NULL; }
	Node* getRight() { return NULL; }

	void setKey(const Key& k) {}
	void setElement(const Element& e) {}
	void setColor(color c) {}
};



// The following functions have been provided for you, and do not
// need to be modified:


// Output stream operator overload -- writes the contents of a
// Node to the specified output stream. Note that there must be
// a similar operator overload for Key and Element types in
// order for this to compile.
// Example usage:
//		Node<K,E> n;
//		cout << n << endl;
template <typename Key, typename Element>
ostream& operator<<(ostream& out, const Node<Key, Element>& n) {
	out << n.getKey() << endl;
	out << n.getElement() << endl;
	return out;
}

// Input stream operator overload -- reads the contents of a
// Node from the specified input stream. Note that there must be
// a similar operator overload for Key and Element types in order
// for this to compile.
// Example usage:
//		Node<K,E> n;
//		cin >> n;
template <typename Key, typename Element>
istream& operator>>(istream& in, Node<Key, Element>& n) {
	// Clear existing contents, if any
	n = Node<Key, Element>();

	Key k;
	in >> k;
	Element e;
	in >> e;
	n.setKey(k);
	n.setElement(e);

	return in;
}

#endif
