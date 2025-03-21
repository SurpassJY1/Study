#include<iostream>
using namespace std;
//函数模板
/*
template<typename T>
template 声明创建模板
typename表明其后面符号是一种数据类型，可以用class代替
T 通用的数据类型，名字可以替换，通常为大写

普通函数和函数模板的去呗：
普通函数调用时可以发生隐式类型转换
函数模板：
自动类型推导：不会发生隐式类型转换
显示指定类型：可以发生隐式类型转换
建议使用显示指定类型的方式
注意事项：
自动类型推导：必须要推导出一致的数据类型T才可以使用
			  模板必须要确定出T的数据类型，才可以使用

模板局限性：
模板并不是万能的，有些指定数据类型，需要用具体化方式做实现,如传入数组进行=操作
或者自定义数据类型
*/
template<typename T>//声明一个模板
void mySwap(T&a,T&b) 
{
	T temp = a;
	a = b;
	b = temp;
}

void test()
{
	int a = 10;
	int b= 20;
	double c= 0.1;
	double d = 0.2;
	//使用模板
	//第一种，自动类型推导
	mySwap(a,b);
	mySwap(c, d);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;
	cout << "d: " << d << endl;
	//第二种：显示指定类型
	mySwap<int>(a, b);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
}
void test02()
{
	int a = 10;
	char c = 'c';
	//mySwap(a, c);//错误，自动类型推到必须推导出一致的数据类型
}

template<typename T>
//模板必须要确定出T的数据类型才可以使用
void func()
{
	cout << "func called" << endl;
}
void test03()
{
	//func();错误，必须指定出T的数据类型
	func<int>();
}
int myAdd01(int a,int b) 
{
	return a + b;

}
template <class T>
T myAdd02(T a,T b) 
{
	return a + b;
}
void test04()
{
	int a = 10;
	char b = 'a';
	//cout<<myAdd(a, b);//不会发生隐式类型转换,无法推导出一致的数据类型
	cout << myAdd01(a, b);//发生隐式类型转换107
	cout << "-------------------" << endl;
	cout<<myAdd02<int>(a, b);//显式指定类型,输出107
}
//模板并不是万能的，有些指定数据类型，需要用具体化方式做实现, 如传入数组进行 = 操作
template<class T>
bool myCompare(T&a,T&b) 
{
	return a == b? true:false;
}
//创建自定义数据类型
class Person 
{
public:
	string m_Name;
	int m_Age;
	Person(string name, int age) :m_Name(name), m_Age(age) {}
	/*bool operator==(Person& p2) 
	{
		if (this->m_Name == p2.m_Name && this->m_Age == p2.m_Age)return true;
		return false;
	}*/
};
void test05() 
{
	int a = 10;
	int b = 10;
	bool ret= myCompare(a, b);
	if (ret)
	{
		cout << "a==b" << endl;
	}
	else 
	{
		cout << "a!=b" << endl;
	}
}
//解决方案2：利用具体化Person的版本实现代码，具体化会优先调用
//把T替换成Person，并且在前面用Template<>告诉编译器是模板重载代码
template<> bool myCompare(Person& a, Person& b) 
{
	if (a.m_Name == b.m_Name && a.m_Age == b.m_Age)return true;
	return false;
}

void test06() 
{
	Person p1("Jyz", 20);
	Person p2("Jyz", 20);
	//cout << myCompare(p1, p2) << endl;报错，模板的局限
	//解决方案1:对Person的==重载
	//解决方案2：利用具体化Person的版本实现代码，具体化会优先调用
	cout << myCompare(p1,p2) << endl;
}
int main()
{
	test06();
	return 0;
}