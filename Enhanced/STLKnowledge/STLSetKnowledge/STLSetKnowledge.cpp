#include<set>
#include<iostream>
using namespace std;
/*
* set 和 multiset插入的时候默认排序，属于关联式容器,底层是二叉树
* set不允许重复的数multiset可以插入重复的数
* set插入数据的时候会返回插入结果判断是否插入成功
* multiset则不会，可以插入重复的数据
*
* 构造：
* set<T> s
* set(Const set& st)拷贝构造
*
* 大小和交换
* set容器不支持resize
* size();
* empty();
* swap(st);
*
* 插入和删除
* insert(elem);
* clear();
* erase(pos);迭代器pos所指向的元素，返回下一个元素的迭代器哎
* erase(beg,end);删除区间[beg,end)所有元素，返回下一个元素的迭代器
* erase(elem);删除容器值为elem的元素
*
* 查找与统计
* find(key); 查找key是否存在，若存在返回该元素的迭代器，若不存在则返回set.end()
* count(key); 统计key的元素个数
*
* set容器的排序
* set容器默认排序鬼子额为从小到大，掌握如何改变排序规则
* 利用仿函数改变排序规则
* 存在自定义数据类型的时候set设置排序规则
* 
* pair对组的创建
* 成对出现的数据，利用队组可以返回两个数据
* 两种创建方式
* pair<type,type> p(value1,value2);
* pair<type,type> p=make_pair(value1,value2);
*/
//*存在自定义数据类型的时候set设置排序规则

class Person
{
public:
	string m_Name;
	int m_Age;
	Person(string name, int age) :m_Name(name), m_Age(age) {}
};
//按照年龄降序
class PersonCompare 
{
public:
	bool operator() (Person p1, Person p2) const
	{
		return p1.m_Age < p2.m_Age;
	}
};
//利用仿函数修改排序规则
class MyCompare
{
	//重载小括号
public:
	bool operator()(int v1,int v2)const
	{
		return v1 > v2;
	}
};
void showSet(const set<int>& s)
{
	for (set<int>::const_iterator it = s.begin();it != s.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	set<int> s1;
	s1.insert(2);
	s1.insert(2);
	s1.insert(1);
	s1.insert(9);
	set<int> s2(s1);
	set<int> s3 = s1;
	showSet(s3);
}
void test02()
{
	set<int> s1;
	if (s1.empty())cout << "s1 is empty now" << endl;
	s1.insert(1);
	s1.insert(1);
	s1.insert(3);
	s1.insert(2);
	s1.insert(18);
	cout << s1.size() << endl;
	set<int> s2;
	s2.insert(10);
	s2.insert(20);
	s2.insert(30);
	s2.insert(40);
	s1.swap(s2);
	showSet(s1);
}
void test03()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	showSet(s1);
	//erase
	cout << "---------------------------" << endl;
	s1.erase(++s1.begin());
	s1.erase(++s1.begin(), --s1.end());
	showSet(s1);
	s1.clear();
}

void test04()
{
	set<int> s1;
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.insert(4);
	s1.insert(5);
	set<int>::const_iterator it = s1.find(6);
	if (it != s1.end())cout << *it << endl;
	//对于set而言统计的结果要么是0要么是1
	cout << s1.count(3) << endl;
	cout << s1.count(6) << endl;
}
void test05()
{
	set<int> s;
	//set的insert返回队组，队组第二个表示插入成功与否
	pair<set<int>::iterator, bool> ret = s.insert(10);
	if (ret.second)
	{
		cout << "第一次插入成功" << endl;
	}
	else cout << "插入失败" << endl;
	pair<set<int>::iterator, bool> ret2 = s.insert(10);
	if (ret2.second)
	{
		cout << "第二次插入成功" << endl;
	}
	else cout << "插入失败" << endl;
	showSet(s);
	cout << "--------------------" << endl;
	multiset<int> ms;
	//multiset的insert返回迭代器，不会判断插入成功或者失败
	ms.insert(10);
	ms.insert(10);
	for (multiset<int>::const_iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << endl;
	}
}
void test06()
{
	//对组的创建
	pair<string, int> p("Tom", 20);
	cout << p.first << " " << p.second << endl;
	//第二种方式
	pair<string, int> p2 = make_pair("Jerry", 30);
	cout << p2.first << " " << p.second << endl;
}
void test07()
{
	//对于自定义数据类型通常会指定排序规则，不然不知道插入后怎么排序
	set<int> s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	s1.insert(50);
	showSet(s1);
	//指定排序规则为从大到小
	set<int, MyCompare> s2;
	s2.insert(10);
	s2.insert(20);
	s2.insert(30);
	s2.insert(40);
	s2.insert(50);
	s2.insert(60);
	for (set<int,MyCompare>::const_iterator it=s2.begin();it!=s2.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test08()
{
	Person p1("Zjy",18);
	Person p2("Jyz",18);
	Person p3("Cd",17);
	Person p4("Hsy",6);
	set<Person,PersonCompare> s;
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	for (set<Person,PersonCompare>::const_iterator it=s.begin();it!=s.end();it++)
	{
		cout << (*it).m_Name << " " << "Age: " << (*it).m_Age << endl;
	}
}
int main()
{
	test08();
	system("pause");
	return 0;
}