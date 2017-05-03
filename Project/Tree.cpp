	/*#include <iostream>
#include <string>
#include <list>
#include "prototypes2.h"
using namespace std;

//Node functies

template<class T>
Node<T> :: Node(Node<T>* par, T dat){
	parent = par;
	data = new T(data);
}

template<class T>
Node<T> :: ~Node() {
	delete data;
	for (Node<T>* child : children)
		delete child;
}


template<class T>
typename T Node<T> :: getData(){
	return data;
}

template<class T>
list<Node<T>*> Node<T>::getChildren()
{
	return children;
}

template<class T>
Node<T>* Node<T>::getParent()
{
	return parent;
}

template<class T>
void Node<T>::addChildren(Node<T> parentNode) {
	//parentNode.getData() : split uitvoeren
		int size; //aantal childeren dat moet worden toegevoegd (splitsize?)
	for (int i = 0; i++; i < size) {
		//Node(parentNode, split(i));
	}
}

//Positiefuncties
template<class T>
Position<T>::Position(Node<T>* node){
	nodePosition = node;
}

template<class T>
typename T Position<T>::operator*(){
	return nodePosition.getData();
}

template<class T>
Position<T> Position<T>::parent(){
	return Position(nodePosition.getParent());
}

template<class T>
list<Position<T>> Position<T>::children(){
	return Position(nodePosition.getChildren());
}

//Treefuncties


/*template<class T>
int Tree<T>::size()
{
	return 0;
}*/
/*
template<class T>
Tree<T>::Tree(){
	Node<T> node;// = Node(nullptr, train.dat)
	node* = _root;
	node.addChildren();
}

template<class T>
bool Tree<T>::empty()
{
	return _root == nullptr;
}

template<class T>
Position<T> Tree<T>::root()
{
	return _root;
}

template<class T>
void Tree<T>::makeTree(list<T> nodeChildren){
	list<Node<T>>::iterator it = nodeChildren.begin();
	for (int k = 0; k++; k<nodeChildren.size()) {
		if (/*it.getData()!= eenduidig*//*) {
		/*	it.addChildren();
			makeTree(it.getChildren);
		}
		it++;
	}
}




/*template<class T>
void Tree<T>::printTree()
{
}*/
