#include<iostream>
using namespace std;

class Person
{
	/*
	1.���캯��û�з���ֵ
	2.���캯��û�в���
    3.���캯��������������ͬ
	4.���캯�������в�������������
	5.���������ʱ���캯�����Զ����ã�����ֻ�����һ��
	*/
public:
	Person() {
	cout<< "Person()" << endl;
	}
	/*
	��������
	û�з���ֵ��дvoid
	��������������ͬ��ǰ��ӡ�
	û�в�������������
	*/
    ~Person() {
	cout<< "~Person()" << endl;
	}
};
//int main()
//{
//	Person p;
//	return 0;
//}