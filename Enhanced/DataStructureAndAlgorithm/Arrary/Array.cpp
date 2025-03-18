#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
数组存储在连续的内存空间内，且元素类型相同。这种做法包含丰富的先验信息，系统可以利用这些信息来优化数据结构的操作效率。

空间效率高：数组为数据分配了连续的内存块，无须额外的结构开销。
支持随机访问：数组允许在
 时间内访问任何元素。
缓存局部性：当访问数组元素时，计算机不仅会加载它，还会缓存其周围的其他数据，从而借助高速缓存来提升后续操作的执行速度。
连续空间存储是一把双刃剑，其存在以下局限性。

插入与删除效率低：当数组中元素较多时，插入与删除操作需要移动大量的元素。
长度不可变：数组在初始化后长度就固定了，扩容数组需要将所有数据复制到新数组，开销很大。
空间浪费：如果数组分配的大小超过实际所需，那么多余的空间就被浪费了。


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