#include "Circle.h"
#include<iostream>
using namespace std;
void Circle::setR(double r) {
	this->r = r;
}
double Circle::getR() {
	return this->r;
}
void Circle::setCenter(Point center) {
	this->center = center;
}
void Circle::setCenter(int x, int y) {
	Point center(x, y);
	this->center = center;
}
Point Circle::getCenter() {
	return this->center;
}
