#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/*
* cpp对文件操作需要包含头文件 fstream
文件类型：
	文本文件：文件以文本的ASCII码形式存储在计算机中
	二进制文件：文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂他

操作文件的三大类：
	ofstream：写操作
	ifstream：读操作
	fstream：读写操作
	文本文件：
	写文件：
	包含头文件：
	include<fstream>
	创建流对象
	ofstream ofs;
	打开文件
	ofs.open("文件路径"，打开方式);
	写入数据
	ofs<<"写入的数据";
	关闭文件
	ofs.close();
打开方式：
	ios::in 为读文件打开
	ios::out 为写文件打开
	ios::ate 初始位置：文件尾
	ios::app 追加方式写文件
	ios::trunc 如果文件存在，先删除，再创建同名文件
	二进制方式写文件：
	ios::binary|ios::out
	*/
//文本文件写文件
void test01()
{
	ofstream ofs;
	ofs.open("Test.txt",ios::out);
	//写入数据
	ofs << "Hello, this is a test file";
	//关闭
	ofs.close();
}
//读取文本文件
void read()
{
	ifstream ifs;
	ifs.open("Test.txt",ios::in);
	//判断文件是否打开成功
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//四种读数据方法：
	//
	char buf[1024];
	//第一种
	/*while (ifs>>buf)
	{
		cout << buf <<" ";
	}*/
	//第二种
	/*while (ifs.getline(buf,sizeof(buf)) )//成员函数getline，第一个参数是输入流第二个此参数是读取数量
	{
		cout << buf << endl;
	}*/
	//第三种
	//string str;
	//while (getline(ifs,str)) //全局函数版getline，第一个参数是文件输入流，第二个是准备好的字符串
	//{
	//	cout << str << endl;
	//}
	//第四种，逐个词读，不推荐
	/*char c;
	while ((c = ifs.get())!= EOF) 
	{
		cout << c << endl;
	}*/
	ifs.close();
}
int main()
{
	read();
	return 0;
}