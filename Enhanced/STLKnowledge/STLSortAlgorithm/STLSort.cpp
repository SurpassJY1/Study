#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
using namespace std;
/*
常用排序算法
sort(beg,end,_pred)对容器内元素进行排序
random_shuffle洗牌，指定范围内的元素随机调整次序
merge(beg1,end1,beg2,end2,dest)容器元素合并，并存储到另一容器中，两个容器必须是有序的,目标容器也是有序的
reverse(beg,end)反转指定范围的元素
*/
class MyPrint 
{
public:
	void operator()(int v) 
	{
		cout << v << " ";
	}
};

class MyCompare 
{
public:
	bool operator()(int v1,int v2) 
	{
		return v1 > v2;
	}
};
void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);
	sort(v.begin(),v.end());
	for_each(v.begin(),v.end(),MyPrint());
	cout << endl;
	sort(v.begin(),v.end(),MyCompare());
	for_each(v.begin(), v.end(), MyPrint());
}
//random_shuffle
void test02() 
{
	//随机数的种子
	srand((unsigned int)time(NULL));
	vector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(),v.end(),MyPrint());
	cout << endl;
	cout << "After random_shuffle" << endl;
	random_shuffle(v.begin(),v.end());//要让每次点开都不一样需要一个随机数的种子
	for_each(v.begin(), v.end(), MyPrint());
}
//merge
void test03() 
{
	vector<int> v1;
	vector<int> v2;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for (size_t i =5; i < 20; i++)
	{
		v2.push_back(i);
	}
	vector<int> vTar;
	vTar.resize(v1.size()+v2.size());
	merge(v1.begin(),v1.end(),v2.begin(),v2.end(),vTar.begin());
	//报错，因为没有提前给vTar分配空间
	for_each(vTar.begin(),vTar.end(),MyPrint());
}
//reverse(beg,end)
void test04() 
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);
	for_each(v.begin(),v.end(),MyPrint());
	cout << endl;
	reverse(v.begin(),v.end());
	for_each(v.begin(),v.end(),MyPrint());
}
int main() 
{
	test04();
	system("pause");
	return 0;
}