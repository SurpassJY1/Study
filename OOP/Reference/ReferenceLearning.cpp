#include<iostream>
using namespace std;
int& referReturn();
void show(const int& val);
int main()
{ 
	/*
	��ʽ��
	�������� &����=ԭ��;
	ע�����
	���ñ����ʼ��
	int&b;�ǲ������
	����һ����ʼ����Ͳ����Ըı���
	���õı�����ָ�볣��
	*/
	int a = 10;
	int c = 20;
	int& b = a;
	b = c;//���Ǹ������ã��Ǹ�ֵ����
	a = 30;
	cout << a << endl;
	cout << b << endl;
	swap(a, c);
	cout << "a: " << a << endl;
	cout << "c: " << c << endl;
	int&ref = referReturn();
	cout << "ref: " << ref << endl;
	cout << "ref: " << ref << endl;
	//�����������ֵ�����ã��������ÿ���Ϊ��ֵ
	referReturn() = 100000;
	cout << "ref: " << ref << endl;
	show(c);
	return 0;
} 

//������������������,��ָ�����
void swap(int&a,int&b)
{
	int temp = a;
	a = b;
	b = temp;
}
//������������������ֵ
//ע�⣺��Ҫ���ؾֲ�����������
//�÷�����������Ϊ��ֵ
int& referReturn()
{
	//int ref = 10;�����ջ��
	static int ref = 10;//�����ȫ����
	return ref;
}
//�������ã�
//�������ó������������β�����ֹ�����
void show(const int& val)
{
	cout << val << endl;
}