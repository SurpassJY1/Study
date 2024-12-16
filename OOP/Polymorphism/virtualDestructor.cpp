#include<iostream>
using namespace std;
/*
多态使用时，如果子类有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
解决方式：将父类中的析构函数改为虚析构或者纯虚析构
虚析构和纯虚析构的共性：
都可以解决父类指针释放子类对象
都需要具体的函数实现
虚析构和纯虚析构的区别：
如果是纯虚析构，该类属于抽象类，无法实例化对象

总结：
虚析构和纯虚析构都是用来解决父类指针释放子类对象中开辟到堆区的属性的问题
如果子类中没有数据开辟到堆区，可以不写虚析构或者纯虚析构
如果一个类写了纯虚析构，那么这个类属于抽象类，无法实例化对象
*/
class Human 
{
public:
	//纯虚函数
	virtual void speak() = 0;
	//构造函数和析构函数
	Human() { cout << "Constructor called" << endl; }
	//利用虚析构解决父类指针释放子类对象的时候释放不干净的问题
	//virtual ~Human() { cout << "Destructor called" << endl; }
	
	//纯虚析构：
	//写了纯虚析构这个类属于抽象类，无法实例化
	virtual ~Human() = 0;//报错，需要一个具体的函数实现,
						//因为本类当中也有可能有成员开辟在堆区；在类外实现
};
//纯虚析构的函数外实现
Human::~Human() 
{
	cout << "Destructor called" << endl;
}
class Student :public Human 
{
public:
	string* m_Name;
	void speak() {
		cout << *m_Name<<" speaks" << endl;
	}
	Student(string name):m_Name(new string(name)) {
		cout << "Constructor called" << endl;
	}
	//用析构函数删除堆区成员属性
	~Student()
	{
		cout << "Destructor called" << endl;
		delete m_Name;
		m_Name = nullptr;
	}
};
void test() 
{
	Human* human = new Student("Tom");
	human->speak();
	delete human;//可以发现没有调用Student类的析构函数
	//原因：父类指针在析构的时候没有调用子类的析构函数造成了内存的泄露
	//解决方法：利用虚析构
}
int main()
{
	test();
	return 0;
}