#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>
using namespace std;
/*
numeric:
accumulate(beg,end,val)计算容器元素累计综合,val是一个起始的累加值
fill(beg,end,val)向容器中添加元素
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
	//后期重新填充
	fill(v.begin(),v.end(),100);
	for_each(v.begin(),v.end(),MyPrint());
}

int main()
{
	test02();
	return 0;
}