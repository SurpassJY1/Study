#include<iostream>
using namespace std;

class Person {

public:
	Person() {
		cout << "�޲ι���" << endl;
	}
	Person(int age) {
		this->m_Age = age;
		cout << "�вι���" << endl;
	}

	//�������캯���ĵ���ʱ��
	//1.ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
	//2.��ֵ���ݵķ�ʽ��������ֵ
	//3.��ֵ��ʽ���ؾֲ�����
	Person(const Person& p) {
		m_Age = p.m_Age;
		cout << "��������" << endl;
	}
	int m_Age;
	~Person() {
		cout << "��������" << endl;
	}
};
void test(Person p) {
}
Person test2() {
	Person p;
	return p;
}
void test3() {
	Person p=test2();
}
//int main()
//{
//	//�������캯���ĵ���ʱ��
//	//1.ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
//	Person p1 = 10;
//	Person p2 = p1;
//	cout << "--------------------------" << endl;
//	//2.��ֵ���ݵķ�ʽ��������ֵ
//	test(p1);
//	cout << "--------------------------" << endl;
//	//3.��ֵ��ʽ���ؾֲ�����
//	test3();
//	cout << "--------------------------" << endl;
//	return 0;
//}