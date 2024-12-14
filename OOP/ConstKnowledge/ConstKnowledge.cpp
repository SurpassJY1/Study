#include<iostream>
using namespace std;
class Person {

public:
	//常函数
	//在成员函数后面加const修饰的是this，让this指针不可以修改指针指向对象的值
	 void showPerson() const
	{
		//m_A=100;相当于this—>m_A = 100;
		// this指针的本质是指针常量，指针常量的指向是不能修改的，
		// 但是this指针指向对象的值是可以修改的
		// 常函数this指向的值也不可以修改,
		// 相当于Person* const this到const Person* const this
		 //表达式必须为可修改的左值
		 m_B = 100;
	}
	 void func() {}
	int m_A;
	mutable int m_B;//特殊变量，常函数中也可以修改这个值
};

void test1() {
	Person p;
	
	p.showPerson();
	cout << p.m_B << endl;
}
void test2() {
//常对象
	const Person p;
	//p.m_A = 100;常对象不可以修改成员变量
	p.m_B = 200;//常对象可以修改mutable修饰的成员变量
	//p.func();//常对象只能调用常函数，因为普通的成员函数可以修改属性
	p.showPerson();
}
int main() {
	test1();
	return 0;
}