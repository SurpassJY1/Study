#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
����bool���͵ķº������ǳ�֮Ϊν��
���operator()���ܵ���һ�����������ǳ�֮ΪһԪν��
���operator()���ܵ����������������ǳ�֮Ϊ��Ԫν��
*/
class GreaterFive 
{
public:
	bool operator()(int val) 
	{
		return val > 5;
	}
};
class MyCompare 
{
public:
	bool operator()(int val1,int val2)
	{
		return val1 > val2;
	}
};
//һԪν�ʰ���
void test01()
{
	vector<int> v;
	for (int i = 0;i < 10;i++) 
	{
		v.push_back(i);
	}
	//����һԪν���ҵ�����5������
	//�����������ν���ҵ�����������Ԫ��
	//find_if���ص�����
	vector<int>::iterator it=find_if(v.begin(),v.end(), GreaterFive());
	cout << (*it) << endl;
}
//��Ԫν�ʰ���
void test02()
{
	vector<int> v;
	v.push_back(90);
	v.push_back(30);
	v.push_back(20);
	v.push_back(60);
	v.push_back(40);
	v.push_back(80);
	//����sort�㷨��������
	//sort�㷨Ĭ����������
	sort(v.begin(),v.end());
	for (vector<int>::const_iterator it = v.begin();it != v.end();it++) 
	{
		cout << (*it) << " ";
	}
	cout << endl;
	//����������������(��Ԫν��)������Ϊ��������
	sort(v.begin(),v.end(),MyCompare());
	for (vector<int>::const_iterator it = v.begin();it != v.end();it++) 
	{
		cout << (*it) << " ";
	}
}

int main()
{
	test02();
	system("pause");
	return 0;
}