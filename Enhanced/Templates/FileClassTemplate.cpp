#include<iostream>
#include "FileClassTemplate.hpp"
using namespace std;

void test01()
{
	Person<string,int>p1("Jyz",20);
	p1.show();
}

int main() {
	test01();
	return 0;
}