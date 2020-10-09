//ECE250
//Quadtree.cpp
//Purpose: Implementation for Quadtree class
//Author: Chintan Mistry
//Version 1.0 - 10/03/2020
#include "Quadtree.h"
#include <iostream>

//Searches for a node located at (x,y) starting from the root node
Node* Quadtree::Search(Node* qNode, double x, double y) {
	if (getSize() == 0) {
		return nullptr;
	}

	if (qNode == nullptr) {
		return nullptr;
	}
	else {
		if (x == qNode->cityInfo->x && y == qNode->cityInfo->y) {			
			return qNode;
		}
		else if (x >= qNode->cityInfo->x && y > qNode->cityInfo->y) {
			Search(qNode->NE, x, y);
		}
		else if (x < qNode->cityInfo->x && y >= qNode->cityInfo->y) {
			Search(qNode->NW, x, y);
		}
		else if (x <= qNode->cityInfo->x && y < qNode->cityInfo->y) {
			Search(qNode->SW, x, y);
		}
		else {
			Search(qNode->SE, x, y);
		}
	}
}

//Insert a new node into the tree
void Quadtree::Insert(Node* newNode, Node* currentNode) {

	//if tree is empty set root equal to the new node
	if (getSize() == 0) {
		this->root = newNode;
		this->size += 1;
		std::cout << "success" << "\n";
		return;
	}

	//if the new node already exists delete it and return
	if ((newNode->cityInfo->x == currentNode->cityInfo->x) && (newNode->cityInfo->y == currentNode->cityInfo->y)) {
		std::cout << "failure" << "\n";
		delete newNode->cityInfo;
		newNode->cityInfo = nullptr;
		delete newNode;
		newNode = nullptr;
		return;
	}
	else if ((newNode->cityInfo->x >= currentNode->cityInfo->x) && (newNode->cityInfo->y > currentNode->cityInfo->y)) {
		if (currentNode->NE == nullptr) {
			currentNode->NE = newNode;
			this->size += 1;
			std::cout << "success" << "\n";
			return;
		}
		else {
			Insert(newNode, currentNode->NE);
		}
	}
	else if ((newNode->cityInfo->x < currentNode->cityInfo->x) && (newNode->cityInfo->y >= currentNode->cityInfo->y)) {
		if (currentNode->NW == nullptr) {
			currentNode->NW = newNode;
			this->size += 1;
			std::cout << "success" << "\n";
			return;
		}
		else {
			Insert(newNode, currentNode->NW);
		}
	}
	else if ((newNode->cityInfo->x <= currentNode->cityInfo->x) && (newNode->cityInfo->y < currentNode->cityInfo->y)) {
		if (currentNode->SW == nullptr) {
			currentNode->SW = newNode;
			this->size += 1;
			std::cout << "success" << "\n";
			return;
		}
		else {
			Insert(newNode, currentNode->SW);
		}
	}
	else {
		if (currentNode->SE == nullptr) {
			currentNode->SE = newNode;
			this->size += 1;
			std::cout << "success" << "\n";
			return;
		}
		else {
			Insert(newNode, currentNode->SE);
		}
	}
}

//dealloacte all nodes and CityInfo objects in the tree
void Quadtree::Clear(Node* qNode) {
	if (getSize() == 0) {
		return;
	}

	if (qNode != nullptr) {
		Clear(qNode->NE);
		Clear(qNode->NW);
		Clear(qNode->SW);
		Clear(qNode->SE);
		delete qNode->cityInfo;
		qNode->cityInfo = nullptr;
		delete qNode;
		qNode = nullptr;
		this->size -= 1;
		return;
	}
	return;
}

//print all cities in the tree using an inorder traversal
void Quadtree::print(Node* qNode) {
	if (getSize() == 0) {
		return;
	}

	if (qNode != nullptr) {
		print(qNode->NE);
		print(qNode->NW);
		std::cout << qNode->cityInfo->Name << " ";
		print(qNode->SW);
		print(qNode->SE);
	}
}

//find the maximum value of a specified attribute under the given node
int Quadtree::q_max(Node* qNode, int max, std::string attr, Node* root) {
	if (qNode != nullptr) {
		max = q_max(qNode->NE, max, attr, root);
		max = q_max(qNode->NW, max, attr, root);
		max= q_max(qNode->SW, max, attr, root);
		max = q_max(qNode->SE, max, attr, root);

		//compare current max with the value at the current node
		if (attr == "p") {
			max = (qNode->cityInfo->Population > max) ? qNode->cityInfo->Population : max;
		}
		else if (attr == "r") {
			max = (qNode->cityInfo->CostOfLiving > max) ? qNode->cityInfo->CostOfLiving : max;
		}
		else {
			max = (qNode->cityInfo->AvgNetSalary > max) ? qNode->cityInfo->AvgNetSalary : max;
		}

		//finally compare the subtree max with the given node (not necessarily root of whole Quadtree)
		if (qNode == root) {
			if (attr == "p") {
				max = (root->cityInfo->Population > max) ? root->cityInfo->Population : max;
			}
			else if (attr == "r") {
				max = (root->cityInfo->CostOfLiving > max) ? root->cityInfo->CostOfLiving : max;
			}
			else {
				max = (root->cityInfo->AvgNetSalary > max) ? root->cityInfo->AvgNetSalary : max;
			}
		}
		return max;
	}
	return max;

}

//find the minimum value of a specified attribute under the given node
int Quadtree::q_min(Node* qNode, int min, std::string attr, Node* root) {
	if (qNode != nullptr) {
		min = q_min(qNode->NE, min, attr, root);
		min = q_min(qNode->NW, min, attr, root);
		min = q_min(qNode->SW, min, attr, root);
		min = q_min(qNode->SE, min, attr, root);

		//compare current min with the value at the current node
		if (attr == "p") {
			min = (qNode->cityInfo->Population < min) ? qNode->cityInfo->Population : min;
		}
		else if (attr == "r") {
			min = (qNode->cityInfo->CostOfLiving < min) ? qNode->cityInfo->CostOfLiving : min;
		}
		else {
			min = (qNode->cityInfo->AvgNetSalary < min) ? qNode->cityInfo->AvgNetSalary : min;
		}

		//finally compare the subtree min with the given node (not necessarily root of whole Quadtree) 
		if (qNode == root) {
			if (attr == "p") {
				min = (root->cityInfo->Population < min) ? root->cityInfo->Population : min;
			}
			else if (attr == "r") {
				min = (root->cityInfo->CostOfLiving < min) ? root->cityInfo->CostOfLiving : min;
			}
			else {
				min = (root->cityInfo->AvgNetSalary < min) ? root->cityInfo->AvgNetSalary : min;
			}
		}
		return min;
	}
	return min;
}

//find the total value of an attribute under the specified node
int Quadtree::q_total(Node* qNode, int sum, std::string attr, Node* root) {
	if (qNode != nullptr) {
		sum = q_total(qNode->NE, sum, attr, root);
		sum = q_total(qNode->NW, sum, attr, root);
		sum = q_total(qNode->SW, sum, attr, root);
		sum = q_total(qNode->SE, sum, attr, root);
		if (attr == "p") {
			sum += qNode->cityInfo->Population;
		}
		else if (attr == "r") {
			sum += qNode->cityInfo->CostOfLiving;
		}
		else {
			sum += qNode->cityInfo->AvgNetSalary;
		}
		return sum;
	}
	return sum;
}

//return current size of Quadtree
int Quadtree::getSize() {
	return this->size;
}