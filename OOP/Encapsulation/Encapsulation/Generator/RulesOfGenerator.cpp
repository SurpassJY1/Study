#include<iostream>
using namespace std;

/*
写一个类cpp会至少添加三个函数
默认构造（空实现）
析构函数（空实现）
拷贝构造（值拷贝）
如果我们写了构造函数就提供默认析构函数和拷贝构造函数
*/
class Person {

public:
	Person() {
		cout << "无参构造" << endl;
	}
	Person(int age) {
		this->m_Age = age;
		cout << "有参构造" << endl;
	}
	Person(const Person& p) {
		m_Age = p.m_Age;
		cout << "拷贝构造" << endl;
	}
	int m_Age;
	~Person() {
		cout << "析构函数" << endl;
	}
};
