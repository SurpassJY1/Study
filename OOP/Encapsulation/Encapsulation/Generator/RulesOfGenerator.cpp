#include<iostream>
using namespace std;

/*
дһ����cpp�����������������
Ĭ�Ϲ��죨��ʵ�֣�
������������ʵ�֣�
�������죨ֵ������
�������д�˹��캯�����ṩĬ�����������Ϳ������캯��
*/
class Person {

public:
	Person() {
		cout << "�޲ι���" << endl;
	}
	Person(int age) {
		this->m_Age = age;
		cout << "�вι���" << endl;
	}
	Person(const Person& p) {
		m_Age = p.m_Age;
		cout << "��������" << endl;
	}
	int m_Age;
	~Person() {
		cout << "��������" << endl;
	}
};
