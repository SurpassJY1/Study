#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void myPrint(int val)
{
	cout << val << endl;
}

void test01()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	//通过迭代器访问容器中的数据
	//起始迭代器
	vector<int>::iterator itBegin = v.begin();//指向容器中的第一个元素
	vector<int>::iterator itEnd = v.end();//结束迭代器，指向容器最后一个元素的下一个位置
	//第一种遍历方式
	while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}
	//第二种遍历方式
	for (vector<int>::iterator itBegin = v.begin(); itBegin != v.end(); itBegin++)
	{
		cout << *itBegin << endl;
	}
	//第三种遍历方法用STL当中的
	for_each(v.begin(), v.end(), myPrint);
}
//Vector 存放自定义数据类型
class Person
{
public:
	int m_Age;
	string m_Name;
	Person(int age, string name) :m_Age(age), m_Name(name) {}
};

ostream& operator<<(ostream& out, Person& p)
{
	cout << "Age: " << p.m_Age << " Name" << p.m_Name ;
	return cout;
}

void test02()
{
	Person p1(15, "zjy");
	Person p2(16, "zjy");
	Person p3(17, "zjy");
	Person p4(18, "zjy");
	Person p5(19, "zjy");
	vector<Person> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	for (vector<Person>::iterator itBegin = v.begin();itBegin != v.end();itBegin++)
	{
		cout << *itBegin << endl;
	}
}
//存放自定义数据类型的指针
void test03()
{
	Person p1(15, "zjy");
	Person p2(16, "zjy");
	Person p3(17, "zjy");
	Person p4(18, "zjy");
	Person p5(19, "zjy");
	vector<Person*> v;
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	for (vector<Person*>::iterator it=v.begin();it!=v.end();it++)
	{
		cout << (*it)->m_Age << (*it)->m_Name << endl;
	}
}
//Vector嵌套Vector容器
void test04()
{
	vector<vector<int>> v;
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;
	vector<int>v5;
	for (int i = 0;i<7;i++) 
	{
		v1.push_back(i);
		v2.push_back(i+1);
		v3.push_back(i+2);
		v4.push_back(i+3);
		v5.push_back(i+4);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);
	for (vector<vector<int>>::iterator it=v.begin();it!=v.end();it++)
	{
		//(*it)是一个容器，要把这个再遍历一边
		for (vector<int>::iterator vit = (*it).begin();vit != (*it).end();vit++) 
		{
			cout << *vit << endl;
		}
	}
}
int main()
{
	test04();
	return 0;
}