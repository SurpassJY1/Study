#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>//标准算法的头文件
using namespace std;
/*
deque的构造函数
deque<T> deqT; 默认
deque(beg,end) deqT; 迭代器构造
deque(n,elem); n个几构造
deque(const deque &deque) 拷贝构造

deque的赋值操作
deque& operator=(const deque &deq);重载等号
assign(beg, end)将[beg,end)区间中的数据拷贝复制给本身
assign(n,elem)n个elem赋值

deque的大小操作
deque.empty()判断是否为空
deque.size()返回容器中元素个数
deque.resize(num)重新指定容器的长度为num
deque.resize(num,elem)重新指定容器长度为num，若容器变长则用elem填充

deque的插入和删除
两端插入操作
push_back(elem) 在容器尾部添加一个数据
push_front(elem) 在容器头部插入一个数据
pop_back(); 删除容器最后一个数据
pop_front(); 删除容器第一个数据

指定位置操作
insert(pos,elem); 在pos位置插入一个elem元素的拷贝,返回新数据的位置
insert(pos,n,elem); 在pos位置插入n个elem数据，无返回值
insert(pos,beg,end); 在pos位置插入[beg,end)区间的数据，无返回值
clear(); 清空容器内所有的数据
erase(beg,end); 删除[beg,end)区间的数据，返回下一个数据的位置
erase(pos);删除pos位置的数据，返回下一个数据的位置

deque的数据存取操作
at(int index)； 返回索引idx所指的数据
operator[]； 返回索引idx所指的数据
front()；返回容器中的第一个元素
back()；返回容器中的最后一个元素

deque的排序
sort(iterator beg,iterator end)
对beg和end区间内的元素进行排序
对于支持随机访问的迭代器容器都可以利用sort算法直接对其进行排序
*/
void printDeq(const deque<int>& deq)
{
	for (deque<int>::const_iterator it = deq.begin(); it != deq.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int> d1;
	for (size_t i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeq(d1);
	deque<int> d2(d1);
	printDeq(d2);
	deque<int> d3(10, 100);
	deque<int> d4(d1.begin(), d1.end() - 5);
	printDeq(d3);
	printDeq(d4);
}

void test02()
{
	deque<int>d1;
	for (size_t i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	deque<int>d2 = d1;
	printDeq(d2);
	deque<int>d3;
	d3.assign(10, 100);
	printDeq(d3);
	deque<int>d4;
	d4.assign(d3.begin(), d3.end() - 5);
	printDeq(d4);
}

void test03()
{
	deque<int>d1;
	for (size_t i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	if (!d1.empty())
	{
		cout << "d1 is not empty" << endl;
	}
	cout << "Size of d1 is " << d1.size() << endl;
	d1.resize(5);
	cout << "Size of d1 is after resizing " << d1.size() << endl;
	printDeq(d1);
	d1.resize(10);
	cout << "Size of d1 is after resizing again " << d1.size() << endl;
	printDeq(d1);
	d1.resize(15, 15);
	printDeq(d1);
}

void test04()
{
	//两端操作
	deque<int> d1;
	//尾插
	for (size_t i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	deque<int> d2;
	for (size_t i = 0; i < 10; i++)
	{
		d2.push_front(i);
	}
	cout << "d1：" << endl;
	printDeq(d1);
	cout << "d2：" << endl;
	printDeq(d2);
	d1.insert(d1.begin(), 10000);
	printDeq(d1);
	d2.clear();
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);
	d1.insert(d1.begin(), d2.begin(), d2.end());
	printDeq(d1);
	d1.erase(d1.begin() + 1);
	printDeq(d1);
}

void test05()
{
	deque<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);
	cout << d.at(0) << endl;
	cout << d[1] << endl;
	cout << d.front() << endl;
	cout << d.back() << endl;

}

void test06()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	cout << "Before sorting: ";
	printDeq(d);
	cout << "After sorting: ";
	sort(d.begin(), d.end());
	printDeq(d);
	//对于支持随机访问的迭代器容器都可以利用sort算法直接对其进行排序
	vector<int>v;
	v.push_back(10);
	v.push_back(140);
	v.push_back(40);
	v.push_back(666);
	cout << "Before sorting: ";
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it) << " ";
	}
	cout << endl;
	sort(v.begin(), v.end());
	cout << "After sorting: ";
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it) << " ";
	}

}

int main()
{
	test06();
	system("pause");
	return 0;
}