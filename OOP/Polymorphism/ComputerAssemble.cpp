#include<iostream>
using namespace std;
/*
* �������ΪCPU �Կ� �ڴ���
* ��ÿ�������װ�ɳ�����࣬���ṩ��ͬ�ĳ���������ͬ�����
* �����������ṩ�õ��Թ����ĺ��������ҵ���ÿ����������Ľӿ�
* ������װ��̨��ͬ�ĵ��Խ��й���
*/

//CPU������
class CPU
{
public:
	virtual void calculate() = 0;
};
//�Կ��ĳ�����
class VideoCard
{
public:
	virtual void display() = 0;
};
//�ڴ����ĳ�����
class RAM
{
public:
	virtual void store() = 0;
};
//������
class Computer 
{
public:
	//�ڹ��캯���д��벻ͬ�����
	Computer(CPU* CPU, VideoCard* VideoCard, RAM* RAM) :CPU( CPU), VideoCard(VideoCard), RAM(RAM) {}
	//�ṩ���������������ڶ���Ԫ���ͷŸɾ�
	~Computer() 
	{
		delete CPU;
		delete VideoCard;
		delete RAM;
		CPU = nullptr;
		VideoCard = nullptr;
		RAM = nullptr;
	}
	//�ṩ��������
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
//д����
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
{//��װ��һ̨����
	CPU* iu = new Intel;
	VideoCard* nCard = new NVDIA;
	RAM* ram = new sumsung;
	//����
	Computer* computer = new Computer(iu,nCard,ram);
	computer->work();
	return 0;
}