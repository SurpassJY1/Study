#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
copy(beg,end,dest)
replace��beg��end,old,new���������ھ�Ԫ���滻����Ԫ��
replace_if(beg,end,_pred,new)������_pred��Ԫ���滻Ϊ��Ԫ��
swap(container c1,container c2)��������������Ԫ��
*/
class MyPrint
{
public:
	void operator()(int v1)
	{
		cout << v1 << " ";
	}
};
void test01()
{
	vector<int> v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int> dest;
	//��ǰ��dest����ռ�
	dest.resize(v1.size());
	copy(v1.begin(), v1.end(), dest.begin());
	for_each(dest.begin(), dest.end(), MyPrint());
}
//replace
void test02()
{
	vector<int>v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(10);
	v.push_back(20);
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
	//��20�滻Ϊ666
	replace(v.begin(), v.end(), 20, 666);
	for_each(v.begin(), v.end(), MyPrint());
}
//replace_if
//�����ڵ���30���滻��3000
class GreaterThirty
{
public:
	bool operator()(int val)
	{
		return val >= 30;
	}
};
void test03()
{
	vector<int>v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(10);
	v.push_back(20);
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
	//�����ڵ���30���滻��3000
	replace_if(v.begin(), v.end(), GreaterThirty(), 3000);
	for_each(v.begin(), v.end(), MyPrint());
}
//swap
void test04()
{
	vector<int> v1;
	vector<int> v2;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for (size_t i = 100; i < 110; i++)
	{
		v2.push_back(i);
	}
	cout << "Before swaping" << endl;
	for_each(v1.begin(), v1.end(), MyPrint());
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << "After swaping" << endl;
	swap(v1,v2);
	for_each(v1.begin(), v1.end(), MyPrint());
	for_each(v2.begin(), v2.end(), MyPrint());
}
int main()
{
	test04();
	return 0;
}