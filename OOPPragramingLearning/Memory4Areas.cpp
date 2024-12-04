#include<iostream>
using namespace std;
int* func();
int* createArr(int i);

int g_a = 10;
int g_b = 10;

int main()
{
	/*
	代码区：存放二进制代码，由操作系统管理
	全局区：存放全局变量和静态变量以及常量
	栈区：由编译器自动分配释放，存放函数的参数值局部变量等
	堆区：由程序员分配和释放，若程序元不释放，程序结束时由操作系统回收

	代码区全局区在程序运行前划分
	代码区共享，只读
	对于频繁执行的程序，内存中有一份代码就行
	防止程序意外的修改了机器指令

	全局区：该区域的数据在程序结束后由操作系统释放

	栈区存放函数参数和局部变量
	栈区由编译器管理开辟和释放
	注意事项：
	不要反回局部变量的地址

	堆区：由程序员分配释放，程序结束时由操作系统回收
	用new关键字手动开辟
	用delete进行手动释放
	*/
	int* p = func();
	//手动释放
	//delete p;
	 cout<<*p;
	 cout << "我疯狂拖时间" << endl;
	 cout << "我疯狂拖时间" << endl;
	 cout << "我疯狂拖时间" << endl;
	 cout << "我疯狂拖时间" << endl;
	 cout << "我疯狂拖时间" << endl;
	 cout << "我疯狂拖时间" << endl;
	 cout << "我疯狂拖时间" << endl;
	 cout << "我疯狂拖时间" << endl;
	 cout << "我疯狂拖时间" << endl;
	 cout << "我疯狂拖时间" << endl;
	 cout << "我疯狂拖时间" << endl;
	 cout << "我疯狂拖时间" << endl;
	 cout << "我疯狂拖时间" << endl;
	 cout << "我疯狂拖时间" << endl;
	 cout << "我疯狂拖时间" << endl;
	 cout << "我疯狂拖时间" << endl;
	 int *arr=createArr(10);//因为在堆区，所以返回出函数也不会自动消失
	 for (size_t i = 0; i < 10; i++)
	 {
		 cout << arr[i];
	 }
	 delete[]arr;//释放整个数组要在前面加个中括号不然就只释放了第一个元素
	 
	 return 0;
}

int* createArr(int i)
{
	int* arr = new int[i];
	for (size_t j = 0; j < i; j++)
	{
		arr[j] = 0;
	}
	for (size_t j = 0; j < i; j++)
	{
		cout << arr[j];
	}
	return arr;
}
int* func()
{
//用new关键字可以将数据开辟到堆区
	int* p = new int(10);//指针本质也是局部变量，放在栈上，指针保存的数据存放在堆区
		return p;
}
//用来测试全局区
void globalArea()
{
	int a = 10;
	int b = 10;
	static int s_a = 10;
	static int s_b = 10;
	const int c_l_a = 10;
	const int c_l_b = 10;
	string str = "a";//不是字符串常量
	string  str2 = "b";
	cout << (int)&a << endl;
	cout << (int)&b << endl;
	cout << (int)&g_a << endl;
	cout << (int)&g_b << endl;
	cout << (int)&s_a << endl;
	cout << (int)&s_b << endl;
	cout << (int)&"1" << endl;
	cout << (int)&"2" << endl;
	cout << (int)&c_l_a << endl;
	cout << (int)&c_l_b << endl;
	cout << (int)&str << endl;
	cout << (int)&str2 << endl;
	//局部变量局部常量都不在全局区
	//全局变量静态变量常量(const修饰的全局常量以及字符串常量)在全局区中
}