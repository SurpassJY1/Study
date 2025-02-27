#include<iostream>
#include<vector>
using namespace std;
/*
vector的迭代器是支持随机访问的迭代器
vector的构造函数
vector<T> v;
vector(v.begin(),v.end());将v[begin(),end())区间中的元素拷贝给本身
vector(n,elem);将n个elem拷贝给本身
vector(const vector &vec);拷贝构造函数

vector赋值操作
vector& operator=(const vector &vec)重载等号操作符赋值
assign(beg,end)将[beg,end)区间中的数据拷贝赋值给本身
assign(n,elem)将n个 elem 拷贝赋值给本身

vector容量和大小
函数原型
empty(); 判断容器是否为空
capacity();容器的容量
size(); 返回容器的个数
resize(int num);重新指定容器长度为num，若容器边长，则以默认值填充新位置
				若容器变短，则末尾超出容器长度的元素被删除
resize(int num,elem);重新指定容器长度为num，若容器边长，则以elem填充新位置
					若容器变短，则末尾超出容器长度的元素被删除

vector容器的插入和删除
函数原型
push_back(ele);尾部插入元素ele
pop_back();尾部删除最后一个元素
insert(const_iterator pos,ele);迭代器指向位置pos插入元素ele
insert(const_inerator pos,int count,ele);迭代器指向位置pos插入count个元素ele
erase(const_iterator pos);删除迭代器指向的元素
erase(const_iterator start,const_iterator_iterator end);删除迭代器从start到end之间的元素
clear();删除容器中的所有元素

vector容器的数据存取操作
函数原型
at(int idx);返回索引idx所指的数据
operator[];返回索引idx所指的数据
front();返回容器中第一个数据元素
back();返回容器中最后一个数据元素

vector互换容器
函数原型
swap(vec);将vec与本身元素互换
实际用途
巧用swap可以收缩内存空间
	vector<int>(v).swap(v);
	vector<int>(v)利用拷贝构造函数创造的一个匿名对象
	.swap(v)容器交换
	最后系统回收匿名对象

	vector容器预留空间
	减少vector在动态扩展容量时的扩展速度
	函数原型：
	reserve(int len);容器预留len个元素长度，预留位置不初始化，元素不可访问
*/
void print(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
}
void test01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	print(v1);
	cout << "------------------------------------" << endl;
	//通过区间构造
	vector<int> v2(v1.begin(), v1.end());
	print(v2);
	cout << "--------------------------------------" << endl;
	//n个 element构造
	vector<int> v3(10, 1);
	print(v3);
	cout << "-------------------------------------------" << endl;
	vector<int> v4(v3);
	print(v4);
}
//vector的赋值
void test02()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	print(v1);
	//operator=
	vector<int>v2 = v1;
	print(v2);
	//assign
	vector<int> v3;
	v3.assign(v2.begin(), v2.end());
	cout << "-------------------------" << endl;
	print(v3);
	cout << "-----------------------------" << endl;
	vector<int>  v4;
	v4.assign(10, 1);
	print(v4);
}
//vector容器的容量和大小操作
void test03()
{
	vector<int>v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	print(v1);
	cout << "-------------------" << endl;
	if (v1.empty())
	{
		cout << "v1 is empty" << endl;
	}
	else cout << "v1 is not empty" << endl;
	cout << "Capacity of v1 is " << v1.capacity() << endl;
	cout << "Size of v1 is " << v1.size() << endl;
	//重新指定大小
	v1.resize(15);
	cout << "Size of v1 is " << v1.size() << endl;//重新指定的比原来长默认用0填充
	cout << "------------------------" << endl;
	print(v1);
	//指定默认填充值
	v1.resize(20, 100);
	cout << "--------------------------" << endl;
	print(v1);
}
/*
push_back(ele);尾部插入元素ele
pop_back();尾部删除最后一个元素
insert(const_iterator pos,ele);迭代器指向位置pos插入元素ele
insert(const_inerator pos,int count,ele);迭代器指向位置pos插入count个元素ele
erase(const_iterator pos);删除迭代器指向的元素
erase(const_iterator start,const_iterator_iterator end);删除迭代器从start到end之间的元素
clear();删除容器中的所有元素*/
void test04()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	print(v1);
	cout << "------------------" << endl;
	v1.pop_back();
	print(v1);
	cout << "------------------" << endl;

	//插入
	//第一个参数是迭代器
	v1.insert(v1.begin(), 100);
	print(v1);
	cout << "------------------" << endl;
	v1.insert(v1.begin(), 2, 2);
	print(v1);
	cout << "------------------" << endl;
	//删除参数也是迭代器
	v1.erase(v1.begin());
	print(v1);

	cout << "------------------" << endl;
	//清空
	v1.clear();
	print(v1);

}
void test05()
{
	vector<int>v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	//利用[]方式访问数组中的元素
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " " << endl;
	}
	cout << endl;
	//利用at方式访问元素
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << endl;
	}
	cout << endl;
	//获取第一个元素
	cout << "第一个元素" << v1.front() << endl;
	//获取最后一个元素
	cout << "最后一个元素" << v1.back() << endl;
}
void test06()
{
	vector<int>v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int>v2;
	for (size_t i = 10; i < 20; i++)
	{
		v2.push_back(i);
	}
	cout << "v1:" << endl;
	print(v1);
	cout << endl;
	cout << "v2:" << endl;
	print(v2);
	cout << endl;
	v1.swap(v2);
	cout << "v1:" << endl;
	print(v1);
	cout << "v2:" << endl;
	print(v2);
}
//利用swap收缩内存空间
void test07()
{
	vector<int>v;
	for (size_t i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << "Capacity of v is " << v.capacity() << endl;
	cout << "Size of v is " << v.size() << endl;
	cout << endl;
	v.resize(3);
	cout << "Capacity of v is " << v.capacity() << endl;
	cout << "Size of v is " << v.size() << endl;
	cout << endl;
	//利用swap收缩内存空间
	vector<int>(v).swap(v);
	cout << "Capacity of v is " << v.capacity() << endl;
	cout << "Size of v is " << v.size() << endl;
	/*/巧用swap可以收缩内存空间
		vector<int>(v).swap(v);
	vector<int>(v)利用拷贝构造函数创造的一个匿名对象
		.swap(v)容器交换
		最后系统回收匿名对象*/
}
//预留空间
void test08()
{
	vector<int>v;
	//提前预留空间
	v.reserve(100000);
	int num = 0;
	int* p = nullptr;
	for (size_t i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p!=&v[0])
		{
			//重新开辟空间后再让p指向头一个元素
			p = &v[0];
			num++;
		}
	}
	cout << "重新开辟空间次数为：" << num << endl;//动态扩展了30次
													//预留100000空间后就动态扩展了一次
}
int main()
{
	test08();
	system("pause");
	return 0;
}