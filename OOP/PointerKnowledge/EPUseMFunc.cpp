#include<iostream>
using namespace std;
/*
��cpp�п�ָ��Ҳ���Է��ʳ�Ա��������Ҫע����û���õ�this
ָ��
*/
class Person {
public:
	void showClassName() 
	{
		cout << "this is person class" << endl;
	}
	int m_Age;
	void showAge() {
		//����ԭ���Ǵ����ָ��Ϊ�գ���ָ�뻹����ó�Ա
		//����һ�����ӽ�׳��
		if (this==nullptr)
		{
			return;
		}
		cout << "Age: " << m_Age << endl;
	}
};
int main()
{
	Person* p = nullptr;
	p->showClassName();
	//����p->showAge();
	//��Ϊ�������Ե�ǰ�涼Ĭ���и�this->m_Age
	p->m_Age();
	return 0;
}