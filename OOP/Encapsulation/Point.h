#pragma once
#include <iostream>
using namespace std;
class Point
{
	private:
		int x;
		int y;
	public:
		Point(int x, int y) :x(x), y(y) {}
		Point() :x(0), y(0) {}
		void setX(int x);
		void setY(int y);
		int getX();
		int getY();
};

