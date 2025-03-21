#include<string>
#include<iostream>
using namespace std;

string hannoi(int n, char src, char dest, char aux)
{
	string str1;
	if (n > 0) {
		str1 = hannoi(n - 1, src, aux, dest);
		str1 =str1+src+dest;
		str1 += hannoi(n - 1,	 aux, dest, src);
	}
	else {
		str1 = "";
	}
	return str1;
}
int main() 
{
	cout << hannoi(2,'A','C','B') << endl;
	return 0;
}
