#include<iostream>
using namespace std;
/*
������Ƴ�ͻ
���ض�������*this
*/
class Person {
	public:
		int age;
		Person(int age){
		//���Ƴ�ͻage = age;
			//thisָ��ָ�򱻵��õĳ�Ա���������ڵĶ���
			this->age = age;
		}
		//void addAge(Person& p) {
		//һ��Ҫ��������,��Ϊֵ���ݷ��ػḴ��һ���µ�����,ÿ�η��ض����ÿ������캯������һ���¶���
		Person& addAge(Person& p){
			this->age += p.age;
			//���ر���
			return *this;
		}
};
//������Ƴ�ͻ
void test01() {
	Person p(18);
	cout << "Age: " << p.age << endl;
}
//���ض�����
void test02(){
	Person p(10);
	Person p2(10);
	//p2.addAge(p);
	p2.addAge(p).addAge(p).addAge(p).addAge(p).addAge(p);
	//���������Ҫ���׷�Ӳ�����Ҫ����addAge
	cout << "Age: " << p2.age << endl;
}
