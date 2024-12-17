#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
/*
用二进制的方式对文件进行读写操作
二进制也可以操作自定义数据类型
二进制方式读文件用的read函数
函数原型：
ifstream& read( char* buffer, int len );
参数解释：字符指针buffer指向内存中存储的一段空捡，len是读写的字节数
*/
class Person
{
public:
	char m_Name[64];
	int m_Age;
};
void test()
{
	ofstream ofs("Person.txt",ios::binary|ios::out);
	Person p = {"jyz",20};
	//p.m_Name = "jyz";
	//•	在 C++ 中，数组一旦初始化后，不能直接赋值整个数组。所以报错
	//可以使用strcpy来修改,strcpy是个包含在头文件cstring中的全局函数
	ofs.write((const char* )&p,sizeof(p));//对象地址，对象大小
	ofs.close();
}
void readTest()
{
	ifstream ifs("Person.txt", ios::binary | ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	Person p;
	ifs.read((char*) &p,sizeof(p));
	cout << "Name " << p.m_Name << " Age: " << p.m_Age << endl;
}
int main() 
{
	readTest();
	return 0;
}