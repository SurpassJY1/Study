#pragma once
#ifndef FILECLASSTEMPLATE_H
#define FILECLASSTEMPLATE_H
#include<iostream>
using namespace std;
//��ģ����ļ���д
//���⣺
//��ģ��ĳ�Ա����ʱ�����ڵ��ý׶Σ����·��ļ���д��ʱ�����Ӳ���
//�����ʽ��������������ʵ��д��ͬһ���ļ����У������ĺ�׺��Ϊhpp
//�����ʽ2��ֱ�Ӱ���cppԴ�ļ�
template<class T1,class T2>
class Person 
{
public:
	T1 m_Name;
	T2 m_Age;
	Person(T1 name, T2 age);
	void show();
};
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) 
{
	this->m_Age = age;
	this->m_Name = name;
}
template<class T1, class T2>
void Person<T1, T2>::show() 
{
	cout << "Name: " << this->m_Name << " Age:" << this->m_Age << endl;
}

#endif