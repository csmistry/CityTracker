//ECE250
//CityInfo.h
//Purpose: Class to hold information relative to cites being added to 
//		   the Quadtree Data Structure
//Author: Chintan Mistry
//Version 1.0 - 10/03/2020
#include<string>

class CityInfo {
	friend class Quadtree;
	std::string Name;
	double x;
	double y;
	int Population;
	int CostOfLiving;
	int AvgNetSalary;

public:
	//getters for private member variables
	std::string getName() { return this->Name; }
	int getP() { return this->Population; }
	int getR() { return this->CostOfLiving; }
	int getS() { return this->AvgNetSalary; }

	//Constructors & Destructors
	CityInfo(std::string name, double longi, double latti, int pop, int CoL, int AvgNS) {
		Name = name;
		x = longi;
		y = latti;
		Population = pop;
		CostOfLiving = CoL;
		AvgNetSalary = AvgNS;
	};


};