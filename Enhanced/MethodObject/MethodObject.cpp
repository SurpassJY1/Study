#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<functional>
using namespace std;


/*
��������(�º���)��
	���غ������ò��������࣬������Ϊ��������
	��������ʹ�����ص�()ʱ,��Ϊ���ƺ�������,Ҳ�зº���
����
��������(�º���)��һ����,����һ������

�ص�
����������ʹ��ʱ��������ͨ�����������ã������в����������з���ֵ
�������󳬳���ͨ�����ĸ����������������Լ���״̬
�������������Ϊ��������

�ڽ���������
STL���ڽ���һЩ��������

���ࣺ
�����º���
��ϵ�º���
�߼��º���

�÷�
��Щ�º����������Ķ����÷���һ�㺯����ȫ��ͬ
ʹ���ڽ�����������Ҫ����ͷ�ļ�#include<functional>
*/

class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};
class MyPrint
{
public:
	void operator() (string str)
	{
		cout << str << endl;
		count++;
	}
	//�ڲ�״̬
	int count;
	MyPrint()
	{
		this->count = 0;
	}
};
//1
void test01()
{
	MyAdd myAdd;
	cout << myAdd(10, 10) << endl;
}
//2
void test02()
{
	MyPrint mp;
	mp("Hello World");
	mp("Hello World");
	mp("Hello World");
	mp("Hello World");
	mp("Hello World");
	cout << mp.count << endl;
}

void doPrint(MyPrint& mp, string str)
{
	mp(str);
}

//�������������Ϊ�������д���
void test03()
{
	MyPrint mp;
	doPrint(mp, "Hello, c++");
}
//����STL�ڽ���������������
void test04()
{
	//negate ȡ���º�����һԪ
	negate<int> n;
	cout << n(50) << endl;
	//plus ��Ԫ�º��� �ӷ�
	plus<int> p;
	cout << p(100, 100) << endl;
}
//�ڽ����������ϵ�º���
//����greater<>
void test05()
{
	vector<int> v;
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(50);
	v.push_back(10);
	for (vector<int>::const_iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//����STL�ṩ�Ĺ�ϵ�º����������ı��������
	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::const_iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
}
//�߼��º������õıȽ��٣��˽⼴��
void test06()
{
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);
	for (vector<bool>::const_iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//����transform��������v��ת�Ƶ�v2������ȡ��
	vector<bool> v2;
	//��ʹ��transform����ǰҪ��Ŀ��������Ԥ���ռ�
	v2.resize(v.size());
	//��������������ʼ����������ֹ��������Ŀ��������ʼ���������߼��º���
	transform(v.begin(), v.end(), v2.begin(), logical_not<>());
	for (vector<bool>::const_iterator it = v2.begin();it != v2.end();it++)
	{
		cout << *it << " ";
	}
}
int main()
{
	test06();
	system("pause");
	return 0;
}