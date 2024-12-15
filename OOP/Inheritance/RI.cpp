#include<iostream>
using namespace std;
/*
conception:
两个派生类同时继承一个基类
又有某个类同时继承这两个派生类
菱形继承问题：
动物：羊 驼
羊，驼：羊驼
1。羊继承了动物的数据，驼同样继承了动物的数据，当草泥马使用数据的时候就会产生二义性
2。草泥马继承自动物的数据继承了两份
//解决方法：用virtual成为虚继承，共享一个数据，虚继承基类为虚基类
底层：不再是继承两个数据，而是继承两个指针，两个指针通过偏移量找到唯一的数据
*/
//Animal为虚基类
class Animal
{
public:
	int m_Age;
};
//加上virtual关键字
class Sheep : virtual public Animal
{

};
//加上virtual关键字
class Tuo :virtual public Animal
{
};
class SheepTuo : public Sheep,  public Tuo
{
};

void RITest()
{
	SheepTuo st;
	//两个父类数据同名要用作用域区分
	st.Sheep::m_Age = 50;
	st.Tuo::m_Age = 100;
	
	cout << "Sheep Age: " << st.Sheep::m_Age << endl;
	cout << "Tuo Age: " << st.Tuo::m_Age << endl;
	//不明确，继承了两个age st.m_Age = 50;
	//cout<< st.m_Age << endl;//输出100,只有一份age不会出现第二份
	cout << st.m_Age << endl;
}
int main()
{
	RITest();
	return 0;
}
