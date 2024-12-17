#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/*
* cpp���ļ�������Ҫ����ͷ�ļ� fstream
�ļ����ͣ�
	�ı��ļ����ļ����ı���ASCII����ʽ�洢�ڼ������
	�������ļ����ļ����ı��Ķ�������ʽ�洢�ڼ�����У��û�һ�㲻��ֱ�Ӷ�����

�����ļ��������ࣺ
	ofstream��д����
	ifstream��������
	fstream����д����
	�ı��ļ���
	д�ļ���
	����ͷ�ļ���
	include<fstream>
	����������
	ofstream ofs;
	���ļ�
	ofs.open("�ļ�·��"���򿪷�ʽ);
	д������
	ofs<<"д�������";
	�ر��ļ�
	ofs.close();
�򿪷�ʽ��
	ios::in Ϊ���ļ���
	ios::out Ϊд�ļ���
	ios::ate ��ʼλ�ã��ļ�β
	ios::app ׷�ӷ�ʽд�ļ�
	ios::trunc ����ļ����ڣ���ɾ�����ٴ���ͬ���ļ�
	�����Ʒ�ʽд�ļ���
	ios::binary|ios::out
	*/
//�ı��ļ�д�ļ�
void test01()
{
	ofstream ofs;
	ofs.open("Test.txt",ios::out);
	//д������
	ofs << "Hello, this is a test file";
	//�ر�
	ofs.close();
}
//��ȡ�ı��ļ�
void read()
{
	ifstream ifs;
	ifs.open("Test.txt",ios::in);
	//�ж��ļ��Ƿ�򿪳ɹ�
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//���ֶ����ݷ�����
	//
	char buf[1024];
	//��һ��
	/*while (ifs>>buf)
	{
		cout << buf <<" ";
	}*/
	//�ڶ���
	/*while (ifs.getline(buf,sizeof(buf)) )//��Ա����getline����һ���������������ڶ����˲����Ƕ�ȡ����
	{
		cout << buf << endl;
	}*/
	//������
	//string str;
	//while (getline(ifs,str)) //ȫ�ֺ�����getline����һ���������ļ����������ڶ�����׼���õ��ַ���
	//{
	//	cout << str << endl;
	//}
	//�����֣�����ʶ������Ƽ�
	/*char c;
	while ((c = ifs.get())!= EOF) 
	{
		cout << c << endl;
	}*/
	ifs.close();
}
int main()
{
	read();
	return 0;
}