#include<iostream>
using namespace std;
/*
* 电脑组成为CPU 显卡 内存条
* 将每个零件封装成抽象基类，并提供不同的厂商生产不同的零件
* 创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口
* 测试组装三台不同的电脑进行工作
*/

//CPU抽象类
class CPU
{
public:
	virtual void calculate() = 0;
};
//显卡的抽象类
class VideoCard
{
public:
	virtual void display() = 0;
};
//内存条的抽象类
class RAM
{
public:
	virtual void store() = 0;
};
//电脑类
class Computer 
{
public:
	//在构造函数中传入不同的零件
	Computer(CPU* CPU, VideoCard* VideoCard, RAM* RAM) :CPU( CPU), VideoCard(VideoCard), RAM(RAM) {}
	//提供析构函数把三个在堆区元素释放干净
	~Computer() 
	{
		delete CPU;
		delete VideoCard;
		delete RAM;
		CPU = nullptr;
		VideoCard = nullptr;
		RAM = nullptr;
	}
	//提供工作函数
	void work()
	{
		CPU->calculate();
		VideoCard->display();
		RAM->store();
	}
private:
	CPU* CPU;
	VideoCard* VideoCard;
	RAM* RAM;
};
//写厂商
class Intel :public CPU
{
public:
	void calculate() {
		cout << "i7 14700k starts calculate" << endl;
	}
};
class NVDIA : public VideoCard
{
public:
	void display()
	{
		cout << "RTX4090 starts display" << endl;
	}
};
class sumsung :public RAM
{
public:
	void store() {
		cout << "sumsung starts store" << endl;
	}
};
int main()
{//组装第一台电脑
	CPU* iu = new Intel;
	VideoCard* nCard = new NVDIA;
	RAM* ram = new sumsung;
	//电脑
	Computer* computer = new Computer(iu,nCard,ram);
	computer->work();
	return 0;
}