#include<iostream>
using namespace std;
/*
��̬��̬���������أ���������أ����ú�����
��̬��̬����������麯��ʵ������ʱ��̬
����
��̬��̬�ĺ�����ַ��󶨣�����׶�ȷ��������ַ
��̬��̬������ַ��󶨣�����ʱȷ��������ַ

��̬��̬����������
	1.�м̳й�ϵ
	2.������д���麯��
��̬��̬��ʹ�ã�
	��������ָ���������
*/
class Animal
{
public:
	virtual void speak()
	{
		cout << "Animal is speaking" << endl;
	}
};

class Cat : public Animal
{
public:
	void speak() {
		cout << "Cat is speaking" << endl;
	}
};
//ִ��˵���ĺ���
//��ַ��󶨣��ڱ���׶�ȷ��������ַ�����Animal is speaking
//���ִ��è��˵��,��Ҫ���,�ڸ����speak����ǰ����һ��virtual
void doSpeak(Animal& animal) //Animal &animal=cat;
{
	animal.speak();
}

void test() 
{
	cout << "Size of Animal " << sizeof(Animal) << endl;//��virtual��1����virtual��8�������и�ָ��
	cout << "Size of Cat " << sizeof(Cat) << endl;													//vfptr��vitrual function pointer
														//ָ��ָ���麯����vftable
														//vftable���¼�麯����ַ����������д�˸�����麯����
														// �����ڲ����麯������滻��������麯����ַ
														//������ָ���������ָ����������ʱ������̬
}
