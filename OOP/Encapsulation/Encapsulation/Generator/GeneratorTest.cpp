#include<iostream>
using namespace std;

class Person
{
	/*
	1.构造函数没有返回值
	2.构造函数没有参数
    3.构造函数名字与类名相同
	4.构造函数可以有参数，可以重载
	5.创建对象的时候构造函数会自动调用，并且只会调用一次
	*/
public:
	Person() {
	cout<< "Person()" << endl;
	}
	/*
	析构函数
	没有返回值不写void
	函数名和类名相同在前面加～
	没有参数不发生重载
	*/
    ~Person() {
	cout<< "~Person()" << endl;
	}
};
//int main()
//{
//	Person p;
//	return 0;
//}