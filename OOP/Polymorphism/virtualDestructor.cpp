#include<iostream>
using namespace std;
/*
��̬ʹ��ʱ��������������Կ��ٵ���������ô����ָ�����ͷ�ʱ�޷����õ��������������
�����ʽ���������е�����������Ϊ���������ߴ�������
�������ʹ��������Ĺ��ԣ�
�����Խ������ָ���ͷ��������
����Ҫ����ĺ���ʵ��
�������ʹ�������������
����Ǵ����������������ڳ����࣬�޷�ʵ��������

�ܽ᣺
�������ʹ����������������������ָ���ͷ���������п��ٵ����������Ե�����
���������û�����ݿ��ٵ����������Բ�д���������ߴ�������
���һ����д�˴�����������ô��������ڳ����࣬�޷�ʵ��������
*/
class Human 
{
public:
	//���麯��
	virtual void speak() = 0;
	//���캯������������
	Human() { cout << "Constructor called" << endl; }
	//�����������������ָ���ͷ���������ʱ���ͷŲ��ɾ�������
	//virtual ~Human() { cout << "Destructor called" << endl; }
	
	//����������
	//д�˴���������������ڳ����࣬�޷�ʵ����
	virtual ~Human() = 0;//������Ҫһ������ĺ���ʵ��,
						//��Ϊ���൱��Ҳ�п����г�Ա�����ڶ�����������ʵ��
};
//���������ĺ�����ʵ��
Human::~Human() 
{
	cout << "Destructor called" << endl;
}
class Student :public Human 
{
public:
	string* m_Name;
	void speak() {
		cout << *m_Name<<" speaks" << endl;
	}
	Student(string name):m_Name(new string(name)) {
		cout << "Constructor called" << endl;
	}
	//����������ɾ��������Ա����
	~Student()
	{
		cout << "Destructor called" << endl;
		delete m_Name;
		m_Name = nullptr;
	}
};
void test() 
{
	Human* human = new Student("Tom");
	human->speak();
	delete human;//���Է���û�е���Student�����������
	//ԭ�򣺸���ָ����������ʱ��û�е����������������������ڴ��й¶
	//�������������������
}
int main()
{
	test();
	return 0;
}