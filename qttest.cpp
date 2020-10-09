//ECE250
//qttest.cpp
//Purpose: Driver program used to call appropriate methods based on input
//Author: Chintan Mistry
//Version 1.0 - 10/03/2020
#include <iostream>
#include "Quadtree.h"

int main() {
	std::string input = "";
	std::string cmd = "";
	Quadtree qTree;
	
	while (std::cin) {
		std::getline(std::cin, input);
		cmd = input.substr(0, input.find_first_of(" "));
		
		if (cmd == "i") {
			input = input.substr(input.find_first_of(" ") +1, input.length());

			// Parse input
			std::string name = input.substr(0, input.find_first_of(";"));
			input = input.substr(input.find_first_of(";")+1, input.length());
			double x = std::stod(input.substr(0, input.find_first_of(";")));
			input = input.substr(input.find_first_of(";")+1, input.length());
			double y = std::stod(input.substr(0, input.find_first_of(";")));
			input = input.substr(input.find_first_of(";")+1, input.length());
			int pop = std::stoi(input.substr(0, input.find_first_of(";")));
			input = input.substr(input.find_first_of(";")+1, input.length());
			int CoL = std::stoi(input.substr(0, input.find_first_of(";")));
			input = input.substr(input.find_first_of(";")+1, input.length());
			int AvgNS = std::stoi(input.substr(0, input.length()));
			
			//Create a new node to insert
			CityInfo* newInfo = new CityInfo(name, x, y, pop, CoL, AvgNS);
			Node* newNode = new Node(newInfo);
			qTree.Insert(newNode, qTree.getRoot());
			
		}
		else if (cmd == "s") {
			input = input.substr(input.find_first_of(" ")+1, input.length());

			double x = std::stod(input.substr(0, input.find_first_of(";")));
			input = input.substr(input.find_first_of(";")+1, input.length());
			double y = std::stod(input);
			
			Node* resultNode = qTree.Search(qTree.getRoot(), x, y);
			if (resultNode != nullptr) {
				std::cout << "found " << resultNode->getCityInfo()->getName() << "\n";
			}
			else {
				std::cout << "not found" << "\n";
			}
			
		}
		else if (cmd == "q_max") {
			input = input.substr(input.find_first_of(" ")+1, input.length());

			double x = std::stod(input.substr(0, input.find_first_of(";")));
			input = input.substr(input.find_first_of(";")+1, input.length());
			double y = std::stod(input.substr(0, input.find_first_of(";")));
			input = input.substr(input.find_first_of(";")+1, input.length());
			std::string d = input.substr(0, input.find_first_of(";"));
			input = input.substr(input.find_first_of(";")+1, input.length());
			std::string attr = input;
			
			//call q_max on in the requested direction of the node at position (x,y)
			Node* parentNode = qTree.Search(qTree.getRoot(), x, y);
			if (parentNode != nullptr) {
				int max = INT32_MIN;
				if (d == "NE") {
					max = qTree.q_max(parentNode->getNE(), max, attr, parentNode->getNE());
				}
				else if (d == "NW") {
					max = qTree.q_max(parentNode->getNW(), max, attr, parentNode->getNW());
				}
				else if (d == "SW") {
					max =qTree.q_max(parentNode->getSW(), max, attr, parentNode->getSW());
				}
				else {
					max = qTree.q_max(parentNode->getSE(), max, attr, parentNode->getSE());
				}	
				
				if (max == INT32_MIN) {
					std::cout << "failure" << "\n";
				}
				else {
					std::cout << "max " << max << "\n";
				}				
			}
			else {
				std::cout << "failure" << "\n";
			}			 
		}
		else if (cmd == "q_min") {
			input = input.substr(input.find_first_of(" ")+1, input.length());

			double x = std::stod(input.substr(0, input.find_first_of(";")));
			input = input.substr(input.find_first_of(";")+1, input.length());
			double y = std::stod(input.substr(0, input.find_first_of(";")));
			input = input.substr(input.find_first_of(";")+1, input.length());
			std::string d = input.substr(0, input.find_first_of(";"));
			input = input.substr(input.find_first_of(";")+1, input.length());
			std::string attr = input;

			//call q_min on in the requested direction of the node at position (x,y)
			Node* parentNode = qTree.Search(qTree.getRoot(), x, y);
			if (parentNode != nullptr) {
				int min = INT32_MAX;
				if (d == "NE") {
					min = qTree.q_min(parentNode->getNE(), min, attr, parentNode->getNE());
				}
				else if (d == "NW") {
					min = qTree.q_min(parentNode->getNW(), min, attr, parentNode->getNW());
				}
				else if (d == "SW") {
					min = qTree.q_min(parentNode->getSW(), min, attr, parentNode->getSW());
				}
				else {
					min = qTree.q_min(parentNode->getSE(), min, attr, parentNode->getSE());
				}

				if (min == INT32_MAX) {
					std::cout << "failure" << "\n";
				}
				else {
					std::cout << "min " << min << "\n";
				}
			}
			else {
				std::cout << "failure" << "\n";
			}
		}
		else if (cmd == "q_total") {
			input = input.substr(input.find_first_of(" ")+1, input.length());

			double x = std::stod(input.substr(0, input.find_first_of(";")));
			input = input.substr(input.find_first_of(";")+1, input.length());
			double y = std::stod(input.substr(0, input.find_first_of(";")));
			input = input.substr(input.find_first_of(";")+1, input.length());
			std::string d = input.substr(0, input.find_first_of(";"));
			input = input.substr(input.find_first_of(";")+1, input.length());
			std::string attr = input;

			//call q_total on in the requested direction of the node at position (x,y)
			Node* parentNode = qTree.Search(qTree.getRoot(), x, y);
			if (parentNode != nullptr) {
				int sum=0;
				if (d == "NE") {
					sum = qTree.q_total(parentNode->getNE(), sum, attr, parentNode->getNE());
				}
				else if (d == "NW") {
					sum = qTree.q_total(parentNode->getNW(), sum, attr, parentNode->getNW());
				}
				else if (d == "SW") {
					sum = qTree.q_total(parentNode->getSW(), sum, attr, parentNode->getSW());
				}
				else {
					sum = qTree.q_total(parentNode->getSE(), sum, attr, parentNode->getSE());
				}

				if (sum == 0) {
					std::cout << "failure" << "\n";
				}
				else {
					std::cout << "total " << sum << "\n";
				}
			}
			else {
				std::cout << "failure" << "\n";
			}
		
		}
		else if (cmd == "print") {
			if (qTree.getSize() != 0) {
				qTree.print(qTree.getRoot());
				std::cout << std::endl;
				}
			
		}
		else if (cmd == "clear") {
			qTree.Clear(qTree.getRoot());
			std::cout << "success" << "\n";
		}
		else if (cmd == "size") {
			std::cout << "tree size " << qTree.getSize() << "\n";
		}
	}
}