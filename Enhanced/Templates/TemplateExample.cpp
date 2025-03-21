#include<iostream>
#include<vector>
using namespace std;

//ʵ��һ��ͨ�ö������С����ĺ���
//ѡ�����򣬴Ӵ�С
//����char����int����

//define template
template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
template<typename T>
void mySort(vector<T>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		int max = i;//�϶����ֵ���±�
			//�����ҵ���ʵ���ֵ�±�
		//�ӵ�ǰԪ����һ����ʼ��
			for (int j = i+1; j < arr.size(); j++)
			{
				if (arr[max] < arr[j])
				{
					max = j;
				}
			}
		if (max != i)//���max���ǵ�ǰֵ������max�͵�ǰֵ
		{
			mySwap(arr[i], arr[max]);
		}
	}
}

void test()
{
	vector<int>arrInt = { 1,2,3,4,5 };
	mySort(arrInt);
	for (size_t i = 0; i < arrInt.size(); i++)
	{
		cout << arrInt[i] << endl;
	}
	cout << "----------------------------" << endl;
	vector<char>arrChar = { 'a','b','c','d' };
	mySort(arrChar);
	for (size_t i = 0; i < arrChar.size(); i++)
	{
		cout << arrChar[i] << endl;
	}
}
int main()
{
	test();
	return  0;
}