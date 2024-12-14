#include<iostream>
using namespace std;

class Person {

public:
	Person() {
		cout << "无参构造" << endl;
	}
	Person(int age) {
		this->m_Age = age;
		cout << "有参构造" << endl;
	}

	//拷贝构造函数的调用时机
	//1.使用一个已经创建完毕的对象来初始化一个新对象
	//2.以值传递的方式给函数传值
	//3.以值方式返回局部对象
	Person(const Person& p) {
		m_Age = p.m_Age;
		cout << "拷贝构造" << endl;
	}
	int m_Age;
	~Person() {
		cout << "析构函数" << endl;
	}
};
void test(Person p) {
}
Person test2() {
	Person p;
	return p;
}
void test3() {
	Person p=test2();
}
//int main()
//{
//	//拷贝构造函数的调用时机
//	//1.使用一个已经创建完毕的对象来初始化一个新对象
//	Person p1 = 10;
//	Person p2 = p1;
//	cout << "--------------------------" << endl;
//	//2.以值传递的方式给函数传值
//	test(p1);
//	cout << "--------------------------" << endl;
//	//3.以值方式返回局部对象
//	test3();
//	cout << "--------------------------" << endl;
//	return 0;
//}