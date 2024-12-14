#include<iostream>
using namespace std;
/*
所有对象共享一份数据
在编译阶段分配内存
类内声明类外初始化
静态成员变相不属于某个对象，所有对象共享同一份数据
因此静态成员变量有两种访问方式：
类名和对象
静态成员变量也有访问权限：
私有成员类外访问不到

静态成员函数：
所有对象共享同一个函数
静态成员函数只能访问静态成员对象
静态成员函数也有自己的访问权限

成员变量和成员函数分开存储：
只有非静态成员变量属于类的对象上
*/
class EmptyClass {};
class NotEmpty {
	int a;//非静态成员变量，属于类的对象上
	static int s_a;//静态成员变量，不属于类的对象上
	void func() {}//非静态成员函数,不属于类的对象上
	static void func() {}//静态成员函数,不属于类的对象上
};
class Person
{
public:
	Person();
	~Person();
	static void staticFunc() {
		//静态成员函数能访问静态成员变量
		m_A = 100;
		//静态成员函数不能访问非静态成员变量，因为无法区分哪个对象的成员函数
		//m_B = 100;
		cout << "staticFunc used" << endl;
	}
private:
	static void staticFunc2() {
	}
	static int m_A;
	int m_B;
};

Person::Person()
{
}

Person::~Person()
{
}
//类外初始化
int Person::m_A = 10;

int main()
{//有权限
	//Person::staticFunc2();
	//空对象占用一个字节
	//C++编译器会给空对象分配一个字节空间，是为了区分空对象占内存的位置
	//每一个空对象也应该有一个独一无二的内存地址
	// 
	//
	cout << sizeof(EmptyClass) << endl;
	cout << sizeof(NotEmpty) << endl;
	return 0;
}