#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
����洢���������ڴ�ռ��ڣ���Ԫ��������ͬ���������������ḻ��������Ϣ��ϵͳ����������Щ��Ϣ���Ż����ݽṹ�Ĳ���Ч�ʡ�

�ռ�Ч�ʸߣ�����Ϊ���ݷ������������ڴ�飬�������Ľṹ������
֧��������ʣ�����������
 ʱ���ڷ����κ�Ԫ�ء�
����ֲ��ԣ�����������Ԫ��ʱ�����������������������Ỻ������Χ���������ݣ��Ӷ��������ٻ�������������������ִ���ٶȡ�
�����ռ�洢��һ��˫�н�����������¾����ԡ�

������ɾ��Ч�ʵͣ���������Ԫ�ؽ϶�ʱ��������ɾ��������Ҫ�ƶ�������Ԫ�ء�
���Ȳ��ɱ䣺�����ڳ�ʼ���󳤶Ⱦ͹̶��ˣ�����������Ҫ���������ݸ��Ƶ������飬�����ܴ�
�ռ��˷ѣ�����������Ĵ�С����ʵ�����裬��ô����Ŀռ�ͱ��˷��ˡ�


*/
template<class T>
class MyArr
{
	T* data;
	int size;
	int capacity;
public:
	MyArr(int n) :capacity(n)
	{
		size = 0;
		data = new T[n];
	};
	MyArr() :capacity(10), size(0)
	{
		data = new T[10];
	}
	~MyArr() 
	{
		delete[]data;
	}
	T get(int n)
	{
		return data[n];
	}
	void insert(int n, T value)
	{
		//if n>capacity
		if (size >= capacity)
		{
			extendArr();
		}
		//move index and after it to next one
		if (size > 1)
		{
			for (int i = size - 1; i > n; i--)
			{
				data[i] = data[i - 1];
			}
		}
		data[n] = value;
		size++;
	}
	void print() 
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << "The "<<i<<": " << data[i] << endl;
		}
		cout << endl;
	}
	T remove(int index) 
	{
		if (index>size)
		{
			return NULL;
		}
		//move the elements after the id to front
		T removed = data[index];
		for (size_t i = index+1; i <size ; i++)
		{
			data[i - 1] = data[i];
		}
		size--;
		return removed;
	}
	void extendArr() 
	{
		capacity += capacity / 2;
		T* newArr = new T[capacity];
		for (size_t i = 0; i < size; i++)
		{
			newArr[i] = data[i];
		}
		//delete the old array
		delete[]data;
		data = newArr;
	}
	vector<T> toVector() 
	{
		vector<T> v;
		v.reserve(size);
		cout << size << endl;
		for (size_t i = 0; i < size; i++)
		{
			v.push_back(data[i]);
		
		}
		return v;
	}
};
template<class T>
class MyPrint 
{
public:
	void operator()(T value) 
	{
		cout << value << " ";
	}
};
int main()
{
	MyArr<int> mArr;
	for (size_t i = 0; i < 15; i++)
	{
		mArr.insert(i,i+1);
	}
	mArr.remove(3);
	vector<int> v=mArr.toVector();
	cout << v[0];
	//for_each(v.begin(),v.end(),MyPrint<int>());
	return 0;
}