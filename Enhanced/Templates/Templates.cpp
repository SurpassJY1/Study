#include<iostream>
using namespace std;
//����ģ��
/*
template<typename T>
template ��������ģ��
typename��������������һ���������ͣ�������class����
T ͨ�õ��������ͣ����ֿ����滻��ͨ��Ϊ��д

��ͨ�����ͺ���ģ���ȥ�£�
��ͨ��������ʱ���Է�����ʽ����ת��
����ģ�壺
�Զ������Ƶ������ᷢ����ʽ����ת��
��ʾָ�����ͣ����Է�����ʽ����ת��
����ʹ����ʾָ�����͵ķ�ʽ
ע�����
�Զ������Ƶ�������Ҫ�Ƶ���һ�µ���������T�ſ���ʹ��
			  ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��

ģ������ԣ�
ģ�岢�������ܵģ���Щָ���������ͣ���Ҫ�þ��廯��ʽ��ʵ��,�紫���������=����
�����Զ�����������
*/
template<typename T>//����һ��ģ��
void mySwap(T&a,T&b) 
{
	T temp = a;
	a = b;
	b = temp;
}

void test()
{
	int a = 10;
	int b= 20;
	double c= 0.1;
	double d = 0.2;
	//ʹ��ģ��
	//��һ�֣��Զ������Ƶ�
	mySwap(a,b);
	mySwap(c, d);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;
	cout << "d: " << d << endl;
	//�ڶ��֣���ʾָ������
	mySwap<int>(a, b);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
}
void test02()
{
	int a = 10;
	char c = 'c';
	//mySwap(a, c);//�����Զ������Ƶ������Ƶ���һ�µ���������
}

template<typename T>
//ģ�����Ҫȷ����T���������Ͳſ���ʹ��
void func()
{
	cout << "func called" << endl;
}
void test03()
{
	//func();���󣬱���ָ����T����������
	func<int>();
}
int myAdd01(int a,int b) 
{
	return a + b;

}
template <class T>
T myAdd02(T a,T b) 
{
	return a + b;
}
void test04()
{
	int a = 10;
	char b = 'a';
	//cout<<myAdd(a, b);//���ᷢ����ʽ����ת��,�޷��Ƶ���һ�µ���������
	cout << myAdd01(a, b);//������ʽ����ת��107
	cout << "-------------------" << endl;
	cout<<myAdd02<int>(a, b);//��ʽָ������,���107
}
//ģ�岢�������ܵģ���Щָ���������ͣ���Ҫ�þ��廯��ʽ��ʵ��, �紫��������� = ����
template<class T>
bool myCompare(T&a,T&b) 
{
	return a == b? true:false;
}
//�����Զ�����������
class Person 
{
public:
	string m_Name;
	int m_Age;
	Person(string name, int age) :m_Name(name), m_Age(age) {}
	/*bool operator==(Person& p2) 
	{
		if (this->m_Name == p2.m_Name && this->m_Age == p2.m_Age)return true;
		return false;
	}*/
};
void test05() 
{
	int a = 10;
	int b = 10;
	bool ret= myCompare(a, b);
	if (ret)
	{
		cout << "a==b" << endl;
	}
	else 
	{
		cout << "a!=b" << endl;
	}
}
//�������2�����þ��廯Person�İ汾ʵ�ִ��룬���廯�����ȵ���
//��T�滻��Person��������ǰ����Template<>���߱�������ģ�����ش���
template<> bool myCompare(Person& a, Person& b) 
{
	if (a.m_Name == b.m_Name && a.m_Age == b.m_Age)return true;
	return false;
}

void test06() 
{
	Person p1("Jyz", 20);
	Person p2("Jyz", 20);
	//cout << myCompare(p1, p2) << endl;����ģ��ľ���
	//�������1:��Person��==����
	//�������2�����þ��廯Person�İ汾ʵ�ִ��룬���廯�����ȵ���
	cout << myCompare(p1,p2) << endl;
}
int main()
{
	test06();
	return 0;
}