#include<iostream>
using namespace std;

class AbstractMake 
{
public:
	 void boil() 
	{
		cout << "��ˮ" << endl;
	}
	 virtual void putIngredient() = 0;
	  void pour() 
	 {
		 cout << "���뱭��" << endl;
	 }
	 void makeDrink()
	 {
		 boil();
		 putIngredient();
		 pour();
	 }
};
class Coffee :public AbstractMake 
{
public:
	void putIngredient() 
	{
		cout << "�ӿ���" << endl;
	}
};
class Tea :public AbstractMake 
{
public:
	void putIngredient()
	{
		cout << "�Ӳ�Ҷ" << endl;
	}
};
void doWork(AbstractMake* abs)
{
	abs->makeDrink();
	//��ֹ�ڴ�й¶
	delete abs;
}
