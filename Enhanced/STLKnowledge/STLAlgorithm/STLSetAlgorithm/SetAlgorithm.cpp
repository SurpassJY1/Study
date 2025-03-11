#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
常用集合算法
itEnd set_intersection(beg1,end1,beg2,end2,begTar);
求交集
返回目标容器中最后一个交集元素的迭代器
itEnd set_union(beg1,end1,beg2,end2,begTar);
求并集，注意，两个容器必须是有序序列
itEnd set_difference(beg1,end1,beg2,end2,begTar)
求差集，注意，两个容器必须是有序序列
*/

//itEnd set_intersection(beg1,end1,beg2,end2,begTar)
class MyPrint 
{
public:
	void operator()(int v) 
	{
		cout << v << " ";
	}
};

void test01()
{
	vector<int> v1;
	vector<int> v2;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i+5);
	}
	//存储交集的目标容器
	vector<int> v3;
	//提前在v3开辟交集的空间
	//v3的空间取两个容器小的那个因为交集元素最大不会大于他
	v3.resize(min(v1.size(),v2.size()));
	//接受set_intersection返回的迭代器，是交集最后一个元素的迭代器，用于遍历
	vector<int>::iterator itEnd=set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
	for_each(v3.begin(),itEnd,MyPrint());
}
//set_union
void test02()
{
	vector<int> v1;
	vector<int> v2;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i+5);
	}
	//target
	vector<int> v3;
	//最特殊的情况就是没有交集，并集大小是两个容器大小相加
	v3.resize(v1.size()+v2.size());
	//接收并集的最后一个元素的迭代器位置
	auto itEnd=set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
	for_each(v3.begin(),itEnd,MyPrint());
}
//set_difference
void test03()
{
	vector<int> v1;
	vector<int> v2;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i+5);
	}
	vector<int> vTar;
	//求差集最特殊情况就是没有交集，此时size取两个容器当中大的哪一个
	vTar.resize(max(v1.size(),v2.size()));
	auto itEnd = set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),vTar.begin());
	for_each(vTar.begin(),itEnd,MyPrint());
	cout << endl;
	//求v2-v1
	vector<int> v3;
	v3.resize(max(v1.size(),v2.size()));
	auto itEnd2 = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v3.begin());
	for_each(v3.begin(), itEnd2, MyPrint());

}
int main() {
	test03();
	system("pause");
	return 0;
}