#include<iostream>
using namespace std;

//函数默认参数

//如果自己传入数据就用自己的数据，如果没有，那么用默认值
int func(int a,int b=20, int c=30)
{
	return a + b + c;
}

//如果某个位置已经有默认参数，那么这个位置往后从左到右都必须有默认值
/*错误案例
int func(int a,int b=10.int c)
{
return a+b+c;
}
*/
//如果函数声明有默认参数，函数实现就不能有默认参数
//声明和实现当中只能由一个有默认参数

//占位参数
// 语法，形参只写一个数据类型
//占位参数还可以有默认参数

//函数重载
//作用：函数名可以胸痛，提高复用性
// 函数重载的条件：
//同一作用域下
//函数名称相同
//函数参数类型不同，或者个数不同，或者顺序不同
//注意，函数返回值是不满足重载条件的
//注意事项：
// 引用作为函数重载条件
// 函数重载碰到默认参数
//

void overloadFunc() {
	cout << "overloadFunc use" << endl;
}



void overloadFunc(int a,double b) {
	cout << "overloadFunc(int a,double b) use!" << endl;
}

void overloadFunc(double b,int a) {
	cout << "double b,int a" << endl;
}

void overloadFunc(int&a) {
	cout << "overloadFunc(int&a) used" << endl;
}

//函数重载碰到默认参数我输入overloadFucn(a)可调用上面的那个也可以调用下面的，不知道调用哪个
// void overloadFunc(int&a, int b=10) {
//	cout << "overloadFunc(int&a, int b=10) used" << endl;
//}

void overloadFunc(const int& a) {
	cout << "overloadFunc(const int&a) used" << endl;
}


void func2(int a, int=10)
{
	cout << "this is a function" << endl;
}
int main()
{
	int a = 1;
	overloadFunc(a);//overloadFunc(int&a) used  引用引用合法的内存空间,栈区或堆区， int &a=1 指向常量区不合法
	overloadFunc(1);//overloadFunc(const int&a) used
	overloadFunc();
	overloadFunc(1, 1.1);
	overloadFunc(1.1, 1);

}