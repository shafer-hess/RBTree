#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

enum color {RED, BLACK};

template <typename Key, typename Element>
class Node {
private:
	// Add class members here
	Node<Key, Element> * left;
	Node<Key, Element> * right;
	Node<Key, Element> * parent;

	color colorVal;
	Key key;
	Element element;

public:
	// Implement each of these methods
	Node();
	~Node();
	// These implementations are only to get the skeleton
	// code to compile. Ignore the warnings they generate
	// until you replace their implementations with your own
	const Key& getKey() const;
	const Element& getElement() const;
	Element& getElement();

	color getColor() /*const*/; /*{ return RED; }*/
	Node<Key, Element> * getParent();
	Node<Key, Element> * getLeft();
	Node<Key, Element> * getRight();

	void setKey(const Key& k);
	void setElement(const Element& e);
	void setColor(color c);

	void setLeft(Node<Key, Element> * node);
	void setRight(Node<Key, Element> * node);
	void setParent(Node<Key, Element> * node);

};

template <typename Key, typename Element>
Node<Key, Element>::Node() {
	colorVal = RED;
};

template <typename Key, typename Element>
Node<Key, Element>::~Node() {};

template<typename Key, typename Element>
Node<Key, Element> * Node<Key, Element>::getLeft() {
	return left;
}

template<typename Key, typename Element>
Node<Key, Element> * Node<Key, Element>::getRight() {
	return right;
}

template<typename Key, typename Element>
Node<Key, Element> * Node<Key, Element>::getParent() {
	return parent;
}

template<typename Key, typename Element>
color Node<Key, Element>::getColor() {
	return colorVal;
}

template<typename Key, typename Element>
const Element& Node<Key, Element>::getElement() const {
	return element;
}

template<typename Key, typename Element>
Element& Node<Key, Element>::getElement() {
	return element;
}

template<typename Key, typename Element>
const Key& Node<Key, Element>::getKey() const {
	return key;
}

template<typename Key, typename Element>
void Node<Key, Element>::setKey(const Key& k) {
	key = k;
}

template<typename Key, typename Element>
void Node<Key, Element>::setElement(const Element& e) {
	element = e;
}

template<typename Key, typename Element>
void Node<Key, Element>::setColor(color c) {
	colorVal = c;
}

template<typename Key, typename Element>
void Node<Key, Element>::setLeft(Node<Key, Element> * node) {
	left = node;
}

template<typename Key, typename Element>
void Node<Key, Element>::setRight(Node<Key, Element> * node) {
	right = node;
}

template<typename Key, typename Element>
void Node<Key, Element>::setParent(Node<Key, Element> * node) {
	parent = node;
}

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
