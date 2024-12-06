#pragma once
#include<iostream>
#include"Point.h"
using namespace std;
class Circle
{
private:
	Point center;
	double r;
public:
	Circle() :center(0, 0), r(0) {}
	Circle(Point center,double r=0) :center(), r(r) {}
	Circle(int x, int y, double r) :center(x, y), r(r) {}
	void setR(double r);
	double getR();
	void setCenter(Point center);
	void setCenter(int x,int y);
	Point getCenter();
};

