#include "Point.h"
#include<iostream>
using namespace std;

int Point::getX() {
	return x;
}
int Point::getY() {
	return y;
}
void Point::setX(int x) {
	this->x = x;
}
void Point::setY(int y) {
	this->y = y;
}