#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
/*
栈不允许遍历的行为
可以empty判断是否为空或
可以size看元素个数

构造函数：
stack<T> stk;
stack(const stack &stk);拷贝构造函数

赋值操作
stack& operator=(const stack &stk);重载等号操作符

数据存取
push(elem);向栈顶添加元素
pop();从栈顶移除第一个元素
top();返回栈顶元素

大小操作
empty();判断堆栈是否为空
size();返回栈的大小
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