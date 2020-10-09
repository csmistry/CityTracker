//ECE250
//Quadtree.h
//Purpose: Quadtree data structure used to store cities
//Author: Chintan Mistry
//Version 1.0 - 10/03/2020
#include "Node.h"

class Quadtree {
	Node* root;
	int size;
public:
	int q_max(Node* qNode, int max, std::string attr, Node* root);
	int q_min(Node* qNode, int min, std::string attr, Node* root);
	int q_total(Node* qNode, int sum, std::string attr, Node* root);
	Node* Search(Node* qNode, double x, double y);
	void Insert(Node* newNode, Node* currentNode);
	void Clear(Node* qNode);
	void print(Node* qNode);
	int getSize();
	Node* getRoot() { return this->root; }

	//constructors & Destructors
	Quadtree() {
		root = nullptr;
		size = 0;
	}
	~Quadtree() {
		Clear(this->root);
	}
};