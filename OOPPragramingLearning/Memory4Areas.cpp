#include<iostream>
using namespace std;
int* func();
int* createArr(int i);

int g_a = 10;
int g_b = 10;

int main()
{
	/*
	����������Ŷ����ƴ��룬�ɲ���ϵͳ����
	ȫ���������ȫ�ֱ����;�̬�����Լ�����
	ջ�����ɱ������Զ������ͷţ���ź����Ĳ���ֵ�ֲ�������
	�������ɳ���Ա������ͷţ�������Ԫ���ͷţ��������ʱ�ɲ���ϵͳ����

	������ȫ�����ڳ�������ǰ����
	����������ֻ��
	����Ƶ��ִ�еĳ����ڴ�����һ�ݴ������
	��ֹ����������޸��˻���ָ��

	ȫ������������������ڳ���������ɲ���ϵͳ�ͷ�

	ջ����ź��������;ֲ�����
	ջ���ɱ����������ٺ��ͷ�
	ע�����
	��Ҫ���ؾֲ������ĵ�ַ

	�������ɳ���Ա�����ͷţ��������ʱ�ɲ���ϵͳ����
	��new�ؼ����ֶ�����
	��delete�����ֶ��ͷ�
	*/
	int* p = func();
	//�ֶ��ͷ�
	//delete p;
	 cout<<*p;
	 cout << "�ҷ����ʱ��" << endl;
	 cout << "�ҷ����ʱ��" << endl;
	 cout << "�ҷ����ʱ��" << endl;
	 cout << "�ҷ����ʱ��" << endl;
	 cout << "�ҷ����ʱ��" << endl;
	 cout << "�ҷ����ʱ��" << endl;
	 cout << "�ҷ����ʱ��" << endl;
	 cout << "�ҷ����ʱ��" << endl;
	 cout << "�ҷ����ʱ��" << endl;
	 cout << "�ҷ����ʱ��" << endl;
	 cout << "�ҷ����ʱ��" << endl;
	 cout << "�ҷ����ʱ��" << endl;
	 cout << "�ҷ����ʱ��" << endl;
	 cout << "�ҷ����ʱ��" << endl;
	 cout << "�ҷ����ʱ��" << endl;
	 cout << "�ҷ����ʱ��" << endl;
	 int *arr=createArr(10);//��Ϊ�ڶ��������Է��س�����Ҳ�����Զ���ʧ
	 for (size_t i = 0; i < 10; i++)
	 {
		 cout << arr[i];
	 }
	 delete[]arr;//�ͷ���������Ҫ��ǰ��Ӹ������Ų�Ȼ��ֻ�ͷ��˵�һ��Ԫ��
	 
	 return 0;
}

int* createArr(int i)
{
	int* arr = new int[i];
	for (size_t j = 0; j < i; j++)
	{
		arr[j] = 0;
	}
	for (size_t j = 0; j < i; j++)
	{
		cout << arr[j];
	}
	return arr;
}
int* func()
{
//��new�ؼ��ֿ��Խ����ݿ��ٵ�����
	int* p = new int(10);//ָ�뱾��Ҳ�Ǿֲ�����������ջ�ϣ�ָ�뱣������ݴ���ڶ���
		return p;
}
//��������ȫ����
void globalArea()
{
	int a = 10;
	int b = 10;
	static int s_a = 10;
	static int s_b = 10;
	const int c_l_a = 10;
	const int c_l_b = 10;
	string str = "a";//�����ַ�������
	string  str2 = "b";
	cout << (int)&a << endl;
	cout << (int)&b << endl;
	cout << (int)&g_a << endl;
	cout << (int)&g_b << endl;
	cout << (int)&s_a << endl;
	cout << (int)&s_b << endl;
	cout << (int)&"1" << endl;
	cout << (int)&"2" << endl;
	cout << (int)&c_l_a << endl;
	cout << (int)&c_l_b << endl;
	cout << (int)&str << endl;
	cout << (int)&str2 << endl;
	//�ֲ������ֲ�����������ȫ����
	//ȫ�ֱ�����̬��������(const���ε�ȫ�ֳ����Լ��ַ�������)��ȫ������
}