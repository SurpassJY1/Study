#pragma once
#ifndef FILECLASSTEMPLATE_H
#define FILECLASSTEMPLATE_H
#include<iostream>
using namespace std;
//类模板分文件编写
//问题：
//类模板的成员创建时机是在调用阶段，导致分文件编写的时候链接不到
//解决方式：将函数声明和实现写到同一份文件当中，并更改后缀名为hpp
//解决方式2：直接包含cpp源文件
template<class T1,class T2>
class Person 
{
public:
	T1 m_Name;
	T2 m_Age;
	Person(T1 name, T2 age);
	void show();
};
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) 
{
	this->m_Age = age;
	this->m_Name = name;
}
template<class T1, class T2>
void Person<T1, T2>::show() 
{
	cout << "Name: " << this->m_Name << " Age:" << this->m_Age << endl;
}

#endif