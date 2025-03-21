#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main() 
{
	int val;
	cin >> val;
	int numB = val / 100;
	//remove hundred 
	val = val - numB * 100;
	int numS = val / 10;
	//remove ten 
	val = val - 10 * numS;
	ostringstream res;
	for (int i=0;i<numB;i++) 
	{
		res << "B";
	}
	for (int i=0;i<numS;i++) 
	{
		res << "S";
	}
	for (int i=1;i<=val;i++) 
	{
		res << i;
	}
	cout << res.str()<<endl;
	return 0;
}