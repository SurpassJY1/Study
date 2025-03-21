#include<iostream>
#include<string>
using namespace std;

/*
string和 char* 的区别
char*是一个指针
string是一个了类，类内部封装了char*，管理这个字符串，是一个char*容器
特点：
string内部封装了很多成员方法
find
copy
delete
replace
insert

string的构造函数
string()
string(const char* s)
string(const string& s)
string(int n,char c)
字符串拼接
+=操作符号
append(const string& s,int pos,int )
查找和替换
find(string s,int start);
rfind(string s,int start);
找到了返回下标，没找到返回-1，rfind和find的区别是rfind从右往左找
替换
replace(int pos,int n,const string& str)从pos开始n个字符为str
*/
//string的构造函数
void test01()
{
	string s1;
	const char* str = "Hello world";
	string s2(str);
	cout << s2 << endl;
	string s3 (s2);
	cout << s3 << endl;
	string s4(10,'a');
	cout << s4 << endl;
}
//string的赋值操作
void test02()
{
	string str1;
	str1 = "Hello world";
	cout << str1 << endl;
	string str2 = str1;
	cout <<"str2: "<< str2 << endl;
	string str3 ;
	str3 = 'a';
	cout << str3 << endl;
	string str4;
	str4.assign("Hello assign");
	cout << "str4 " << str4 << endl;
	string str5;
	//获取前五个字符
	str5.assign("Hello c++",5);
	cout << "str5: " << str5 << endl;
	string str6;
	str6.assign(10,'p');
	cout << "str6 " << str6 << endl;
}
//字符串拼接
void test03()
{
	string str1 = "我";
	str1 += "操死你妈";
	cout << str1 << endl;
	str1 += ':';
	cout << str1 << endl;
	string str2 = ",射在她脸上";
	str1 += str2;
	cout << str1;
}
//字符串拼接 append
void test04()
{
	string str1 = "I";
	str1.append(" Love ");
	str1.append("You are a SB",0,3);//参数2是截取的字符串起始位置，参数3是截取的字符个数
	cout << str1;
}
//查找
void test05()
{
	string str1 = "abcde";
	int pos = str1.find("bc");
	int pos2 = str1.find("n");//-1
	cout << pos<<endl;
	cout << pos2 << endl;
	pos = str1.rfind("bc");
	pos2 = str1.rfind("n");//-1
	cout << pos << endl;
	cout << pos2 << endl;
	//find和rfind的区别，find是从左往右找，rfind是从右往左找
}
//替换
void test06()
{
	string str1 = "abcdefg";
	//从1号位子起，3个字符替换为1111
	str1.replace(1, 3, "1111");
	cout << str1 << endl;
}
int main()
{
	test02();
	return 0;
}