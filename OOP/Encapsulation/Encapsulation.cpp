#include<iostream>
#include"math.h"
#include"Point.h"
#include"Circle.h"
#define PI 3.14
using namespace std;

/*
struct和class的区别：
stuct的默认权限是public
class的默认权限是private
封装的三种访问权限
公共public			类内类外都可以访问
保护protected		类内可以访问，类外不可以访问，子类可以访问父类的保护内容
私有private			类内可以访问，类外不可以访问，子类不可以访问父类的私有内容
*/
class Student {
private:
	string name;
	string stuNum;
public:
	Student() :name(""), stuNum("") {};
	Student(string name, string stuNum) :name(name), stuNum(stuNum) {}
	string setName(string name) {
		this->name = name;
		return name;
	}
	string setStuNum(string stuNum)
	{
		this->stuNum = stuNum;
		return stuNum;
	}
	string getName() {
		return this->name;
	}
	string getStuNum()
	{
		return this->stuNum;
	}
};

class MyCircule
{private:
	double r;
	Point point;
public:
	MyCircule(double r) :r(r) {};
	double getRound() {
		return 2 * PI * r;
	}
};
//class Point 
//{
//private:
//	int x;
//	int y;
//public:
//	Point(int x, int y) :x(x), y(y) {}
//	Point() :x(0), y(0) {}
//	
//};

void checkIfPointOnCircle(Point point,Circle circle) {
	Point center = circle.getCenter();
	int c_x = center.getX();
	int c_y = center.getY();
	int x = point.getX();
	int y = point.getY();
	double x_Dist = pow(x-c_x,2);
	double y_Dist = pow(y-c_y,2);
	double r_2 = pow(circle.getR(), 2);
	if(x_Dist + y_Dist - r_2>0) {
		cout << "Point is outside of the circle" << endl;
	}
	else if(x_Dist + y_Dist - r_2 == 0)
	{
		cout << "Point is on the circle" << endl;
	}
	else
	{
		cout << "Point is inside the circle" << endl;
	}
}
int main()
{
	Point point(1,0);//in the circle
	Circle circle(0,0, 1);
	Point point2(2, 0);//outside the circle
	Point point3(0, 0);//inside the circle
	checkIfPointOnCircle(point,circle);
	checkIfPointOnCircle(point2,circle);
	checkIfPointOnCircle(point3,circle);
	return 0;
}


