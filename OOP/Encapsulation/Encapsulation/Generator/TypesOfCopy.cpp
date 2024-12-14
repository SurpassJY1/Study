#include<iostream>
using namespace std;

/*
深拷贝与浅拷贝

浅拷贝：简单的赋值拷贝操作,问题：堆区的内存重复释放

深拷贝：在堆区重新申请一块内存空间进行赋值操作
*/
class Person {

public:

	Person() {}
	Person(int age,int height) {
		this->m_Age = age;
		this->height = new int(height);
		cout << "有参构造" << endl;
	}
	Person(const Person &p) {
		cout << "拷贝构造调用" << endl;
		m_Age = p.m_Age;
		//深拷贝操作
		height = new int(*p.height);
	}

	int m_Age;
	//将堆区开辟的数据在析构函数手动释放
	int* height;
	~Person() {
		if (height!=nullptr)
		{
			delete height;
			height = nullptr;
		}
		cout << "析构函数" << endl;
	}
};
void test()
{
	Person p1(18,180);
	cout << "p1 " << p1.m_Age<<"height: "<<*p1.height << endl;
	Person p2 = p1;
	cout << "p2 " << p2.m_Age <<"height: "<<*p2.height << endl;
}
int main()
{
	test();
	return 0;
}