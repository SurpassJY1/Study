#include<iostream>
#include<list>
#include<string>
using namespace std;
//将person按年龄进行升序排序，若是年龄相同则按身高进行降序排序
class Person
{
public:
	string m_Name;
	int m_Age;
	int m_Height;
	Person(string name, int age, int height) :m_Name(name), m_Age(age), m_Height(height) {}
};
bool personCompare(Person p1,Person p2)
{
	if (p1.m_Age<p2.m_Age)
	{
		return true;
	}
	else if (p1.m_Age==p2.m_Age) 
	{
		return p1.m_Height > p2.m_Height;
	}
	return false;
}
void test()
{
	Person p1("Jyz",21,178);
	Person p2("Zjy",21,182);
	Person p3("lb",35,175);
	Person p4("cc",45,180);
	Person p5("sc",40,170);
	Person p6("zy",25,190);
	Person p7("zf", 35,160);
	list<Person>l;
	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	l.push_back(p6);
	l.push_back(p7);
	for (list<Person>::iterator i = l.begin(); i !=l.end(); i++)
	{
		cout << (*i).m_Name << " " << (*i).m_Age << " " << (*i).m_Height << endl;
	}
	//操作自定义数据类型的时候要自己写规则
	l.sort(personCompare);
	cout << "------------------------------------------" << endl;
	for (list<Person>::iterator i = l.begin(); i != l.end(); i++)
	{
		cout << (*i).m_Name << " " << (*i).m_Age << " " << (*i).m_Height << endl;
	}
}

int main()
{
	test();
	system("pause");
	return 0;
}