#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
返回bool类型的仿函数我们称之为谓词
如果operator()接受的是一个参数，我们称之为一元谓词
如果operator()接受的是两个参数，我们称之为二元谓词
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
//一元谓词案例
void test01()
{
	vector<int> v;
	for (int i = 0;i < 10;i++) 
	{
		v.push_back(i);
	}
	//利用一元谓词找到大于5的数字
	//传入迭代器和谓词找到符合条件的元素
	//find_if返回迭代器
	vector<int>::iterator it=find_if(v.begin(),v.end(), GreaterFive());
	cout << (*it) << endl;
}
//二元谓词案例
void test02()
{
	vector<int> v;
	v.push_back(90);
	v.push_back(30);
	v.push_back(20);
	v.push_back(60);
	v.push_back(40);
	v.push_back(80);
	//利用sort算法将他排序
	//sort算法默认升序排列
	sort(v.begin(),v.end());
	for (vector<int>::const_iterator it = v.begin();it != v.end();it++) 
	{
		cout << (*it) << " ";
	}
	cout << endl;
	//利用匿名函数对象(二元谓词)将他改为降序排列
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