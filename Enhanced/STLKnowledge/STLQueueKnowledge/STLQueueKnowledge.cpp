#include<queue>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class Person 
{
public:
	string m_Name;
	int m_Age;
	Person(string name, int age) :m_Name(name), m_Age(age) {}
};

void test01()
{
	queue<Person>q;
	Person p1("xwmr",16);
	Person p2("zz",16);
	Person p3("qszj",31);
	Person p4("zjy",18);
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	queue<Person>q2;
	q2.push(Person("gh", 21));
	q2.push(Person("yzl", 21));
	q2.push(Person("zjy", 21));
	q2.push(Person("xrj", 21));
	q.swap(q2);
	cout << "The size of queue: " << q.size() << endl;;
	while (!q.empty())
	{
		cout << q.front().m_Name << " " << q.front().m_Age << endl;
		q.pop();
	}
	cout << "The size of queue: " << q.size();
}

int main()
{
	test01();
	return 0;
}