#include<iostream>
using namespace std;
class Person {

public:
	//������
	//�ڳ�Ա���������const���ε���this����thisָ�벻�����޸�ָ��ָ������ֵ
	 void showPerson() const
	{
		//m_A=100;�൱��this��>m_A = 100;
		// thisָ��ı�����ָ�볣����ָ�볣����ָ���ǲ����޸ĵģ�
		// ����thisָ��ָ������ֵ�ǿ����޸ĵ�
		// ������thisָ���ֵҲ�������޸�,
		// �൱��Person* const this��const Person* const this
		 //���ʽ����Ϊ���޸ĵ���ֵ
		 m_B = 100;
	}
	 void func() {}
	int m_A;
	mutable int m_B;//�����������������Ҳ�����޸����ֵ
};

void test1() {
	Person p;
	
	p.showPerson();
	cout << p.m_B << endl;
}
void test2() {
//������
	const Person p;
	//p.m_A = 100;�����󲻿����޸ĳ�Ա����
	p.m_B = 200;//����������޸�mutable���εĳ�Ա����
	//p.func();//������ֻ�ܵ��ó���������Ϊ��ͨ�ĳ�Ա���������޸�����
	p.showPerson();
}
int main() {
	test1();
	return 0;
}