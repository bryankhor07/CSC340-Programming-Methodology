#include<iostream>
#include"Coordinate.h"
#include"LocationBook.h"
#include<cmath>
using namespace std;

int main() {

	Coordinate c1(2, 4);
	Coordinate c2(4, 6);
	Coordinate c3(6, 8);
	Coordinate c4(8, 10);
	Coordinate c5(10, 12);
	Coordinate c6(12, 14);

	LocationBook lb;

	lb.addLocation(c1);
	lb.addLocation(c2);
	lb.addLocation(c3);
	lb.addLocation(c4);
	lb.addLocation(c5);
	lb.addLocation(c6);

	cout << "The total distance you travelled is " << lb.totalDistanceTravelled() << endl;
	cout << "The total distance from the start to the second point is " << lb.viewDistanceToAGivenPoint(12, 14) << endl;

}