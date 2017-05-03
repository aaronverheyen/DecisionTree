#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <math.h>
#include <float.h>
#include <cstdlib>
#include <iomanip>
#include <list>
#include <numeric>
#include <algorithm>

using namespace std;
//Nodeklasse
template<class T>
class Node {
private:
	T data;
	Node<T>* parent;
	list<Node<T>*> children;
public:
	Node(Node<T>* par, T dat);
	~Node();
	T getData();
	list<Node<T>*> getChildren();
	Node<T>* getParent();
	void addChildren(Node<T> parentNode);
};

//Positieklasse
template <class T>
class Position {
private:
	Node<T>* nodePosition;
public:
	Position(Node<T>* par);
	T operator*();
	Position parent();
	list<Position> children();
};

template<class T>
class Tree {
private:
	Position<T> _root;
public:
	Tree();
	//int size();
	bool empty();
	Tree root();
	void makeTree(list<T> nodeChildren);
	//void printTree();
};
