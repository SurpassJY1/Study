#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>//��׼�㷨��ͷ�ļ�
using namespace std;
/*
deque�Ĺ��캯��
deque<T> deqT; Ĭ��
deque(beg,end) deqT; ����������
deque(n,elem); n��������
deque(const deque &deque) ��������

deque�ĸ�ֵ����
deque& operator=(const deque &deq);���صȺ�
assign(beg, end)��[beg,end)�����е����ݿ������Ƹ�����
assign(n,elem)n��elem��ֵ

deque�Ĵ�С����
deque.empty()�ж��Ƿ�Ϊ��
deque.size()����������Ԫ�ظ���
deque.resize(num)����ָ�������ĳ���Ϊnum
deque.resize(num,elem)����ָ����������Ϊnum���������䳤����elem���

deque�Ĳ����ɾ��
���˲������
push_back(elem) ������β�����һ������
push_front(elem) ������ͷ������һ������
pop_back(); ɾ���������һ������
pop_front(); ɾ��������һ������

ָ��λ�ò���
insert(pos,elem); ��posλ�ò���һ��elemԪ�صĿ���,���������ݵ�λ��
insert(pos,n,elem); ��posλ�ò���n��elem���ݣ��޷���ֵ
insert(pos,beg,end); ��posλ�ò���[beg,end)��������ݣ��޷���ֵ
clear(); ������������е�����
erase(beg,end); ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ��
erase(pos);ɾ��posλ�õ����ݣ�������һ�����ݵ�λ��

deque�����ݴ�ȡ����
at(int index)�� ��������idx��ָ������
operator[]�� ��������idx��ָ������
front()�����������еĵ�һ��Ԫ��
back()�����������е����һ��Ԫ��

deque������
sort(iterator beg,iterator end)
��beg��end�����ڵ�Ԫ�ؽ�������
����֧��������ʵĵ�������������������sort�㷨ֱ�Ӷ����������
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
	//���˲���
	deque<int> d1;
	//β��
	for (size_t i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	deque<int> d2;
	for (size_t i = 0; i < 10; i++)
	{
		d2.push_front(i);
	}
	cout << "d1��" << endl;
	printDeq(d1);
	cout << "d2��" << endl;
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
	//����֧��������ʵĵ�������������������sort�㷨ֱ�Ӷ����������
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