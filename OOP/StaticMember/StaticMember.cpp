#include<iostream>
using namespace std;
/*
���ж�����һ������
�ڱ���׶η����ڴ�
�������������ʼ��
��̬��Ա���಻����ĳ���������ж�����ͬһ������
��˾�̬��Ա���������ַ��ʷ�ʽ��
�����Ͷ���
��̬��Ա����Ҳ�з���Ȩ�ޣ�
˽�г�Ա������ʲ���

��̬��Ա������
���ж�����ͬһ������
��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
��̬��Ա����Ҳ���Լ��ķ���Ȩ��

��Ա�����ͳ�Ա�����ֿ��洢��
ֻ�зǾ�̬��Ա����������Ķ�����
*/
class EmptyClass {};
class NotEmpty {
	int a;//�Ǿ�̬��Ա������������Ķ�����
	static int s_a;//��̬��Ա��������������Ķ�����
	void func() {}//�Ǿ�̬��Ա����,��������Ķ�����
	static void func() {}//��̬��Ա����,��������Ķ�����
};
class Person
{
public:
	Person();
	~Person();
	static void staticFunc() {
		//��̬��Ա�����ܷ��ʾ�̬��Ա����
		m_A = 100;
		//��̬��Ա�������ܷ��ʷǾ�̬��Ա��������Ϊ�޷������ĸ�����ĳ�Ա����
		//m_B = 100;
		cout << "staticFunc used" << endl;
	}
private:
	static void staticFunc2() {
	}
	static int m_A;
	int m_B;
};

Person::Person()
{
}

Person::~Person()
{
}
//�����ʼ��
int Person::m_A = 10;

int main()
{//��Ȩ��
	//Person::staticFunc2();
	//�ն���ռ��һ���ֽ�
	//C++����������ն������һ���ֽڿռ䣬��Ϊ�����ֿն���ռ�ڴ��λ��
	//ÿһ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
	// 
	//
	cout << sizeof(EmptyClass) << endl;
	cout << sizeof(NotEmpty) << endl;
	return 0;
}