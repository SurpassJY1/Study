#include<set>
#include<iostream>
using namespace std;
/*
* set �� multiset�����ʱ��Ĭ���������ڹ���ʽ����,�ײ��Ƕ�����
* set�������ظ�����multiset���Բ����ظ�����
* set�������ݵ�ʱ��᷵�ز������ж��Ƿ����ɹ�
* multiset�򲻻ᣬ���Բ����ظ�������
*
* ���죺
* set<T> s
* set(Const set& st)��������
*
* ��С�ͽ���
* set������֧��resize
* size();
* empty();
* swap(st);
*
* �����ɾ��
* insert(elem);
* clear();
* erase(pos);������pos��ָ���Ԫ�أ�������һ��Ԫ�صĵ�������
* erase(beg,end);ɾ������[beg,end)����Ԫ�أ�������һ��Ԫ�صĵ�����
* erase(elem);ɾ������ֵΪelem��Ԫ��
*
* ������ͳ��
* find(key); ����key�Ƿ���ڣ������ڷ��ظ�Ԫ�صĵ����������������򷵻�set.end()
* count(key); ͳ��key��Ԫ�ظ���
*
* set����������
* set����Ĭ��������Ӷ�Ϊ��С����������θı��������
* ���÷º����ı��������
* �����Զ����������͵�ʱ��set�����������
* 
* pair����Ĵ���
* �ɶԳ��ֵ����ݣ����ö�����Է�����������
* ���ִ�����ʽ
* pair<type,type> p(value1,value2);
* pair<type,type> p=make_pair(value1,value2);
*/
//*�����Զ����������͵�ʱ��set�����������

class Person
{
public:
	string m_Name;
	int m_Age;
	Person(string name, int age) :m_Name(name), m_Age(age) {}
};
//�������併��
class PersonCompare 
{
public:
	bool operator() (Person p1, Person p2) const
	{
		return p1.m_Age < p2.m_Age;
	}
};
//���÷º����޸��������
class MyCompare
{
	//����С����
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
	//����set����ͳ�ƵĽ��Ҫô��0Ҫô��1
	cout << s1.count(3) << endl;
	cout << s1.count(6) << endl;
}
void test05()
{
	set<int> s;
	//set��insert���ض��飬����ڶ�����ʾ����ɹ����
	pair<set<int>::iterator, bool> ret = s.insert(10);
	if (ret.second)
	{
		cout << "��һ�β���ɹ�" << endl;
	}
	else cout << "����ʧ��" << endl;
	pair<set<int>::iterator, bool> ret2 = s.insert(10);
	if (ret2.second)
	{
		cout << "�ڶ��β���ɹ�" << endl;
	}
	else cout << "����ʧ��" << endl;
	showSet(s);
	cout << "--------------------" << endl;
	multiset<int> ms;
	//multiset��insert���ص������������жϲ���ɹ�����ʧ��
	ms.insert(10);
	ms.insert(10);
	for (multiset<int>::const_iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << endl;
	}
}
void test06()
{
	//����Ĵ���
	pair<string, int> p("Tom", 20);
	cout << p.first << " " << p.second << endl;
	//�ڶ��ַ�ʽ
	pair<string, int> p2 = make_pair("Jerry", 30);
	cout << p2.first << " " << p.second << endl;
}
void test07()
{
	//�����Զ�����������ͨ����ָ��������򣬲�Ȼ��֪���������ô����
	set<int> s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	s1.insert(50);
	showSet(s1);
	//ָ���������Ϊ�Ӵ�С
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