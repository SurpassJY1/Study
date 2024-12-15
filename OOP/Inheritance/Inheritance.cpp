#include<iostream>

using namespace std;

class Base 
{
public:
	int pub_Num;
	//��̬��Ա�ص�
	//����׶η����ڴ�
	//�������������ʼ��
	//���ж�����ͬһ������
	static int s_A;
	Base()
	{
		//cout << "Base constructor called" << endl;
		pub_Num = 50;
	}
	~Base()
	{
		//cout << "Base destructor called" << endl;
	}
	void func(int para) 
	{
		cout << "This is func of Base" << endl;
	}
	void func()
	{
		cout << "This is func of Base" << endl;
	}
	//���ྲ̬��Ա����
	//��̬��Ա�����ص㣺
	//ֻ�ܷ��ʾ�̬��Ա����
	//���ж�����һ�ݷ���ʵ��
	static void sFunc() 
	{
		cout << "Base static func called" << endl;
	}
private:
	int pri_Num;
protected:
	int pro_Num;
};

int Base::s_A = 100;

class Derived :public Base
{
public:
	int d_Num;
	int pub_Num;
	static int s_A;
	//This method is used to determine the routine of Base and Derived
	Derived() 
	{
		pub_Num = 100;
		 d_Num = 1;
		//cout << "Derived constructor called" << endl;
	}
	~Derived() 
	{
		//cout << "Derived destructor called" << endl;
	}
	void func()
	{
		cout << "This is func of Derived" << endl;
	}
	//���ྲ̬��Ա����
	static void sFunc() 
	{
		cout << "Derived static func called" << endl;
	}
};
int Derived::s_A = 200;
//ͬ����̬����
void test02() 
{//ͨ���������
	Derived d;
	d.sFunc();//�����
	d.Base::sFunc();//�����
	//ͨ����������
	Derived::sFunc();
	//������ֺ͸���ͬ���ľ�̬��Ա����,Ҳ�����ظ���������ͬ����Ա����
	//�������ʸ�������������ͬ����Ա���������������
	Derived::Base::sFunc();
}
//ͬ����̬��Ա����
void test01() 
{
	Derived d;
	//ͨ���������
	cout << d.s_A << endl;//200
	cout << d.Base::s_A << endl;//100
	//ͨ����������
	cout << Derived::s_A << endl;//200
	//��һ��::��ʾͨ���������ʾ�̬��Ա���ڶ���::��ʾ��Base���µľ�̬��Ա
	cout << Derived::Base::s_A << endl;//100
}
void test()
{
	Derived d;
	//���ุ���е�ͬ����Ա����Ĭ�ϵ������࣬���ø����ڱ�����ǰ����������
	cout << d.pub_Num << endl;//200
	cout << d.Base::pub_Num << endl;//50
	//ͬ����ø���ͬ����Ա����Ҳ��Ҫ��������,�������صĺ�������Ϊ�������ȥ��������ͬ����Ա����
	d.func();//this is func of derived
	d.Base::func(11);//this is func of base
	d.Base::func();//this is func of base
}
//��̳��﷨
//class ���ࣺ�̳з�ʽ ����1���̳з�ʽ������2...
//��̳п��ܻ�������������ͬ����Ա���֣�������Ҫ�����������������
//int main()
//{
//	//��ʹ�Ǹ����з��ʲ����ı���Ҳȫ�������൱��
//	//cout << "Size of Derived: " << sizeof(Derived) << endl;
//	//Derived der;//Base constructor
//				//Derived constructor
//				//Derived destructor
//				//Base destructor
//
//	return 0;
//}