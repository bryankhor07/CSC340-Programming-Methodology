#pragma once
#include<iostream>
#include"Proj3Coordinate.h"
using namespace std;

class LocationBook {
private:
	int capacity;
	int locationCount;
	double** locations;
public:
	LocationBook();
	void addLocation(Coordinate coordinate);
	double totalDistanceTravelled();
	double viewDistanceToAGivenPoint(double x_coordinate, double y_coordinate);
};