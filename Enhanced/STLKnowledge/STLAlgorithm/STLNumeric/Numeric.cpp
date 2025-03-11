#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>
using namespace std;
/*
numeric:
accumulate(beg,end,val)��������Ԫ���ۼ��ۺ�,val��һ����ʼ���ۼ�ֵ
fill(beg,end,val)�����������Ԫ��
*/
//accumulate
void test01() {
	vector<int>v;
	for (size_t i = 1; i <= 100; i++)
	{
		v.push_back(i);
	}
	int total=accumulate(v.begin(),v.end(),1000);
	cout << total << endl;
}
class MyPrint 
{
public:
	void operator()(int val) 
	{
		cout << val << " ";
	}
};
//fill
void test02() 
{
	vector<int> v;
	v.resize(10);
	//�����������
	fill(v.begin(),v.end(),100);
	for_each(v.begin(),v.end(),MyPrint());
}

int main()
{
	test02();
	return 0;
}