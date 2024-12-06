#include<iostream>
using namespace std;
int& referReturn();
void show(const int& val);
int main()
{ 
	/*
	格式：
	数据类型 &别名=原名;
	注意事项：
	引用必须初始化
	int&b;是不允许的
	引用一旦初始化后就不可以改变了
	引用的本质是指针常量
	*/
	int a = 10;
	int c = 20;
	int& b = a;
	b = c;//不是更改引用，是赋值操作
	a = 30;
	cout << a << endl;
	cout << b << endl;
	swap(a, c);
	cout << "a: " << a << endl;
	cout << "c: " << c << endl;
	int&ref = referReturn();
	cout << "ref: " << ref << endl;
	cout << "ref: " << ref << endl;
	//如果函数返回值是引用，函数调用可以为左值
	referReturn() = 100000;
	cout << "ref: " << ref << endl;
	show(c);
	return 0;
} 

//利用引用做函数参数,简化指针操作
void swap(int&a,int&b)
{
	int temp = a;
	a = b;
	b = temp;
}
//利用引用做函数返回值
//注意：不要返回局部变量的引用
//用法：函数调用为左值
int& referReturn()
{
	//int ref = 10;存放在栈区
	static int ref = 10;//存放在全局区
	return ref;
}
//常量引用：
//常量引用常被用来修饰形参来防止误操作
void show(const int& val)
{
	cout << val << endl;
}