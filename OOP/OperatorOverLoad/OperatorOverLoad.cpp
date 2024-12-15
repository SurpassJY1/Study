#include<iostream>
using namespace std;
/*
运算符重载：
对已有的运算符进行重新定义，赋予其另一种功能，以适应不同的数据类型
注意事项
1.对于内置数据类型,表达式运算符不可以重载
2.不要滥用运算符重载
*/
//实现加号运算符重载
//1.成员函数重载加号
//2.全局函数重载加号

//实现左移运算符重载
class Person {
	friend	Person& operator+(Person& p1, Person& p2);
	friend	Person& operator+(Person& p1, int num);
	friend ostream& operator<<(ostream& cout, Person& p);
	friend void test();

private:
	int m_A;
	int m_B;
	//成员函数重载加号
		/*Person& operator+(Person& p)
		{
			Person temp;
			temp.m_A = p.m_A + this->m_A;
			temp.m_B = p.m_B + this->m_B;
			return temp;
		}*/
		//通常不会利用成员函数调用左移运算符，因为不能保证cout在左侧

};
//全局函数重载加号
Person& operator+(Person& p1, Person& p2)
{
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}
//符号重载也可以发生函数重载
Person& operator+(Person& p1, int num)
{
	Person temp;
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}
//只能利用全局函数重载左移运算符
//cout是标准输出流对象,只能有一个所以只能引用方式传递
ostream& operator<<(ostream& cout, Person& p)
{
	cout << "m_A " << p.m_A << " m_B" << p.m_B;
	return cout;
}

//重载加加运算符，使他能够添加自己的整形类
class MyInteger {
public:
	int m_Num;
	MyInteger(int num);
	//重载前置++运算符
	MyInteger& operator++() {
		m_Num++;
		return *this;
	}
	//重载前置--运算符
	MyInteger& operator--() 
	{
		m_Num--;
		return *this;
	}
	//重载后置--运算符
	MyInteger operator--(int)
	{
		MyInteger temp = *this;
		this->m_Num--;
		return temp;
	}
	//重载后置++运算符
	//int代表一个占位参数，可以用于区分前置和后置递增
	MyInteger operator++(int) 
	{
		//先返回结果，再进行递增
		MyInteger temp = *this;
		this->m_Num++;
		//必须值传递，因为temp是局部变量，在函数结束后会被释放，所以不能引用传递
		return temp;
	}
};
MyInteger::MyInteger(int num) {
	m_Num = num;
}

ostream& operator<<(ostream& cout,MyInteger myint) 
{
	cout << myint.m_Num;
	return cout;
}

void test2() {
	MyInteger myint(0);
	cout << ++myint << endl;
	cout << myint++ << endl;
	cout << myint << endl;
	cout << --myint << endl;
	cout << myint-- << endl;
	cout << myint << endl;
}
class Student {
	friend ostream& operator<<(ostream& cout, Student& stu);
private:
	int* m_Age;
public:
	Student(int age) :m_Age(new int(age)){}
	//写上自己的析构函数来删除堆区内存
	~Student() 
	{
		if (m_Age!=nullptr)
		{
			delete m_Age;
			m_Age = nullptr;
		}
	}
	//重载赋值符号
	Student& operator=(Student& stu) 
	{
	//判断本身m_Age有无记录值,有的话就删除
		if (m_Age!=nullptr)
		{
			delete m_Age;
			m_Age = nullptr;
		}
		m_Age = new int(*stu.m_Age);
		return *this;
	}
	Student& operator=(int age)
	{
		*m_Age = age;
		return *this;
	}
	//重载逻辑运算符
	bool operator==(Student& stu) 
	{
		if (*this->m_Age==*stu.m_Age)
		{
			return true;
		}
		return false;
	}
	bool operator!=(Student& stu) 
	{
		return *this->m_Age != *stu.m_Age;
	}
};
//重载Student类的<<符号
ostream& operator<<(ostream& cout,Student& stu) 
{
	cout << *stu.m_Age;
	return cout;
}

void test3() 
{
	Student stu1(18);
	Student stu2(19);
	cout << stu1 << endl;
	cout << stu2 << endl;
	cout << "-----------" << endl;
	Student stu3(20);
	stu2 = stu1;
	cout << stu2 << endl;//浅拷贝输出18,重写析构函数之后报错，原因是浅拷贝逐个字节的拷贝，
						 //导致stu2中m_Age的地址和stu1中的一样,导致重复释放
						 //因此我们要重写赋值符号重新开辟内存空间进行深拷贝
	stu3 = stu2 = stu1;
	cout << "Stu3: " << stu3 << " Stu2: " << stu2 << " Stu1: " << endl;
	if (stu3==stu2)
	{
		cout << "True" << endl;
	}
	stu2 = 30;
	if (stu3!=stu2)
	{
		cout << "False" << endl;
	}
}

//通过重载()符号实现仿函数,仿函数因为调用看起来像函数所以叫仿函数

class MyAdd 
{public:
	int operator()(int num1,int num2) 
	{
		return num1 + num2;
	}
};

void test4() 
{
//通过匿名对象调用仿函数,类名+（）就是一个匿名对象
	cout << MyAdd()(30, 30)<< endl;
}

void test() {
	Person p;
	p.m_A = 10;
	p.m_B = 10;
	Person p2;
	p2.m_A = 20;
	p2.m_B = 20;
	Person p3 = p + p2;
	Person p4 = p + 100;
	cout << p << endl;
}



int main()
{
	test4();
	return 0;
}