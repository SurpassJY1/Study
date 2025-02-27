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
	//ͨ�����������������е�����
	//��ʼ������
	vector<int>::iterator itBegin = v.begin();//ָ�������еĵ�һ��Ԫ��
	vector<int>::iterator itEnd = v.end();//������������ָ���������һ��Ԫ�ص���һ��λ��
	//��һ�ֱ�����ʽ
	while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}
	//�ڶ��ֱ�����ʽ
	for (vector<int>::iterator itBegin = v.begin(); itBegin != v.end(); itBegin++)
	{
		cout << *itBegin << endl;
	}
	//�����ֱ���������STL���е�
	for_each(v.begin(), v.end(), myPrint);
}
//Vector ����Զ�����������
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
//����Զ����������͵�ָ��
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
//VectorǶ��Vector����
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
		//(*it)��һ��������Ҫ������ٱ���һ��
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