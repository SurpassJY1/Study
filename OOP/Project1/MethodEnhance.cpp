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

int main()
{
	cout << func(10,30);
}