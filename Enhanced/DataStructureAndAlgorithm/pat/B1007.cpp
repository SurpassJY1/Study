#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

//first solution to enhance performance
//bool isPrimeNumber(int i)
//{
//	if (i == 1||i==0)return false;
//	int m = i / 2;
//	for (int j=2;j<=m;j++)//the factor is between 2 and x/2 
//						//,j<=m because we should make sure m is greater tha j to avoid 4 
//	{
//		if (i%j==0) 
//		{
//			return false;
//		}
//	}
//	return true;
//}

//second solution to enhance performance
//bool isPrimeNumber(int i) 
//{
//	if (i == 2)return true;
//	if (i == 1 || i == 0||i%2==0) return false;
//	//i is odd number here
//	//odd number can't be divided by 2 and 2n
//	for (int num = 3;num < i;num+=2) //we can only check odd number
//	{
//		if (i%num==0) 
//		{
//			return false;
//		}
//	}
//	return true;
//}

////combination of two solutions
//bool isPrimeNumber(int i)
//{
//	if (i == 2)return true;
//	if (i == 1 || i == 0 || i % 2 == 0)return false;
//	//odd number here
//	int m = i / 2; //the odd number's factor is between 3 and i/2
//	for (int num=3;num<m;num+=2)
//	{
//		if (i%num==0) 
//		{
//			return false;
//		}
//	}
//	return true;
//}

//the factor is between 2 to sqrt(n)
//because factor f1*f2=n
//if two factor are all greater/less than sqrt(n), f1*f2>/<n
bool isPrimeNumber(int i)
{
	if (i == 2)return true;
	if (i == 1 || i == 0 || i % 2 == 0)return false;
	for (int num = 3;num * num <= i;num += 2)
	{
		if (i % num == 0)
			return false;
	}
	return true;
}
int main()
{
	int N;
	cin >> N;
	vector<int> primNumbers;
	for (int i = 0;i <= N;i++)
	{
		if (isPrimeNumber(i))
		{
			primNumbers.push_back(i);
		}
	}
	int count = 0;
	for (int i = 1;i < primNumbers.size();i++)
	{
		if (primNumbers[i] - primNumbers[i - 1] == 2)
		{
			count++;
		}
	}
	cout << count << endl;
	return 0;
}