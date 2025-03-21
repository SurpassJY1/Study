#include<iostream>
using namespace std;
/*
类模板的作用：
建立一个通用类，类中的成员数据类型可以不具体指定，用一个虚拟的类型来代表
语法：
	template<class T>
	类
类模板和函数模板的区别;
	1.类模板没有自动类型推导的使用方式
	2.类模板在模板参数列表中可以有默认参数

类模板中成员函数创建时机：
	1.普通类中成员函数一开始就可以创建.
	2.类模板成员函数在调用时才创建

	类模板成员函数类外实现
	1.

类模板对象做函数参数：
	三种传递方式：
		//1.指定传入类型--直接显示对象的数据类型
		//2.参数模板化----将对象中的参数变为模板进行传递
		//3.整个类模板化--将这个对象类型模板化进行传递
*/
//2.类模板在模板参数列表中可以有默认参数
template<class NameType=string,class AgeType=int>
class Person
{
	NameType m_Name;
	AgeType m_Age;
public:
	//类内实现
	/*Person(NameType name, AgeType age) :m_Name(name), m_Age(age) {}*/
	//类内实现
	/*void show()
	{
		cout << "Age: " << this->m_Age << " Name: " << this->m_Name << endl;
	}*/
	//类外实现
	Person(NameType name, AgeType age);
	void show();
};
template<class NameType,class AgeType>
Person<NameType,AgeType>::Person(NameType name,AgeType age) {
	m_Name = name;
	m_Age = age;
}
template<class NameType, class AgeType>
void Person<NameType,AgeType>::show() 
{
	cout << "Age: " << this->m_Age << " Name: " << this->m_Name << endl;
}
void test()
{
	//1.类模板没有自动类型推导的使用方式
	//Person p1("Jyz", 20);
	
	//只能用尖括号显示指定类型
	Person<string, int>p1("Jyz",20);
	//模板参数列表中有默认参数了，所以不用写出来
	Person <>p2("Zjt", 20);
	p1.show();
	p2.show();
}
/*
类模板中成员函数创建时机：
1.普通类中成员函数一开始就可以创建.
2.类模板成员函数在调用时才创建
*/
class Person1 
{
public:
	void showPerson1()
	{
		cout << "Show Person1" << endl;
	}
};
class Person2
{
public:
	void showPerson2()
	{
		cout << "Show Person2" << endl;
	}
};
template<class T>
class MyClass 
{
public:
	T obj;
	void func1() 
	{
		obj.showPerson1();//编译通过，说明类模板的类成员创建的时候才指定类型
	}
	void func2() 
	{
		obj.showPerson2();
	}
};
//1.指定传入类型--直接显示对象的数据类型
void func1(Person <string, int>& p1)
{
	p1.show();
}
//2.参数模板化----将对象中的参数变为模板进行传递
template<class T1,class T2>
void func2(Person <T1, T2>p1) 
{
	p1.show();
}
//3.整个类模板化--将这个对象类型模板化进行传递
template<class T>
void func3(T &p) 
{
	p.show();
}
void test02() 
{
	Person <> p1("Jyz", 20);
	func3(p1);
}
int main()
{
	test02();
	return 0;
}