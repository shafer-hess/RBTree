#ifndef PROJ4_RBTREE_H
#define PROJ4_RBTREE_H

#include "Node.h"
#include <iostream>
using namespace std;

template <typename Key, typename Element>
class RBTree {
private:
	// Add class members here
  int treeSize;
  Node<Key, Element> * root;

public:
	// Implement each of these methods
  RBTree();
  void insert(const Key& k, const Element& e);
  void BSTInsert(Node<Key, Element> * root, Node<Key, Element> * node);
  void fixViolation(Node<Key, Element> * root, Node<Key, Element> * node);
  Node<Key, Element>* search(const Key& k);
  void del(const Key& k);
  void inorder(ostream& out) const;
  void inorderHelper(ostream& out, Node<Key, Element> * node) const;
  void levelOrderHelper(ostream& out, Node<Key, Element> * node) const;
  void levelOrder(ostream& out) const;
  size_t size() const;
  Node<Key, Element>* getRoot();
};

//Constructor
template <typename Key, typename Element>
RBTree<Key, Element>::RBTree() {
  treeSize = 0;
}

//Insert into RB tree using binary search tree implemnetation then fixViolation later
template <typename Key, typename Element>
void RBTree<Key, Element>::BSTInsert(Node<Key, Element> * root, Node<Key, Element> * node) {
  if(root == NULL) {
    root->setKey(node->getKey());
    root->setElement(node->getElement());
    root->setColor(BLACK);
    return;
  }

  


}

// Function to insert a new node with given data
template <typename Key, typename Element>
void RBTree<Key, Element>::insert(const Key& k, const Element& e) {
  if(treeSize == 0) {
    root = new Node<Key, Element>;
    root->setKey(k);
    root->setElement(e);
    root->setColor(BLACK);
    treeSize++;
  }
}

// Function to search a node with given data
template <typename Key, typename Element>
Node<Key, Element>* RBTree<Key, Element>::search(const Key& k) {
	return NULL;
}

// Function to delete a node with given data
//TODO//
template <typename Key, typename Element>
void RBTree<Key, Element>::del(const Key& k) {}

template <typename Key, typename Element>
void RBTree<Key, Element>::inorderHelper(ostream& out, Node<Key, Element> * node) const {
  if(node == NULL) {
    return;
  }
  inorderHelper(out, node->getLeft());
  out << *node;
  inorderHelper(out, node->getRight());
}

// Function to do inorder traversal
//TODO//
template <typename Key, typename Element>
void RBTree<Key, Element>::inorder(ostream& out) const {
    inorderHelper(out, root);
}

template <typename Key, typename Element>
void RBTree<Key, Element>::levelOrderHelper(ostream& out, Node<Key, Element> * node) const {

}

// Function to perform level-order traversal
//TODO//
template <typename Key, typename Element>
void RBTree<Key, Element>::levelOrder(ostream& out) const {
    levelOrderHelper(out, root);
}
// Function to return the number of nodes in the RBTree
template <typename Key, typename Element>
size_t RBTree<Key, Element>::size() const {
  return treeSize;
}

// Function to return a pointer to the root of the RBTree
template <typename Key, typename Element>
Node<Key, Element>* RBTree<Key, Element>::getRoot() {
  return root;
}

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
