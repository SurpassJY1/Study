#include<iostream>
using namespace std;

//构造函数的分类及调用
//分类
//按参数分类： 无参构造和有参构造
//按类型分类： 普通构造和拷贝构造

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
//int main() {
//	//调用的方法：
//	//括号法:
//	//注意事项：调用默认无参构造的时候不要括号
//	//因为编译器会认为Person p1();是一个函数的声明
//	/*Person p1;
//	Person p2(10);
//	Person p3(p2);
//	cout<<"Age of p2 "<<p2.m_Age << endl;
//	cout<<"Age of p3 "<<p3.m_Age << endl;*/
//	//显示法
//	Person p1;
//	Person p2 = Person(10);
//	Person p3 = Person(p2);
//	
//	Person(10);//匿名对象，特点：当前执行结束时系统会立即回收
//	//注意：不要使用拷贝对象函数初始化匿名对象
//	//系统会认为Person(p2)为Person p2
//
//	//隐式转化法
//	Person p4 = 10;
//	Person p5 = p4;
//
//}