#include<iostream>
using namespace std;
template<class T1, class T2>
class Person;
//ȫ�ֺ�������ʵ��
template<class T1, class T2>
void show2(Person<T1, T2>& p)
{
	cout << p.m_Name << " " << p.m_Age << endl;
}
template<class T1, class T2>
class Person
{
	//ȫ�ֺ�������ʵ��
	//friend void show2(Person<T1,T2>&p);����ͨ���������������ǵ�����ʵ�ֵ�ȫ�ֺ�����һ������ģ��
	//��һ����ģ��Ĳ����б�
	//�����ȫ�ֺ�������ʵ�֣���Ҫ��ǰ�ñ�����֪�����ģ�����
	friend void show2<>(Person<T1,T2>&p);
	//ȫ�ֺ�������ʵ��
	//�����������棬��ǰ����� friend
	friend void show(Person<T1,T2>& p)
	{
		cout << "Name: " << p.m_Name << " Age: " << p.m_Age << endl;
	}
public:
	Person(T1 name, T2 age) :m_Name(name), m_Age(age) {}
private:
	T1 m_Name;
	T2 m_Age;
};

void test01()
{
	Person<int, int>p1(250, 20);
	show(p1);
}
void test02()
{
	Person<string, int>p1("Jyz",20);
	show2(p1);
}
int main()
{
	test01();
	return 0;
}