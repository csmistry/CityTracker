//ECE250
//Node.h
//Purpose: Contains a city object and 4 pointers to other cities in directions 
//		   NE,NW,SE,SW	
//Author: Chintan Mistry
//Version 1.0 - 10/03/2020-

#include "CityInfo.h"

class Node {
	friend class Quadtree;
	Node* NW;
	Node* NE;
	Node* SW;
	Node* SE;
	CityInfo* cityInfo;
public:
	//getters for private member variables
	Node* getNE() { return this->NE; }
	Node* getNW() { return this->NW; }
	Node* getSW() { return this->SW; }
	Node* getSE() { return this->SE; }
	CityInfo* getCityInfo() { return this->cityInfo; }

	//Constructors & Destrucutors
	Node(CityInfo* _cityInfo) {
		NW = nullptr;
		NE = nullptr;
		SW = nullptr;
		SE = nullptr;
		cityInfo = _cityInfo;
	};

	~Node() {
		NW = nullptr;
		NE = nullptr;
		SW = nullptr;
		SE = nullptr;
		cityInfo = nullptr;
	}
};