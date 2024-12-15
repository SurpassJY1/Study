#include<iostream>
using namespace std;
/*
��������أ�
�����е�������������¶��壬��������һ�ֹ��ܣ�����Ӧ��ͬ����������
ע������
1.����������������,���ʽ���������������
2.��Ҫ�������������
*/
//ʵ�ּӺ����������
//1.��Ա�������ؼӺ�
//2.ȫ�ֺ������ؼӺ�

//ʵ���������������
class Person {
	friend	Person& operator+(Person& p1, Person& p2);
	friend	Person& operator+(Person& p1, int num);
	friend ostream& operator<<(ostream& cout, Person& p);
	friend void test();

private:
	int m_A;
	int m_B;
	//��Ա�������ؼӺ�
		/*Person& operator+(Person& p)
		{
			Person temp;
			temp.m_A = p.m_A + this->m_A;
			temp.m_B = p.m_B + this->m_B;
			return temp;
		}*/
		//ͨ���������ó�Ա���������������������Ϊ���ܱ�֤cout�����

};
//ȫ�ֺ������ؼӺ�
Person& operator+(Person& p1, Person& p2)
{
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}
//��������Ҳ���Է�����������
Person& operator+(Person& p1, int num)
{
	Person temp;
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}
//ֻ������ȫ�ֺ����������������
//cout�Ǳ�׼���������,ֻ����һ������ֻ�����÷�ʽ����
ostream& operator<<(ostream& cout, Person& p)
{
	cout << "m_A " << p.m_A << " m_B" << p.m_B;
	return cout;
}

//���ؼӼ��������ʹ���ܹ�����Լ���������
class MyInteger {
public:
	int m_Num;
	MyInteger(int num);
	//����ǰ��++�����
	MyInteger& operator++() {
		m_Num++;
		return *this;
	}
	//����ǰ��--�����
	MyInteger& operator--() 
	{
		m_Num--;
		return *this;
	}
	//���غ���--�����
	MyInteger operator--(int)
	{
		MyInteger temp = *this;
		this->m_Num--;
		return temp;
	}
	//���غ���++�����
	//int����һ��ռλ������������������ǰ�úͺ��õ���
	MyInteger operator++(int) 
	{
		//�ȷ��ؽ�����ٽ��е���
		MyInteger temp = *this;
		this->m_Num++;
		//����ֵ���ݣ���Ϊtemp�Ǿֲ��������ں���������ᱻ�ͷţ����Բ������ô���
		return temp;
	}
};
MyInteger::MyInteger(int num) {
	m_Num = num;
}

ostream& operator<<(ostream& cout,MyInteger myint) 
{
	cout << myint.m_Num;
	return cout;
}

void test2() {
	MyInteger myint(0);
	cout << ++myint << endl;
	cout << myint++ << endl;
	cout << myint << endl;
	cout << --myint << endl;
	cout << myint-- << endl;
	cout << myint << endl;
}
class Student {
	friend ostream& operator<<(ostream& cout, Student& stu);
private:
	int* m_Age;
public:
	Student(int age) :m_Age(new int(age)){}
	//д���Լ�������������ɾ�������ڴ�
	~Student() 
	{
		if (m_Age!=nullptr)
		{
			delete m_Age;
			m_Age = nullptr;
		}
	}
	//���ظ�ֵ����
	Student& operator=(Student& stu) 
	{
	//�жϱ���m_Age���޼�¼ֵ,�еĻ���ɾ��
		if (m_Age!=nullptr)
		{
			delete m_Age;
			m_Age = nullptr;
		}
		m_Age = new int(*stu.m_Age);
		return *this;
	}
	Student& operator=(int age)
	{
		*m_Age = age;
		return *this;
	}
	//�����߼������
	bool operator==(Student& stu) 
	{
		if (*this->m_Age==*stu.m_Age)
		{
			return true;
		}
		return false;
	}
	bool operator!=(Student& stu) 
	{
		return *this->m_Age != *stu.m_Age;
	}
};
//����Student���<<����
ostream& operator<<(ostream& cout,Student& stu) 
{
	cout << *stu.m_Age;
	return cout;
}

void test3() 
{
	Student stu1(18);
	Student stu2(19);
	cout << stu1 << endl;
	cout << stu2 << endl;
	cout << "-----------" << endl;
	Student stu3(20);
	stu2 = stu1;
	cout << stu2 << endl;//ǳ�������18,��д��������֮�󱨴�ԭ����ǳ��������ֽڵĿ�����
						 //����stu2��m_Age�ĵ�ַ��stu1�е�һ��,�����ظ��ͷ�
						 //�������Ҫ��д��ֵ�������¿����ڴ�ռ�������
	stu3 = stu2 = stu1;
	cout << "Stu3: " << stu3 << " Stu2: " << stu2 << " Stu1: " << endl;
	if (stu3==stu2)
	{
		cout << "True" << endl;
	}
	stu2 = 30;
	if (stu3!=stu2)
	{
		cout << "False" << endl;
	}
}

//ͨ������()����ʵ�ַº���,�º�����Ϊ���ÿ������������Խзº���

class MyAdd 
{public:
	int operator()(int num1,int num2) 
	{
		return num1 + num2;
	}
};

void test4() 
{
//ͨ������������÷º���,����+��������һ����������
	cout << MyAdd()(30, 30)<< endl;
}

void test() {
	Person p;
	p.m_A = 10;
	p.m_B = 10;
	Person p2;
	p2.m_A = 20;
	p2.m_B = 20;
	Person p3 = p + p2;
	Person p4 = p + 100;
	cout << p << endl;
}



int main()
{
	test4();
	return 0;
}