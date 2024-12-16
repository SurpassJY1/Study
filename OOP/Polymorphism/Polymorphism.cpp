#include<iostream>
using namespace std;
/*
静态多态：函数重载，运算符重载，复用函数名
动态多态：派生类和虚函数实现运行时多态
区别：
静态多态的函数地址早绑定：编译阶段确定函数地址
动态多态函数地址晚绑定，运行时确定函数地址

动态多态满足条件：
	1.有继承关系
	2.子类重写的虚函数
动态多态的使用：
	父类引用指向子类对象
*/
class Animal
{
public:
	virtual void speak()
	{
		cout << "Animal is speaking" << endl;
	}
};

class Cat : public Animal
{
public:
	void speak() {
		cout << "Cat is speaking" << endl;
	}
};
//执行说话的函数
//地址早绑定，在编译阶段确定函数地址，输出Animal is speaking
//如果执行猫在说话,就要晚绑定,在父类的speak函数前加上一个virtual
void doSpeak(Animal& animal) //Animal &animal=cat;
{
	animal.speak();
}

void test() 
{
	cout << "Size of Animal " << sizeof(Animal) << endl;//无virtual是1，有virtual是8，里面有个指针
	cout << "Size of Cat " << sizeof(Cat) << endl;													//vfptr：vitrual function pointer
														//指针指向虚函数表vftable
														//vftable会记录虚函数地址，当子类重写了父类的虚函数。
														// 子类内部的虚函数表会替换成子类的虚函数地址
														//当父类指针或者引用指向子类对象的时候发生多态
}
