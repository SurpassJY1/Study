#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
�㷨��Ҫ��ͷ�ļ�<algorithm><functional><numeric>���
algorithm������STLͷ�ļ�����һ��,��Χ�漰�ȽϽ��������ң��������������ƣ��޸ĵ�
numeric�����С��ֻ��������������������м����������ģ�庯��
functional������һЩģ���࣬����������������

����Ԫ��
find
find_if����������
adjacent_find���������ظ�Ԫ��
binary_search���ֲ���
countͳ��Ԫ�ظ���
count_if������ͳ��Ԫ�ظ���
*/
//���õı����㷨�е�for_each
void print01(int val)
{
	cout << val << " ";
}
class print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test01()
{
	vector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//�����������������������䷶Χ���в����ĺ��������ߺ�������
	//��ͨ������
	for_each(v.begin(), v.end(), print01);
	cout << endl;
	//����������������
	for_each(v.begin(), v.end(), print02());

}
//������������ĺ�������
class trans
{
public:
	int operator()(int val)
	{
		return val;
	}
};
//transform
//������������һ��������,ԭ���������ݱ���
//transform(iterator beg1,iterator end1,iterator beg2, func)
//beg1 ԭ������ʼ end1 ԭ�������� beg2Ŀ��������ʼ func�Ǻ���ԭ�ͻ��ߺ�������
void test02()
{
	vector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int> vTarget;
	//��ǰ��Ŀ���������ٿռ䣬��Ȼ�ᱨ��
	vTarget.resize(v.size());
	transform(v.begin(), v.end(), vTarget.begin(), trans());
	//for_each(v.begin(),v.end(),print02());
	cout << endl;
	for_each(vTarget.begin(), vTarget.end(), print02());
}
//find(iterator beg,iterator end, value)
//��ֵ����Ԫ�أ��ҵ����ظ�Ԫ�ص�������û�ҵ�����end������
//����������������
void test03()
{
	vector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//���������Ƿ���5
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end())cout << "Not found" << endl;
	else cout << (*it) << endl;
}
//find���Զ�����������
class Person
{
public:
	string name;
	int age;
	Person(string name, int age) :name(name), age(age) {}
};
bool operator==(const Person& p1, const Person& p2)
{
	return p1.age == p2.age;
}

class GreaterFive
{
public:
	bool operator()(int val1)
	{
		return val1 > 5;
	}
};

void test04()
{
	Person p1("zjy", 18);
	Person p2("yzl", 19);
	Person p3("wyk", 11);
	Person p4("zjc", 12);
	vector<Person> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	//��find�������Զ�����������Ҫ�����Զ�����������==����Ϊfind�����ڲ���==�űȽ�
	vector<Person>::iterator it = find(v.begin(), v.end(), p1);
	if (it != v.end())cout << (*it).name << " Age: " << (*it).age << endl;
	else cout << "Not found" << endl;
}
//find_if(iterator beg,iterator end,_pred)
//��pred����Ԫ�أ��ҵ��򷵻ص��������Ҳ����򷵻�endλ�õĵ�����
//_pred:��������ν��
//find_if����������������
void test05()
{
	vector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//���Ҵ������Ԫ��
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end())
	{
		cout << "Not found" << endl;
	}
	else
	{
		cout << "�ҵ���" << *it << endl;
	}
}
//���Զ������������
class FindPerson
{
public:
	bool operator()(Person& p)
	{
		return p.age > 20;
	}
};
void test06()
{
	Person p1("zjy", 21.2);
	Person p2("yzl", 19);
	Person p3("wyk", 11);
	Person p4("zjc", 12);
	vector<Person> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	//���������20����
	vector<Person>::iterator it = find_if(v.begin(), v.end(), FindPerson());
	if (it == v.end())cout << "Not found" << endl;
	else cout << (*it).name << " Age: " << (*it).age << endl;
}
//adjacent_find(beg,end)
//���������ظ�Ԫ�أ���������Ԫ�صĵ�һ��λ�õ�����
//û�ҵ�����end������
void test07()
{
	vector<int>v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);
	v.push_back(3);
	v.push_back(0);
	v.push_back(4);
	v.push_back(1);
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end())cout << "Not found" << endl;
	else cout << *it << endl;
}
//binary_search
//bool binary_search(beg,end,value)
//�����������в����ã�����true��false
//���ҵ�Ԫ�ر���Ϊ��������
void test08()
{
	vector<int> v;
	for (int i = 0;i < 10; i++)
	{
		v.push_back(i);
	}
	bool ret = binary_search(v.begin(), v.end(), 5);
	if (ret == true) { cout << "Found it" << endl; }
	else cout << "Not found" << endl;
}
//count(beg,end,value)
//����Ԫ�س��ִ���
//ͳ��������������
void test09()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(40);
	v.push_back(10);
	int num=count(v.begin(),v.end(),40);
	cout << "40 ���ֵĴ���Ϊ��" << num << endl;
}
//ͳ���Զ�����������
void test10() 
{
	vector<Person> v;
	Person p1("Zjy",20);
	Person p2("Zjy",10);
	Person p3("Zjy",10);
	Person p4("Zjy",10);
	Person p5("Zjy",40);
	Person p6("Wyk",40);
	Person p7("Jyz",40);
	Person p("Jyz",40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);
	v.push_back(p7);
	int num = count(v.begin(),v.end(),p);
	cout << num << endl;

}
//count_if(beg,end,_pred)
//ͳ�Ʒ���ν��_pred��Ԫ�صĸ���
//count_if������������
void test11()
{
	vector<int>v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	int num = count_if(v.begin(),v.end(),GreaterFive());
	cout << num << endl;
}

//count_ifͳ���Զ�����������
void test12()
{
	Person p1("zjy", 21.2);
	Person p2("yzl", 19);
	Person p3("wyk", 11);
	Person p4("zjc", 12);
	vector<Person> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	int num = count_if(v.begin(),v.end(),FindPerson());
	cout << num << endl;
}
int main()
{
	test12();
	return 0;
}