#include<iostream>
#include<algorithm>
#include<list>
using namespace std;
/*
��ʽ�洢
����洢��Ԫ�Ϸ�����
��һϵ�нڵ㹹��
�ڵ����ɣ�һ���Ǵ洢����Ԫ�ص���������һ���洢��һ���ڵ��ָ����
STL�е�������һ��˫��ѭ������

�ŵ㣺
��ȡ��̬�洢���䣬��������ڴ���˷Ѻ��Ƴ�
���Զ�����λ�ý��п��ٵĲ������ɾ��Ԫ�أ������ƶ�����Ԫ��
ȱ�㣺
���������ı����ٶ�û�������
ռ�õĿռ������Ҫ��

�����뽻��
assign(beg,end);��[beg��end)�����е����ݿ�����ֵ������
assign(n,elem);��n��elem�������Ƹ�����
list& operator=(const list& list);���صȺŲ�����
swap(list);��list�뱾���Ԫ�ػ���

������ȡ
front����
back����
û�������ź�at����
��Ϊ��֧���������

list�ķ�ת������
reverse();
sort();
��Ҫʹ��Ĭ�����򷽷����ı䷽ʽ��ĳɴ�С����
��myCompare�ŵ�Ĭ�����򷽷�����
bool myCompare(int v1,int v2)
{
//ʹ��һ�������ڵڶ�����
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
//��֤��������֧���������
	list<int>::iterator it = l.begin();
	it++;
	it--;//֧��˫��
	//it = it + 1;��֧���������
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
	//��֧��������ʵ����������ڲ����ṩ��Ӧ��һЩ�㷨
	//���в�֧��������ʵ���������������ʹ�ñ�׼�㷨
	//Ĭ�ϴ�С��������

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