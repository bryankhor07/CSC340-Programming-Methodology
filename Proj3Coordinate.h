#pragma once
#include<iostream>
using namespace std;

class Coordinate {
private:
	double x_coordinate;
	double y_coordinate;
public:
	Coordinate(double x_coordinate, double y_coordinate);
	Coordinate();
	double getX_coordinate();
	double getY_coordinate();
	void setX_coordinate(double x_coordinate);
	void setY_coordinate(double y_coordinate);
};