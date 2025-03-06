#include<iostream>
#include<map>
#include<string>
using namespace std;
/*
*map的所有元素都是pair
* pair第一个元素为key 第二个元素称为value
* 所有的元素会随着元素的键值自动排序
* 本质是关联式容器，底层是二叉树
* map不允许重复的key值，multimap允许重复的key值
*
* 构造
* map<T1,T2> mp;
* map(const map&mp);
*
* 赋值
* map& operator=(const map& map);
*
* 交换和大小
* size();
* empty();
* swap();
*
* 插入和删除
* insert();
* clear();
* erase(pos);
* erase(beg,end);
* erase(key);
*
* 查找合统计
* find(key);查找该key是否存在，若存在，则返回改键的元素的迭代器，若不存在，则返回end();
* count(key);统计key的个数，对于0来说就是0或者1，对于multimap可能大于1

	map容器的排序
	用仿函数可以改变排序规则
*/
class Person
{
public:
	int m_Age;
	string m_Name;
	Person(string name, int age) :m_Name(name), m_Age(age) {}
};
class PersonCompare
{
public:
	bool operator()(Person p1, Person p2)const
	{
		return p1.m_Age < p2.m_Age;
	}
};
//利用仿函数来改变排序规则
class MyCompare
{
public:
	bool operator()(int v1, int v2)const
	{
		//改变排序规则为key值递减
		return v1 > v2;
	}
};

void printMap(map<int, int>& mp)
{
	for (map<int, int>::const_iterator it = mp.begin();it != mp.end(); it++)
	{
		cout << "Key: " << (*it).first << " Value " << (*it).second << endl;
	}
	cout << endl;
}

void test01()
{
	map<int, int> mp;
	mp.insert(pair<int, int>(1, 10));
	mp.insert(pair<int, int>(2, 20));
	mp.insert(pair<int, int>(3, 30));
	mp.insert(pair<int, int>(4, 40));
	mp.insert(pair<int, int>(5, 50));
	mp.insert(pair<int, int>(6, 60));
	map<int, int> m2(mp);
	map<int, int> m3 = mp;
	printMap(m3);
}

void test02()
{
	map<int, int> m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));
	m1.insert(pair<int, int>(5, 50));
	m1.insert(pair<int, int>(6, 60));
	if (!m1.empty())
	{
		cout << "m1 is not empty" << endl;
		cout << "The size of m1 is " << m1.size() << endl;
		printMap(m1);
	}
	map<int, int> m2;
	m2.insert(pair<int, int>(9, 90));
	m1.swap(m2);
	printMap(m1);
}

void test03()
{
	map<int, int> m;
	//第一种插入
	m.insert(pair<int, int>(1, 10));
	//第二种
	m.insert(make_pair(2, 20));
	//第三种
	m.insert(map<int, int>::value_type(3, 30));
	//第四种，不建议插入，可以利用[]访问到value
	//按照这个方式插入插错了会创造一个value为0的队组
	m[4] = 40;
	printMap(m);

	//删除
	m.erase(m.begin());//erase里面填迭代器
	printMap(m);
	m.erase(3);//按照key删除
	printMap(m);
	m.erase(m.begin(), m.end());
	m.clear();
}
void test04()
{
	map<int, int>m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(3, 40));
	map<int, int>::iterator it = m.find(3);
	if (it != m.end())
	{
		cout << "Founded" << endl;
		cout << (*it).first << " " << (*it).second << endl;
	}
	else {
		cout << "Not found" << endl;
	}
	int count = m.count(3);//1,map不允许重复的key
	cout << "num= " << count << endl;
}
void test05()
{
	map<int, int, MyCompare> m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));
	for (map<int, int, MyCompare>::const_iterator it = m.begin();it != m.end();it++)
	{
		cout << (*it).first << " " << (*it).second << endl;
	}

}
//改变自定义数据类型的排序规则
void test06()
{
	map< Person, int, PersonCompare> m;
	Person p1("Hsy", 18);
	Person p2("Zjy", 19);
	Person p3("Jyz", 21);
	Person p4("Cd", 29);
	m.insert(make_pair(p1, 70));
	m.insert(make_pair(p2, 100));
	m.insert(make_pair(p3, 80));
	m.insert(make_pair(p4, 50));
	for (map<Person, int, PersonCompare>::const_iterator it = m.begin();it != m.end();it++)
	{
		cout << "Name: " << (*it).first.m_Name << " Age: " << (*it).first.m_Age << " Grade: " << (*it).second << endl;
	}
}
int main()
{
	test06();
	system("pause");
	return 0;
}