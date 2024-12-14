#include<iostream>
using namespace std;
/*
在cpp中空指针也可以访问成员函数，但要注意有没有用到this
指针
*/
class Person {
public:
	void showClassName() 
	{
		cout << "this is person class" << endl;
	}
	int m_Age;
	void showAge() {
		//报错原因是传入的指针为空，空指针还想调用成员
		//加这一行增加健壮性
		if (this==nullptr)
		{
			return;
		}
		cout << "Age: " << m_Age << endl;
	}
};
int main()
{
	Person* p = nullptr;
	p->showClassName();
	//报错p->showAge();
	//因为在类属性的前面都默认有个this->m_Age
	p->m_Age();
	return 0;
}