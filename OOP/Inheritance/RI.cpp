#include<iostream>
using namespace std;
/*
conception:
����������ͬʱ�̳�һ������
����ĳ����ͬʱ�̳�������������
���μ̳����⣺
����� ��
���գ�����
1����̳��˶�������ݣ���ͬ���̳��˶�������ݣ���������ʹ�����ݵ�ʱ��ͻ����������
2��������̳��Զ�������ݼ̳�������
//�����������virtual��Ϊ��̳У�����һ�����ݣ���̳л���Ϊ�����
�ײ㣺�����Ǽ̳��������ݣ����Ǽ̳�����ָ�룬����ָ��ͨ��ƫ�����ҵ�Ψһ������
*/
//AnimalΪ�����
class Animal
{
public:
	int m_Age;
};
//����virtual�ؼ���
class Sheep : virtual public Animal
{

};
//����virtual�ؼ���
class Tuo :virtual public Animal
{
};
class SheepTuo : public Sheep,  public Tuo
{
};

void RITest()
{
	SheepTuo st;
	//������������ͬ��Ҫ������������
	st.Sheep::m_Age = 50;
	st.Tuo::m_Age = 100;
	
	cout << "Sheep Age: " << st.Sheep::m_Age << endl;
	cout << "Tuo Age: " << st.Tuo::m_Age << endl;
	//����ȷ���̳�������age st.m_Age = 50;
	//cout<< st.m_Age << endl;//���100,ֻ��һ��age������ֵڶ���
	cout << st.m_Age << endl;
}
int main()
{
	RITest();
	return 0;
}
