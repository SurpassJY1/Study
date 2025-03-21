#pragma once
#ifndef CLASSEXAMPLE_H
#define CLASSEXAMPLE_H
#include <iostream>
using namespace std;
/*
* ʵ��һ��ͨ�õ�������
���������ú��Զ����������ʹ洢
����������ݴ���ڶ���
���캯�����Դ�����������
�ṩ��Ӧ�������캯���Լ�operator=��ֹǳ����
�ṩβ���βɾ
����ͨ���±����
���Ի��Ԫ�ظ�������������
*/
template<class T>
class MyArray
{
public:
	void tailInsert(T data);
	void tailDelete();
	MyArray<T>& operator=(MyArray<T>& another);
	MyArray(int capacity);
	MyArray(const MyArray<T>& arr2);
	~MyArray();
	T& operator[](int index);
private:
	//array
	T* pAddress;
	int m_Capacity;
	int m_Size;
};
template<class T>
MyArray<T>::MyArray(int capacity)
{
	this->m_Capacity = capacity;
	this->m_Size = 0;
	this->pAddress = new T[this->m_Capacity];
	cout << "�вι���" << endl;
}
//destructor
template<class T>
MyArray<T>::~MyArray() 
{
	if (this->pAddress!=nullptr)
	{
		delete[]this->pAddress;
		this->pAddress = nullptr;
	}
	cout << "����" << endl;
}
template<class T>
MyArray<T>& MyArray<T>::operator=(MyArray<T>&another) 
{
	//���ж�ԭ�������Ƿ�����v�ͣ�������ͷ�
	if (this->pAddress!=nullptr)
	{
		delete[]pAddress;
		pAddress = nullptr;
		m_Size = 0;
		m_Capacity = 0;
	}
	this->m_Capacity = another.m_Capacity;
	this->m_Size = another.m_Size;
	this->pAddress = new T[this->m_Size];
	for (size_t i = 0; i < this->m_Size; i++)
	{
		pAddress[i] = another.pAddress[i];
	}
	return *this;
}
template<class T>
MyArray<T>::MyArray(const MyArray<T>& another )
{

	this->m_Capacity = another.m_Capacity;
	this->m_Size = another.m_Size;
	this->pAddress = new T[this->m_Capacity];
	for (size_t i = 0; i < this->m_Size; i++)
	{
		pAddress[i] = another.pAddress[i];
	}
	cout << "����" << endl;
}
template<class T>
void MyArray<T>::tailInsert(T data) 
{
	if (this->m_Size==this->m_Capacity)
	{
		cout << "The array is full" << endl;
		return;
	}
	this->pAddress[m_Size] = data;
	m_Size++;
}
template<class T>
void MyArray<T>::tailDelete() 
{
	if (this->m_Size==0)
	{
		cout << "The array is empty" << endl;
		return;
	}

	size--;
}
template<class T>
T& MyArray<T>::operator[](int index) 
{
	return this->pAddress[index];
}
#endif