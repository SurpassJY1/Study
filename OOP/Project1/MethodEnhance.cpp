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

int main()
{
	cout << func(10,30);
}