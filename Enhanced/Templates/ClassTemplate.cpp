#include<iostream>
using namespace std;
/*
��ģ������ã�
����һ��ͨ���࣬���еĳ�Ա�������Ϳ��Բ�����ָ������һ�����������������
�﷨��
	template<class T>
	��
��ģ��ͺ���ģ�������;
	1.��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
	2.��ģ����ģ������б��п�����Ĭ�ϲ���

��ģ���г�Ա��������ʱ����
	1.��ͨ���г�Ա����һ��ʼ�Ϳ��Դ���.
	2.��ģ���Ա�����ڵ���ʱ�Ŵ���

	��ģ���Ա��������ʵ��
	1.

��ģ�����������������
	���ִ��ݷ�ʽ��
		//1.ָ����������--ֱ����ʾ�������������
		//2.����ģ�廯----�������еĲ�����Ϊģ����д���
		//3.������ģ�廯--�������������ģ�廯���д���
*/
//2.��ģ����ģ������б��п�����Ĭ�ϲ���
template<class NameType=string,class AgeType=int>
class Person
{
	NameType m_Name;
	AgeType m_Age;
public:
	//����ʵ��
	/*Person(NameType name, AgeType age) :m_Name(name), m_Age(age) {}*/
	//����ʵ��
	/*void show()
	{
		cout << "Age: " << this->m_Age << " Name: " << this->m_Name << endl;
	}*/
	//����ʵ��
	Person(NameType name, AgeType age);
	void show();
};
template<class NameType,class AgeType>
Person<NameType,AgeType>::Person(NameType name,AgeType age) {
	m_Name = name;
	m_Age = age;
}
template<class NameType, class AgeType>
void Person<NameType,AgeType>::show() 
{
	cout << "Age: " << this->m_Age << " Name: " << this->m_Name << endl;
}
void test()
{
	//1.��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
	//Person p1("Jyz", 20);
	
	//ֻ���ü�������ʾָ������
	Person<string, int>p1("Jyz",20);
	//ģ������б�����Ĭ�ϲ����ˣ����Բ���д����
	Person <>p2("Zjt", 20);
	p1.show();
	p2.show();
}
/*
��ģ���г�Ա��������ʱ����
1.��ͨ���г�Ա����һ��ʼ�Ϳ��Դ���.
2.��ģ���Ա�����ڵ���ʱ�Ŵ���
*/
class Person1 
{
public:
	void showPerson1()
	{
		cout << "Show Person1" << endl;
	}
};
class Person2
{
public:
	void showPerson2()
	{
		cout << "Show Person2" << endl;
	}
};
template<class T>
class MyClass 
{
public:
	T obj;
	void func1() 
	{
		obj.showPerson1();//����ͨ����˵����ģ������Ա������ʱ���ָ������
	}
	void func2() 
	{
		obj.showPerson2();
	}
};
//1.ָ����������--ֱ����ʾ�������������
void func1(Person <string, int>& p1)
{
	p1.show();
}
//2.����ģ�廯----�������еĲ�����Ϊģ����д���
template<class T1,class T2>
void func2(Person <T1, T2>p1) 
{
	p1.show();
}
//3.������ģ�廯--�������������ģ�廯���д���
template<class T>
void func3(T &p) 
{
	p.show();
}
void test02() 
{
	Person <> p1("Jyz", 20);
	func3(p1);
}
int main()
{
	test02();
	return 0;
}