#include<iostream>
using namespace std;

//���캯���ķ��༰����
//����
//���������ࣺ �޲ι�����вι���
//�����ͷ��ࣺ ��ͨ����Ϳ�������

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
//int main() {
//	//���õķ�����
//	//���ŷ�:
//	//ע���������Ĭ���޲ι����ʱ��Ҫ����
//	//��Ϊ����������ΪPerson p1();��һ������������
//	/*Person p1;
//	Person p2(10);
//	Person p3(p2);
//	cout<<"Age of p2 "<<p2.m_Age << endl;
//	cout<<"Age of p3 "<<p3.m_Age << endl;*/
//	//��ʾ��
//	Person p1;
//	Person p2 = Person(10);
//	Person p3 = Person(p2);
//	
//	Person(10);//���������ص㣺��ǰִ�н���ʱϵͳ����������
//	//ע�⣺��Ҫʹ�ÿ�����������ʼ����������
//	//ϵͳ����ΪPerson(p2)ΪPerson p2
//
//	//��ʽת����
//	Person p4 = 10;
//	Person p5 = p4;
//
//}