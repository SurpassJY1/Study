#include<iostream>
#include<vector>
using namespace std;
/*
vector�ĵ�������֧��������ʵĵ�����
vector�Ĺ��캯��
vector<T> v;
vector(v.begin(),v.end());��v[begin(),end())�����е�Ԫ�ؿ���������
vector(n,elem);��n��elem����������
vector(const vector &vec);�������캯��

vector��ֵ����
vector& operator=(const vector &vec)���صȺŲ�������ֵ
assign(beg,end)��[beg,end)�����е����ݿ�����ֵ������
assign(n,elem)��n�� elem ������ֵ������

vector�����ʹ�С
����ԭ��
empty(); �ж������Ƿ�Ϊ��
capacity();����������
size(); ���������ĸ���
resize(int num);����ָ����������Ϊnum���������߳�������Ĭ��ֵ�����λ��
				��������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
resize(int num,elem);����ָ����������Ϊnum���������߳�������elem�����λ��
					��������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��

vector�����Ĳ����ɾ��
����ԭ��
push_back(ele);β������Ԫ��ele
pop_back();β��ɾ�����һ��Ԫ��
insert(const_iterator pos,ele);������ָ��λ��pos����Ԫ��ele
insert(const_inerator pos,int count,ele);������ָ��λ��pos����count��Ԫ��ele
erase(const_iterator pos);ɾ��������ָ���Ԫ��
erase(const_iterator start,const_iterator_iterator end);ɾ����������start��end֮���Ԫ��
clear();ɾ�������е�����Ԫ��

vector���������ݴ�ȡ����
����ԭ��
at(int idx);��������idx��ָ������
operator[];��������idx��ָ������
front();���������е�һ������Ԫ��
back();�������������һ������Ԫ��

vector��������
����ԭ��
swap(vec);��vec�뱾��Ԫ�ػ���
ʵ����;
����swap���������ڴ�ռ�
	vector<int>(v).swap(v);
	vector<int>(v)���ÿ������캯�������һ����������
	.swap(v)��������
	���ϵͳ������������

	vector����Ԥ���ռ�
	����vector�ڶ�̬��չ����ʱ����չ�ٶ�
	����ԭ�ͣ�
	reserve(int len);����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ���
*/
void print(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
}
void test01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	print(v1);
	cout << "------------------------------------" << endl;
	//ͨ�����乹��
	vector<int> v2(v1.begin(), v1.end());
	print(v2);
	cout << "--------------------------------------" << endl;
	//n�� element����
	vector<int> v3(10, 1);
	print(v3);
	cout << "-------------------------------------------" << endl;
	vector<int> v4(v3);
	print(v4);
}
//vector�ĸ�ֵ
void test02()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	print(v1);
	//operator=
	vector<int>v2 = v1;
	print(v2);
	//assign
	vector<int> v3;
	v3.assign(v2.begin(), v2.end());
	cout << "-------------------------" << endl;
	print(v3);
	cout << "-----------------------------" << endl;
	vector<int>  v4;
	v4.assign(10, 1);
	print(v4);
}
//vector�����������ʹ�С����
void test03()
{
	vector<int>v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	print(v1);
	cout << "-------------------" << endl;
	if (v1.empty())
	{
		cout << "v1 is empty" << endl;
	}
	else cout << "v1 is not empty" << endl;
	cout << "Capacity of v1 is " << v1.capacity() << endl;
	cout << "Size of v1 is " << v1.size() << endl;
	//����ָ����С
	v1.resize(15);
	cout << "Size of v1 is " << v1.size() << endl;//����ָ���ı�ԭ����Ĭ����0���
	cout << "------------------------" << endl;
	print(v1);
	//ָ��Ĭ�����ֵ
	v1.resize(20, 100);
	cout << "--------------------------" << endl;
	print(v1);
}
/*
push_back(ele);β������Ԫ��ele
pop_back();β��ɾ�����һ��Ԫ��
insert(const_iterator pos,ele);������ָ��λ��pos����Ԫ��ele
insert(const_inerator pos,int count,ele);������ָ��λ��pos����count��Ԫ��ele
erase(const_iterator pos);ɾ��������ָ���Ԫ��
erase(const_iterator start,const_iterator_iterator end);ɾ����������start��end֮���Ԫ��
clear();ɾ�������е�����Ԫ��*/
void test04()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	print(v1);
	cout << "------------------" << endl;
	v1.pop_back();
	print(v1);
	cout << "------------------" << endl;

	//����
	//��һ�������ǵ�����
	v1.insert(v1.begin(), 100);
	print(v1);
	cout << "------------------" << endl;
	v1.insert(v1.begin(), 2, 2);
	print(v1);
	cout << "------------------" << endl;
	//ɾ������Ҳ�ǵ�����
	v1.erase(v1.begin());
	print(v1);

	cout << "------------------" << endl;
	//���
	v1.clear();
	print(v1);

}
void test05()
{
	vector<int>v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	//����[]��ʽ���������е�Ԫ��
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " " << endl;
	}
	cout << endl;
	//����at��ʽ����Ԫ��
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << endl;
	}
	cout << endl;
	//��ȡ��һ��Ԫ��
	cout << "��һ��Ԫ��" << v1.front() << endl;
	//��ȡ���һ��Ԫ��
	cout << "���һ��Ԫ��" << v1.back() << endl;
}
void test06()
{
	vector<int>v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int>v2;
	for (size_t i = 10; i < 20; i++)
	{
		v2.push_back(i);
	}
	cout << "v1:" << endl;
	print(v1);
	cout << endl;
	cout << "v2:" << endl;
	print(v2);
	cout << endl;
	v1.swap(v2);
	cout << "v1:" << endl;
	print(v1);
	cout << "v2:" << endl;
	print(v2);
}
//����swap�����ڴ�ռ�
void test07()
{
	vector<int>v;
	for (size_t i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << "Capacity of v is " << v.capacity() << endl;
	cout << "Size of v is " << v.size() << endl;
	cout << endl;
	v.resize(3);
	cout << "Capacity of v is " << v.capacity() << endl;
	cout << "Size of v is " << v.size() << endl;
	cout << endl;
	//����swap�����ڴ�ռ�
	vector<int>(v).swap(v);
	cout << "Capacity of v is " << v.capacity() << endl;
	cout << "Size of v is " << v.size() << endl;
	/*/����swap���������ڴ�ռ�
		vector<int>(v).swap(v);
	vector<int>(v)���ÿ������캯�������һ����������
		.swap(v)��������
		���ϵͳ������������*/
}
//Ԥ���ռ�
void test08()
{
	vector<int>v;
	//��ǰԤ���ռ�
	v.reserve(100000);
	int num = 0;
	int* p = nullptr;
	for (size_t i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p!=&v[0])
		{
			//���¿��ٿռ������pָ��ͷһ��Ԫ��
			p = &v[0];
			num++;
		}
	}
	cout << "���¿��ٿռ����Ϊ��" << num << endl;//��̬��չ��30��
													//Ԥ��100000�ռ��Ͷ�̬��չ��һ��
}
int main()
{
	test08();
	system("pause");
	return 0;
}