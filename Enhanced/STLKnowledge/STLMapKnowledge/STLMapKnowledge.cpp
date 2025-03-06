#include<iostream>
#include<map>
#include<string>
using namespace std;
/*
*map������Ԫ�ض���pair
* pair��һ��Ԫ��Ϊkey �ڶ���Ԫ�س�Ϊvalue
* ���е�Ԫ�ػ�����Ԫ�صļ�ֵ�Զ�����
* �����ǹ���ʽ�������ײ��Ƕ�����
* map�������ظ���keyֵ��multimap�����ظ���keyֵ
*
* ����
* map<T1,T2> mp;
* map(const map&mp);
*
* ��ֵ
* map& operator=(const map& map);
*
* �����ʹ�С
* size();
* empty();
* swap();
*
* �����ɾ��
* insert();
* clear();
* erase(pos);
* erase(beg,end);
* erase(key);
*
* ���Һ�ͳ��
* find(key);���Ҹ�key�Ƿ���ڣ������ڣ��򷵻ظļ���Ԫ�صĵ��������������ڣ��򷵻�end();
* count(key);ͳ��key�ĸ���������0��˵����0����1������multimap���ܴ���1

	map����������
	�÷º������Ըı��������
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
//���÷º������ı��������
class MyCompare
{
public:
	bool operator()(int v1, int v2)const
	{
		//�ı��������Ϊkeyֵ�ݼ�
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
	//��һ�ֲ���
	m.insert(pair<int, int>(1, 10));
	//�ڶ���
	m.insert(make_pair(2, 20));
	//������
	m.insert(map<int, int>::value_type(3, 30));
	//�����֣���������룬��������[]���ʵ�value
	//���������ʽ�������˻ᴴ��һ��valueΪ0�Ķ���
	m[4] = 40;
	printMap(m);

	//ɾ��
	m.erase(m.begin());//erase�����������
	printMap(m);
	m.erase(3);//����keyɾ��
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
	int count = m.count(3);//1,map�������ظ���key
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
//�ı��Զ����������͵��������
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