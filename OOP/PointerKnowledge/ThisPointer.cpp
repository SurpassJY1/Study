#include<iostream>
using namespace std;
/*
解决名称冲突
返回对象本身用*this
*/
class Person {
	public:
		int age;
		Person(int age){
		//名称冲突age = age;
			//this指针指向被调用的成员函数所属于的对象
			this->age = age;
		}
		//void addAge(Person& p) {
		//一定要返回引用,因为值传递返回会复制一个新的数据,每次返回都调用拷贝构造函数返回一个新对象
		Person& addAge(Person& p){
			this->age += p.age;
			//返回本身
			return *this;
		}
};
//解决名称冲突
void test01() {
	Person p(18);
	cout << "Age: " << p.age << endl;
}
//返回对象本身
void test02(){
	Person p(10);
	Person p2(10);
	//p2.addAge(p);
	p2.addAge(p).addAge(p).addAge(p).addAge(p).addAge(p);
	//如果我们想要多次追加操作就要更改addAge
	cout << "Age: " << p2.age << endl;
}
