#ifndef PROJ4_RBTREE_H
#define PROJ4_RBTREE_H

#include "Node.h"
#include <iostream>
using namespace std;

template <typename Key, typename Element>
class RBTree {
private:
	// Add class members here

public:
	// Implement each of these methods
    RBTree() {}
    void insert(const Key& k, const Element& e);
    Node<Key, Element>* search(const Key& k);
    void del(const Key& k);
    void inorder(ostream& out) const;
    void levelOrder(ostream& out) const;
	size_t size() const;
	Node<Key, Element>* getRoot();
};


// Function to insert a new node with given data
template <typename Key, typename Element>
void RBTree<Key, Element>::insert(const Key& k, const Element& e) {}

// Function to search a node with given data
template <typename Key, typename Element>
Node<Key, Element>* RBTree<Key, Element>::search(const Key& k) {
	return NULL;
}

// Function to delete a node with given data
template <typename Key, typename Element>
void RBTree<Key, Element>::del(const Key& k) {}

// Function to do inorder traversal
template <typename Key, typename Element>
void RBTree<Key, Element>::inorder(ostream& out) const {}

// Function to perform level-order traversal
template <typename Key, typename Element>
void RBTree<Key, Element>::levelOrder(ostream& out) const {}

// Function to return the number of nodes in the RBTree
template <typename Key, typename Element>
size_t RBTree<Key, Element>::size() const { return 0; }

// Function to return a pointer to the root of the RBTree
template <typename Key, typename Element>
Node<Key, Element>* RBTree<Key, Element>::getRoot() { return NULL; }


// The following functions have been provided for you, and do not
// need to be modified:


// Output stream operator overload -- writes the contents of the
// entire RBTree to the specified output stream, using an in-order
// traversal. Note that there must be a similar operator overload
// for Key and Element types in order for this to compile.
// Example usage:
//		RBTree<K,E> rbt;
//		cout << rbt << endl;
template <typename Key, typename Element>
ostream& operator<<(ostream& out, const RBTree<Key, Element>& rbtree) {
	out << rbtree.size() << endl;
	rbtree.inorder(out);
	return out;
}

// Input stream operator overload -- reads the contents of an RBTree
// from the specified input stream, inserting each Node as it is
// read. Note that there must be a similar operator overload for Key
// and Element types in order for this to compile.
// Example usage:
//		RBTree<K,E> rbt;
//		cin >> rbt;
template <typename Key, typename Element>
istream& operator>>(istream& in, RBTree<Key, Element>& rbtree) {
	// Clear existing contents, if any
	rbtree = RBTree<Key, Element>();

	// Read in the number of elements to read
	size_t size;
	in >> size;
	for (size_t i = 0; i < size; i++) {
		// Read in each node as it appears in the stream
		Node<Key, Element> n;
		in >> n;
		// Insert the node into the RBTree
		rbtree.insert(n.getKey(), n.getElement());
	}

	return in;
}

#endif //PROJ4_RBTREE_H
