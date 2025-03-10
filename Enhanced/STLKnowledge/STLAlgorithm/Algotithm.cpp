#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
算法主要由头文件<algorithm><functional><numeric>组成
algorithm是所有STL头文件最大的一个,范围涉及比较交换，查找，遍历操作，复制，修改等
numeric体积很小，只包括几个在序列上面进行简单数字运算的模板函数
functional定义了一些模板类，用于声明函数对象

查找元素
find
find_if按条件查找
adjacent_find查找相邻重复元素
binary_search二分查找
count统计元素个数
count_if按条件统计元素个数
*/
//常用的遍历算法中的for_each
void print01(int val)
{
	cout << val << " ";
}
class print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test01()
{
	vector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//传入两个迭代器包含的区间范围还有操作的函数名或者函数对象
	//普通函数名
	for_each(v.begin(), v.end(), print01);
	cout << endl;
	//传入匿名函数对象
	for_each(v.begin(), v.end(), print02());

}
//交换函数传入的函数对象
class trans
{
public:
	int operator()(int val)
	{
		return val;
	}
};
//transform
//搬运容器到另一个容器中,原容器中数据保留
//transform(iterator beg1,iterator end1,iterator beg2, func)
//beg1 原容器开始 end1 原容器结束 beg2目标容器开始 func是函数原型或者函数对象
void test02()
{
	vector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int> vTarget;
	//提前给目标容器开辟空间，不然会报错
	vTarget.resize(v.size());
	transform(v.begin(), v.end(), vTarget.begin(), trans());
	//for_each(v.begin(),v.end(),print02());
	cout << endl;
	for_each(vTarget.begin(), vTarget.end(), print02());
}
//find(iterator beg,iterator end, value)
//按值查找元素，找到返回该元素迭代器，没找到返回end迭代器
//查找内置数据类型
void test03()
{
	vector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//查找容器是否由5
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end())cout << "Not found" << endl;
	else cout << (*it) << endl;
}
//find找自定义数据类型
class Person
{
public:
	string name;
	int age;
	Person(string name, int age) :name(name), age(age) {}
};
bool operator==(const Person& p1, const Person& p2)
{
	return p1.age == p2.age;
}

class GreaterFive
{
public:
	bool operator()(int val1)
	{
		return val1 > 5;
	}
};

void test04()
{
	Person p1("zjy", 18);
	Person p2("yzl", 19);
	Person p3("wyk", 11);
	Person p4("zjc", 12);
	vector<Person> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	//用find函数找自定义数据类型要重载自定义数据类型==号因为find函数内部用==号比较
	vector<Person>::iterator it = find(v.begin(), v.end(), p1);
	if (it != v.end())cout << (*it).name << " Age: " << (*it).age << endl;
	else cout << "Not found" << endl;
}
//find_if(iterator beg,iterator end,_pred)
//按pred查找元素，找到则返回迭代器，找不到则返回end位置的迭代器
//_pred:函数或者谓词
//find_if查找内置数据类型
void test05()
{
	vector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//查找大于五的元素
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end())
	{
		cout << "Not found" << endl;
	}
	else
	{
		cout << "找到：" << *it << endl;
	}
}
//找自定义的数据类型
class FindPerson
{
public:
	bool operator()(Person& p)
	{
		return p.age > 20;
	}
};
void test06()
{
	Person p1("zjy", 21.2);
	Person p2("yzl", 19);
	Person p3("wyk", 11);
	Person p4("zjc", 12);
	vector<Person> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	//找年龄大于20的人
	vector<Person>::iterator it = find_if(v.begin(), v.end(), FindPerson());
	if (it == v.end())cout << "Not found" << endl;
	else cout << (*it).name << " Age: " << (*it).age << endl;
}
//adjacent_find(beg,end)
//查找相邻重复元素，返回相邻元素的第一个位置迭代器
//没找到返回end迭代器
void test07()
{
	vector<int>v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);
	v.push_back(3);
	v.push_back(0);
	v.push_back(4);
	v.push_back(1);
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end())cout << "Not found" << endl;
	else cout << *it << endl;
}
//binary_search
//bool binary_search(beg,end,value)
//在无序序列中不可用，返回true和false
//查找的元素必须为有序序列
void test08()
{
	vector<int> v;
	for (int i = 0;i < 10; i++)
	{
		v.push_back(i);
	}
	bool ret = binary_search(v.begin(), v.end(), 5);
	if (ret == true) { cout << "Found it" << endl; }
	else cout << "Not found" << endl;
}
//count(beg,end,value)
//返回元素出现次数
//统计内置数据类型
void test09()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(40);
	v.push_back(10);
	int num=count(v.begin(),v.end(),40);
	cout << "40 出现的次数为：" << num << endl;
}
//统计自定义数据类型
void test10() 
{
	vector<Person> v;
	Person p1("Zjy",20);
	Person p2("Zjy",10);
	Person p3("Zjy",10);
	Person p4("Zjy",10);
	Person p5("Zjy",40);
	Person p6("Wyk",40);
	Person p7("Jyz",40);
	Person p("Jyz",40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);
	v.push_back(p7);
	int num = count(v.begin(),v.end(),p);
	cout << num << endl;

}
//count_if(beg,end,_pred)
//统计符合谓词_pred的元素的个数
//count_if内置数据类型
void test11()
{
	vector<int>v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	int num = count_if(v.begin(),v.end(),GreaterFive());
	cout << num << endl;
}

//count_if统计自定义数据类型
void test12()
{
	Person p1("zjy", 21.2);
	Person p2("yzl", 19);
	Person p3("wyk", 11);
	Person p4("zjc", 12);
	vector<Person> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	int num = count_if(v.begin(),v.end(),FindPerson());
	cout << num << endl;
}
int main()
{
	test12();
	return 0;
}