#include<iostream>
#include<vector>
using namespace std;

//实现一个通用对数组大小排序的函数
//选择排序，从大到小
//测试char数组int数组

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
		int max = i;//认定最大值的下标
			//遍历找到真实最大值下标
		//从当前元素下一个开始找
			for (int j = i+1; j < arr.size(); j++)
			{
				if (arr[max] < arr[j])
				{
					max = j;
				}
			}
		if (max != i)//如果max不是当前值，交换max和当前值
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