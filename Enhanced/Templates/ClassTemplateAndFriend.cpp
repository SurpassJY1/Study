#include<iostream>
using namespace std;
template<class T1, class T2>
class Person;
//全局函数类外实现
template<class T1, class T2>
void show2(Person<T1, T2>& p)
{
	cout << p.m_Name << " " << p.m_Age << endl;
}
template<class T1, class T2>
class Person
{
	//全局函数类外实现
	//friend void show2(Person<T1,T2>&p);是普通函数声明，而我们的类外实现的全局函数是一个函数模板
	//加一个空模板的参数列表
	//如果是全局函数类外实现，需要提前让编译器知道这个模板存在
	friend void show2<>(Person<T1,T2>&p);
	//全局函数类内实现
	//放在类最上面，在前面加上 friend
	friend void show(Person<T1,T2>& p)
	{
		cout << "Name: " << p.m_Name << " Age: " << p.m_Age << endl;
	}
public:
	Person(T1 name, T2 age) :m_Name(name), m_Age(age) {}
private:
	T1 m_Name;
	T2 m_Age;
};

void test01()
{
	Person<int, int>p1(250, 20);
	show(p1);
}
void test02()
{
	Person<string, int>p1("Jyz",20);
	show2(p1);
}
int main()
{
	test01();
	return 0;
}