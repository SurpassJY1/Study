#include<iostream>
using namespace std;

//����Ĭ�ϲ���

//����Լ��������ݾ����Լ������ݣ����û�У���ô��Ĭ��ֵ
int func(int a,int b=20, int c=30)
{
	return a + b + c;
}

//���ĳ��λ���Ѿ���Ĭ�ϲ�������ô���λ����������Ҷ�������Ĭ��ֵ
/*������
int func(int a,int b=10.int c)
{
return a+b+c;
}
*/
//�������������Ĭ�ϲ���������ʵ�־Ͳ�����Ĭ�ϲ���
//������ʵ�ֵ���ֻ����һ����Ĭ�ϲ���

//ռλ����
// �﷨���β�ֻдһ����������
//ռλ������������Ĭ�ϲ���

//��������
//���ã�������������ʹ����߸�����
// �������ص�������
//ͬһ��������
//����������ͬ
//�����������Ͳ�ͬ�����߸�����ͬ������˳��ͬ
//ע�⣬��������ֵ�ǲ���������������
//ע�����
// ������Ϊ������������
// ������������Ĭ�ϲ���
//

void overloadFunc() {
	cout << "overloadFunc use" << endl;
}



void overloadFunc(int a,double b) {
	cout << "overloadFunc(int a,double b) use!" << endl;
}

void overloadFunc(double b,int a) {
	cout << "double b,int a" << endl;
}

void overloadFunc(int&a) {
	cout << "overloadFunc(int&a) used" << endl;
}

//������������Ĭ�ϲ���������overloadFucn(a)�ɵ���������Ǹ�Ҳ���Ե�������ģ���֪�������ĸ�
// void overloadFunc(int&a, int b=10) {
//	cout << "overloadFunc(int&a, int b=10) used" << endl;
//}

void overloadFunc(const int& a) {
	cout << "overloadFunc(const int&a) used" << endl;
}


void func2(int a, int=10)
{
	cout << "this is a function" << endl;
}
int main()
{
	int a = 1;
	overloadFunc(a);//overloadFunc(int&a) used  �������úϷ����ڴ�ռ�,ջ��������� int &a=1 ָ���������Ϸ�
	overloadFunc(1);//overloadFunc(const int&a) used
	overloadFunc();
	overloadFunc(1, 1.1);
	overloadFunc(1.1, 1);

}