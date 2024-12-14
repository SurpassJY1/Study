#include<iostream>
#include<string>
using namespace std;
//先告诉编译器我们会创建building,如果没有这行会在GoodGuy02创建building报错
class Building;
/*
有些私有的属性也想类外的一些函数或者类进行访问就要用到友元的技术
友元的三种实现：
1.全局函数做友元
2.类做友元
3.成员函数做友元
注意，成员函数做友元要先展示完全定义
*/
class GoodGuy02
{
private:
	Building* building;
public:
	GoodGuy02();
	//可以访问building中的私有成员
	void visit();
	//不可以访问building中的私有成员
	void visit02();
};


//建筑物类
class Building {
	
	//goodGuy全局函数是Building的好朋友,可以访问building中的私有成员
	friend void goodGuy(Building& building);
	//GoodGuy类是Building的好朋友,可以访问building中的私有成员
	friend class GoodGuy;
	//GoodGuy02类的成员函数是友元,可以访问Building中的私有成员
	friend void GoodGuy02::visit();

private:
	string m_Bedroom;
public:
	string m_SittingRoom;
	Building() {
		m_Bedroom = "卧室";
		m_SittingRoom = "客厅";
	}

};

GoodGuy02::GoodGuy02() {
	building = new Building;
}

void GoodGuy02::visit() {
	cout << "好基友02的成员函数visit正在访问：" << building->m_SittingRoom << endl;
	cout << "好基友02的成员函数visit正在访问：" << building->m_Bedroom << endl;
}

void GoodGuy02::visit02()
{
	cout << "好基友02的成员函数visit正在访问：" << building->m_SittingRoom << endl;
}
//类做友元
class GoodGuy {
	Building* building;
public:
	GoodGuy();
	void visit();//参观函数,访问building中的属性


};
GoodGuy::GoodGuy() {
	building = new Building;
}

void GoodGuy::visit() {
	cout << "正在访问building的" << building->m_SittingRoom << endl;
	cout << "正在访问building的" << building->m_Bedroom << endl;
}

//全局函数做为友元
void goodGuy(Building& building)
{
	cout << "好基友的全局函数正在访问：" << building.m_SittingRoom << endl;
	cout << "好基友的全局函数正在访问：" << building.m_Bedroom << endl;
}

//成员函数做友元



void test01() {
	Building building;
	goodGuy(building);
}
void test02() {
	GoodGuy gd;
	gd.visit();
}
void test03() {
	GoodGuy02 gd2;
	gd2.visit();
	gd2.visit02();
}
int main()
{
	test03();
	return 0;
}