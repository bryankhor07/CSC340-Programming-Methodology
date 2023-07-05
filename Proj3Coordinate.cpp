#include"Proj3Coordinate.h"
#include<iostream>
using namespace std;

// Constructor. Initializes the x and y coordinates
Coordinate::Coordinate(double x_coordinate, double y_coordinate) {
	this->x_coordinate = x_coordinate;
	this->y_coordinate = y_coordinate;
}

// Default constructor. Initializes x and y coordinates to 0
Coordinate::Coordinate() {
	x_coordinate = 0;
	y_coordinate = 0;
}

// Return the x coordinate
double Coordinate::getX_coordinate() {
	return this->x_coordinate;
}

// Return the y coordinate
double Coordinate::getY_coordinate() {
	return this->y_coordinate;
}

// Sets the x coordinate to a new value
void Coordinate::setX_coordinate(double x_coordinate) {
	this->x_coordinate = x_coordinate;
}

// Sets the y coordinate to a new value
void Coordinate::setY_coordinate(double y_coordinate) {
	this->y_coordinate = y_coordinate;
}