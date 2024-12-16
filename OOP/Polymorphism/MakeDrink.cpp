#include<iostream>
using namespace std;

class AbstractMake 
{
public:
	 void boil() 
	{
		cout << "烧水" << endl;
	}
	 virtual void putIngredient() = 0;
	  void pour() 
	 {
		 cout << "倒入杯中" << endl;
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
		cout << "加咖啡" << endl;
	}
};
class Tea :public AbstractMake 
{
public:
	void putIngredient()
	{
		cout << "加茶叶" << endl;
	}
};
void doWork(AbstractMake* abs)
{
	abs->makeDrink();
	//防止内存泄露
	delete abs;
}
