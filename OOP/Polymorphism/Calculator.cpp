#include<iostream>
using namespace std;

class Calculator 
{
public:
	int num1;
	int num2;
	int getResult(string oper) {
		if (oper=="+")
		{
			return num1 + num2;
		}
		else if (oper == "-") 
		{
			return num1 - num2;
		}
		else if (oper=="*")
		{
			return num1 * num2;
		}
		else if (oper == "/") 
		{
			return num1 / num2;
		}
		return -1;
	}
};
/*
�������չ�µĹ��ܣ���Ҫ�޸�Դ��
����ʵ�Ŀ����У��ᳫ����ԭ��
����ԭ�򣺶���չ���п��ţ����޸Ľ��йر�
*/
//���ö�̬ʵ�ּ�����
class AbstractCalculator
{
public:
	int m_Num1;
	int m_Num2;
	//���麯��
	//һ������ֻҪ��һ�����麯������ô�����ǳ�����
	//��������ص㣺
	//�޷�ʵ��������
	//���������д���еĴ��麯��
	virtual int getResult() = 0;

};
//�ӷ�������
class AddCalculator :public AbstractCalculator
{
public:
	int getResult() 
	{
		return m_Num1 + m_Num2;
	}
};
//����
class SubCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};
//�˷�
class MultiCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 * m_Num2;
	}
};
void test01() 
{
	Calculator c;
	c.num1 = 10;
	c.num2 = 5;
	cout << c.getResult("/") << endl;
	cout << c.getResult("*") << endl;
	cout << c.getResult("+") << endl;
	cout << c.getResult("-") << endl;
}
void test02()
{
	//����ָ���������ָ���������
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 10;
	cout << abc->getResult()<<endl;
//�����ڶ��������������ǵ�����
	delete abc;
	abc = new SubCalculator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 1000;
	cout << abc->getResult() << endl;
}
class Son :public AbstractCalculator 
{
public:
	int getResult() {
		return 0;
	}
};
void test03() 
{
	//AbstractCalculator abs;ջ���޷�ʵ��������
	//new AbstractCalculator;�����޷�ʵ��������
	//Son s;����û����д�����еĴ��麯���޷�ʵ��������
	//new Son;
	Son sl;//��д�����еĴ��麯��֮��Ϳ���ʵ����������
}
