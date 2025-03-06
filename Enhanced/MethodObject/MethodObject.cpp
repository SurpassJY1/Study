#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<functional>
using namespace std;


/*
函数对象(仿函数)：
	重载函数调用操作符的类，其对象称为函数对象
	函数对象使用重载的()时,行为类似函数调用,也叫仿函数
本质
函数对象(仿函数)是一个类,不是一个函数

特点
函数对象在使用时可以像普通函数那样调用，可以有参数，可以有返回值
函数对象超出普通函数的概念，函数对象可以有自己的状态
函数对象可以作为参数传递

内建函数对象
STL中内建了一些函数对象

分类：
算数仿函数
关系仿函数
逻辑仿函数

用法
这些仿函数所产生的对象，用法和一般函数完全相同
使用内建函数对象，需要引入头文件#include<functional>
*/

class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};
class MyPrint
{
public:
	void operator() (string str)
	{
		cout << str << endl;
		count++;
	}
	//内部状态
	int count;
	MyPrint()
	{
		this->count = 0;
	}
};
//1
void test01()
{
	MyAdd myAdd;
	cout << myAdd(10, 10) << endl;
}
//2
void test02()
{
	MyPrint mp;
	mp("Hello World");
	mp("Hello World");
	mp("Hello World");
	mp("Hello World");
	mp("Hello World");
	cout << mp.count << endl;
}

void doPrint(MyPrint& mp, string str)
{
	mp(str);
}

//函数对象可以作为参数进行传递
void test03()
{
	MyPrint mp;
	doPrint(mp, "Hello, c++");
}
//利用STL内建的算数函数对象
void test04()
{
	//negate 取反仿函数，一元
	negate<int> n;
	cout << n(50) << endl;
	//plus 二元仿函数 加法
	plus<int> p;
	cout << p(100, 100) << endl;
}
//内建函数对象关系仿函数
//大于greater<>
void test05()
{
	vector<int> v;
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(50);
	v.push_back(10);
	for (vector<int>::const_iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//利用STL提供的关系仿函数匿名来改变排序规则
	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::const_iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
}
//逻辑仿函数，用的比较少，了解即可
void test06()
{
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);
	for (vector<bool>::const_iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//利用transform函数来将v中转移到v2，并且取反
	vector<bool> v2;
	//在使用transform函数前要在目标容器中预留空间
	v2.resize(v.size());
	//被拷贝容器的起始迭代器和终止迭代器，目标容器起始迭代器，逻辑仿函数
	transform(v.begin(), v.end(), v2.begin(), logical_not<>());
	for (vector<bool>::const_iterator it = v2.begin();it != v2.end();it++)
	{
		cout << *it << " ";
	}
}
int main()
{
	test06();
	system("pause");
	return 0;
}