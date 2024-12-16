#include<iostream>
using namespace std;

class Calculator 
{
public:
	int num1;
	int num2;
	int getResult(string oper) {
		if (oper=="+")
		{
			return num1 + num2;
		}
		else if (oper == "-") 
		{
			return num1 - num2;
		}
		else if (oper=="*")
		{
			return num1 * num2;
		}
		else if (oper == "/") 
		{
			return num1 / num2;
		}
		return -1;
	}
};
/*
如果想扩展新的功能，需要修改源码
在真实的开发中，提倡开闭原则
开闭原则：对扩展进行开放，多修改进行关闭
*/
//利用多态实现计算器
class AbstractCalculator
{
public:
	int m_Num1;
	int m_Num2;
	//纯虚函数
	//一个类中只要有一个纯虚函数，那么他就是抽象类
	//抽象类的特点：
	//无法实例化对象
	//子类必须重写所有的纯虚函数
	virtual int getResult() = 0;

};
//加法计算器
class AddCalculator :public AbstractCalculator
{
public:
	int getResult() 
	{
		return m_Num1 + m_Num2;
	}
};
//减法
class SubCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};
//乘法
class MultiCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 * m_Num2;
	}
};
void test01() 
{
	Calculator c;
	c.num1 = 10;
	c.num2 = 5;
	cout << c.getResult("/") << endl;
	cout << c.getResult("*") << endl;
	cout << c.getResult("+") << endl;
	cout << c.getResult("-") << endl;
}
void test02()
{
	//父类指针或者引用指向子类对象
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 10;
	cout << abc->getResult()<<endl;
//开辟在堆区的数据用完后记得销毁
	delete abc;
	abc = new SubCalculator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 1000;
	cout << abc->getResult() << endl;
}
class Son :public AbstractCalculator 
{
public:
	int getResult() {
		return 0;
	}
};
void test03() 
{
	//AbstractCalculator abs;栈上无法实例化对象
	//new AbstractCalculator;堆区无法实例化对象
	//Son s;子类没有重写父类中的纯虚函数无法实例化对象
	//new Son;
	Son sl;//重写父类中的纯虚函数之后就可以实例化对象了
}
