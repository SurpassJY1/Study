#include<iostream>
#include<string>
using namespace std;
//�ȸ��߱��������ǻᴴ��building,���û�����л���GoodGuy02����building����
class Building;
/*
��Щ˽�е�����Ҳ�������һЩ������������з��ʾ�Ҫ�õ���Ԫ�ļ���
��Ԫ������ʵ�֣�
1.ȫ�ֺ�������Ԫ
2.������Ԫ
3.��Ա��������Ԫ
ע�⣬��Ա��������ԪҪ��չʾ��ȫ����
*/
class GoodGuy02
{
private:
	Building* building;
public:
	GoodGuy02();
	//���Է���building�е�˽�г�Ա
	void visit();
	//�����Է���building�е�˽�г�Ա
	void visit02();
};


//��������
class Building {
	
	//goodGuyȫ�ֺ�����Building�ĺ�����,���Է���building�е�˽�г�Ա
	friend void goodGuy(Building& building);
	//GoodGuy����Building�ĺ�����,���Է���building�е�˽�г�Ա
	friend class GoodGuy;
	//GoodGuy02��ĳ�Ա��������Ԫ,���Է���Building�е�˽�г�Ա
	friend void GoodGuy02::visit();

private:
	string m_Bedroom;
public:
	string m_SittingRoom;
	Building() {
		m_Bedroom = "����";
		m_SittingRoom = "����";
	}

};

GoodGuy02::GoodGuy02() {
	building = new Building;
}

void GoodGuy02::visit() {
	cout << "�û���02�ĳ�Ա����visit���ڷ��ʣ�" << building->m_SittingRoom << endl;
	cout << "�û���02�ĳ�Ա����visit���ڷ��ʣ�" << building->m_Bedroom << endl;
}

void GoodGuy02::visit02()
{
	cout << "�û���02�ĳ�Ա����visit���ڷ��ʣ�" << building->m_SittingRoom << endl;
}
//������Ԫ
class GoodGuy {
	Building* building;
public:
	GoodGuy();
	void visit();//�ιۺ���,����building�е�����


};
GoodGuy::GoodGuy() {
	building = new Building;
}

void GoodGuy::visit() {
	cout << "���ڷ���building��" << building->m_SittingRoom << endl;
	cout << "���ڷ���building��" << building->m_Bedroom << endl;
}

//ȫ�ֺ�����Ϊ��Ԫ
void goodGuy(Building& building)
{
	cout << "�û��ѵ�ȫ�ֺ������ڷ��ʣ�" << building.m_SittingRoom << endl;
	cout << "�û��ѵ�ȫ�ֺ������ڷ��ʣ�" << building.m_Bedroom << endl;
}

//��Ա��������Ԫ



void test01() {
	Building building;
	goodGuy(building);
}
void test02() {
	GoodGuy gd;
	gd.visit();
}
void test03() {
	GoodGuy02 gd2;
	gd2.visit();
	gd2.visit02();
}
int main()
{
	test03();
	return 0;
}