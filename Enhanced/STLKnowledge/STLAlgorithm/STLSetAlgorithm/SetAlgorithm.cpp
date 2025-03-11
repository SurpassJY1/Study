#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
���ü����㷨
itEnd set_intersection(beg1,end1,beg2,end2,begTar);
�󽻼�
����Ŀ�����������һ������Ԫ�صĵ�����
itEnd set_union(beg1,end1,beg2,end2,begTar);
�󲢼���ע�⣬����������������������
itEnd set_difference(beg1,end1,beg2,end2,begTar)
����ע�⣬����������������������
*/

//itEnd set_intersection(beg1,end1,beg2,end2,begTar)
class MyPrint 
{
public:
	void operator()(int v) 
	{
		cout << v << " ";
	}
};

void test01()
{
	vector<int> v1;
	vector<int> v2;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i+5);
	}
	//�洢������Ŀ������
	vector<int> v3;
	//��ǰ��v3���ٽ����Ŀռ�
	//v3�Ŀռ�ȡ��������С���Ǹ���Ϊ����Ԫ����󲻻������
	v3.resize(min(v1.size(),v2.size()));
	//����set_intersection���صĵ��������ǽ������һ��Ԫ�صĵ����������ڱ���
	vector<int>::iterator itEnd=set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
	for_each(v3.begin(),itEnd,MyPrint());
}
//set_union
void test02()
{
	vector<int> v1;
	vector<int> v2;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i+5);
	}
	//target
	vector<int> v3;
	//��������������û�н�����������С������������С���
	v3.resize(v1.size()+v2.size());
	//���ղ��������һ��Ԫ�صĵ�����λ��
	auto itEnd=set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
	for_each(v3.begin(),itEnd,MyPrint());
}
//set_difference
void test03()
{
	vector<int> v1;
	vector<int> v2;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i+5);
	}
	vector<int> vTar;
	//���������������û�н�������ʱsizeȡ�����������д����һ��
	vTar.resize(max(v1.size(),v2.size()));
	auto itEnd = set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),vTar.begin());
	for_each(vTar.begin(),itEnd,MyPrint());
	cout << endl;
	//��v2-v1
	vector<int> v3;
	v3.resize(max(v1.size(),v2.size()));
	auto itEnd2 = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v3.begin());
	for_each(v3.begin(), itEnd2, MyPrint());

}
int main() {
	test03();
	system("pause");
	return 0;
}