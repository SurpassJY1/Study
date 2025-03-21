#include <iostream>
#include "ClassExample.hpp"
using namespace std;

void test01() 
{
	MyArray< int>arr1(5);
	MyArray<int>arr2 = arr1;
	arr1.tailInsert(1);
	arr1.tailInsert(2);
	arr1.tailInsert(3);
	arr1.tailInsert(4);
	arr1.tailInsert(5);
	cout << arr1[3] << endl;
}

int main() 
{
	test01();
	return 0;
}

