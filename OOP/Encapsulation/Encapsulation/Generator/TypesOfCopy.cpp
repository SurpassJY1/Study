#include<iostream>
using namespace std;

/*
�����ǳ����

ǳ�������򵥵ĸ�ֵ��������,���⣺�������ڴ��ظ��ͷ�

������ڶ�����������һ���ڴ�ռ���и�ֵ����
*/
class Person {

public:

	Person() {}
	Person(int age,int height) {
		this->m_Age = age;
		this->height = new int(height);
		cout << "�вι���" << endl;
	}
	Person(const Person &p) {
		cout << "�����������" << endl;
		m_Age = p.m_Age;
		//�������
		height = new int(*p.height);
	}

	int m_Age;
	//���������ٵ����������������ֶ��ͷ�
	int* height;
	~Person() {
		if (height!=nullptr)
		{
			delete height;
			height = nullptr;
		}
		cout << "��������" << endl;
	}
};
void test()
{
	Person p1(18,180);
	cout << "p1 " << p1.m_Age<<"height: "<<*p1.height << endl;
	Person p2 = p1;
	cout << "p2 " << p2.m_Age <<"height: "<<*p2.height << endl;
}
int main()
{
	test();
	return 0;
}