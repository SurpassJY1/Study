#include<iostream>
#include<algorithm>
#include<list>
using namespace std;
/*
链式存储
物理存储单元上非连续
有一系列节点构成
节点的组成：一个是存储数据元素的数据域另一个存储下一个节点的指针域
STL中的链表是一个双向循环链表

优点：
采取动态存储分配，不会造成内存的浪费和移除
可以对任意位置进行快速的插入或者删除元素，不用移动大量元素
缺点：
对于容器的遍历速度没有数组快
占用的空间比数组要大

复制与交换
assign(beg,end);将[beg，end)区间中的数据拷贝赋值给本身
assign(n,elem);将n个elem拷贝复制给本身
list& operator=(const list& list);重载等号操作符
swap(list);将list与本身的元素互换

函数存取
front（）
back（）
没有中括号和at访问
因为不支持随机访问

list的反转和排序
reverse();
sort();
想要使用默认排序方法并改变方式如改成从小到大
把myCompare放到默认排序方法里面
bool myCompare(int v1,int v2)
{
//使第一个数大于第二个数
return v1>v2;
}
*/
bool myCompare(int v1,int v2)
{
	return v1 > v2;
}
void printList(const list<int> l)
{
	for (list<int>::const_iterator it = l.begin();it != l.end(); it++)
	{
		cout << (*it) << " ";
	}
	cout << endl;
}
void test01()
{
	list<int>l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	printList(l1);
	list<int>l2(l1.begin(), l1.end());
	cout << "L2: " << endl;
	printList(l2);
	list<int>l3(l1);
	cout << "L3: " << endl;
	printList(l3);
	list<int>l4(10, 1000);
	cout << "l4: " << endl;
	printList(l4);
}
void test02()
{
	list<int>l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	list<int>l2;
	l2.assign(l1.begin(), l1.end());
	printList(l2);
	list<int>l3;
	l3.assign(6, 6);
	printList(l3);
	list<int>l4;
	l4.push_back(2);
	l4.push_back(3);
	l4.push_back(4);
	l4.push_back(5);
	printList(l4);
	l4 = l1;
	printList(l4);
	l4.swap(l3);
	printList(l4);

}
void test03()
{
	list<int>l1;
	if (l1.empty())cout << "l1 is empty";
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	if (!l1.empty()) {
		cout << "l1 is not empty" << endl;
		cout << "The size of l1 is " << l1.size() << endl;
	}
	l1.resize(10);
	cout << "The size of l1 after resizing is " << l1.size() << endl;
	printList(l1);
	l1.resize(15, 10000);
	printList(l1);
}
void test04()
{
	list<int>l;
	l.push_back(1);
	l.push_back(2);
	l.push_front(4);
	l.push_front(3);
	cout << "l " << endl;
	printList(l);
	l.pop_back();
	l.pop_front();
	cout << "l after poping ";
	printList(l);
	l.insert(l.begin(), 1);
	printList(l);
	l.insert(l.begin(), 2, 6);
	printList(l);
	list<int>l2;
	l2.insert(l2.begin(), l.begin(), l.end());
	cout << "L2: " << endl;
	printList(l2);
	l2.erase(l2.begin());
	printList(l2);
	l2.remove(4);
	printList(l2);
}
void test05()
{
	list<int>l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	cout << "front: " << l.front() << endl;
	cout << "back: " << l.back() << endl;
//验证迭代器不支持随机访问
	list<int>::iterator it = l.begin();
	it++;
	it--;//支持双向
	//it = it + 1;不支持随机访问
}
void test06()
{
	list<int>list;
	list.push_back(2);
	list.push_back(1);
	list.push_back(5);
	list.push_back(4);
	list.push_back(3);
	printList(list);
	//不支持随机访问迭代器容器内部会提供对应的一些算法
	//所有不支持随机访问迭代器容器不可以使用标准算法
	//默认从小到大排序

	list.sort();
	printList(list);
	list.sort(myCompare);
	printList(list);
	list.reverse();
	printList(list);

}
int main()
{
	test06();
	system("pause");
	return 0;
}