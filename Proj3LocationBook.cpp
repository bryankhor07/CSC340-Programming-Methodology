#include"LocationBook.h"
#include"Coordinate.h"
#include<iostream>
#include<cmath>
using namespace std;

/*
Default constructor.
Initializes the capacity to 5, locationCount to 0 and allocate memory for locations.
*/
LocationBook::LocationBook() {
	this->capacity = 5;
	this->locationCount = 0;
	this->locations = new double* [capacity];
	for (int i = 0; i < capacity; i++) {
		locations[i] = new double[2]; // Allocate memory for locations
	}
}

/*
addLocation takes the coordinates x and y and store it in locations
If the number of locations stored reaches its capacity, I double the size of capacity,
create a temp 2d array and copy the coordinates from locations.
After that, I free the memory for the old array and store new coordinates for the locations array.
*/
void LocationBook::addLocation(Coordinate coordinate) {
	if (locationCount == capacity) {
		capacity *= 2;
		double** temp = new double* [capacity];
		for (int i = 0; i < capacity; i++) {
			temp[i] = new double[2]; // Allocate memory for temp
		}
		for (int i = 0; i < locationCount; i++) {
			temp[i][0] = locations[i][0];
			temp[i][1] = locations[i][1];
		}
		for (int i = 0; i < locationCount; i++) {
			delete[] locations[i];
		}
		delete[] locations; // free memory for the old array
		locations = temp;
	}
	locations[locationCount][0] = coordinate.getX_coordinate();
	locations[locationCount][1] = coordinate.getY_coordinate();
	locationCount++;
}

// Return the total distance travelled from the starting point to the end.
double LocationBook::totalDistanceTravelled() {
	double totalDistance = 0;
	for (int i = 1; i < locationCount; i++) {
		double dx = locations[i][0] - locations[i - 1][0];
		double dy = locations[i][1] - locations[i - 1][1];
		totalDistance += sqrt(dx * dx + dy * dy);
	}
	return totalDistance;
}

// Return the total distance from the start to a given point.
double LocationBook::viewDistanceToAGivenPoint(double x_coordinate, double y_coordinate) {
	int locationCountTracker = 0;
	for (int i = 0; i < locationCount; i++) {
		if (locations[i][0] == x_coordinate && locations[i][1] == y_coordinate) {
			break;
		}
		locationCountTracker++;
	}
	double totalDistance = 0;
	for (int i = 1; i <= locationCountTracker; i++) {
		double dx = locations[i][0] - locations[i - 1][0];
		double dy = locations[i][1] - locations[i - 1][1];
		totalDistance += sqrt(dx * dx + dy * dy);
	}
	return totalDistance;
}