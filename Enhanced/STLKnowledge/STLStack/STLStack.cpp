#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
/*
ջ�������������Ϊ
����empty�ж��Ƿ�Ϊ�ջ�
����size��Ԫ�ظ���

���캯����
stack<T> stk;
stack(const stack &stk);�������캯��

��ֵ����
stack& operator=(const stack &stk);���صȺŲ�����

���ݴ�ȡ
push(elem);��ջ�����Ԫ��
pop();��ջ���Ƴ���һ��Ԫ��
top();����ջ��Ԫ��

��С����
empty();�ж϶�ջ�Ƿ�Ϊ��
size();����ջ�Ĵ�С
*/
void test01()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	cout << "Size of stack: " << s.size() << endl;

	while (!s.empty()) 
	{
		cout << "Top: " << s.top() << " ";
		s.pop();
	}
	cout << endl;
	cout << "Size of stack: " << s.size() << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}