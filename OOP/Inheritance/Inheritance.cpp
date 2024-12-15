#include<iostream>

using namespace std;

class Base 
{
public:
	int pub_Num;
	//静态成员特点
	//编译阶段分配内存
	//类内声明类外初始化
	//所有对象共享同一份数据
	static int s_A;
	Base()
	{
		//cout << "Base constructor called" << endl;
		pub_Num = 50;
	}
	~Base()
	{
		//cout << "Base destructor called" << endl;
	}
	void func(int para) 
	{
		cout << "This is func of Base" << endl;
	}
	void func()
	{
		cout << "This is func of Base" << endl;
	}
	//父类静态成员函数
	//静态成员函数特点：
	//只能访问静态成员属性
	//所有对象共享一份方法实力
	static void sFunc() 
	{
		cout << "Base static func called" << endl;
	}
private:
	int pri_Num;
protected:
	int pro_Num;
};

int Base::s_A = 100;

class Derived :public Base
{
public:
	int d_Num;
	int pub_Num;
	static int s_A;
	//This method is used to determine the routine of Base and Derived
	Derived() 
	{
		pub_Num = 100;
		 d_Num = 1;
		//cout << "Derived constructor called" << endl;
	}
	~Derived() 
	{
		//cout << "Derived destructor called" << endl;
	}
	void func()
	{
		cout << "This is func of Derived" << endl;
	}
	//子类静态成员函数
	static void sFunc() 
	{
		cout << "Derived static func called" << endl;
	}
};
int Derived::s_A = 200;
//同名静态函数
void test02() 
{//通过对象访问
	Derived d;
	d.sFunc();//子类的
	d.Base::sFunc();//父类的
	//通过类名访问
	Derived::sFunc();
	//子类出现和父类同名的静态成员函数,也会隐藏父类中所有同名成员函数
	//如果想访问父类中所有隐藏同名成员函数需加上作用域
	Derived::Base::sFunc();
}
//同名静态成员属性
void test01() 
{
	Derived d;
	//通过对象访问
	cout << d.s_A << endl;//200
	cout << d.Base::s_A << endl;//100
	//通过类名访问
	cout << Derived::s_A << endl;//200
	//第一个::表示通过类名访问静态成员，第二个::表示是Base类下的静态成员
	cout << Derived::Base::s_A << endl;//100
}
void test()
{
	Derived d;
	//子类父类中的同名成员变量默认调用子类，调用父类在变量名前加上作用域
	cout << d.pub_Num << endl;//200
	cout << d.Base::pub_Num << endl;//50
	//同理调用父类同名成员函数也需要加作用域,包括重载的函数，因为子类会隐去父类所有同名成员函数
	d.func();//this is func of derived
	d.Base::func(11);//this is func of base
	d.Base::func();//this is func of base
}
//多继承语法
//class 子类：继承方式 父类1，继承方式：父类2...
//多继承可能会引发父类中有同名成员出现，所以需要加上作用域进行区分
//int main()
//{
//	//即使是父类中访问不到的变量也全都再子类当中
//	//cout << "Size of Derived: " << sizeof(Derived) << endl;
//	//Derived der;//Base constructor
//				//Derived constructor
//				//Derived destructor
//				//Base destructor
//
//	return 0;
//}