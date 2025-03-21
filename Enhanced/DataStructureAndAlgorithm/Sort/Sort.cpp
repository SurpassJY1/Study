#include<iostream>
#include<vector>
using namespace std;

vector<int> insertionSort(vector<int>& vec)
{
	for (int i=1;i<vec.size();i++)
	{
		int j = i, temp = vec[i];
		while (j>0&&temp<vec[j-1])
		{
			vec[j]=vec[j - 1];
		}
		vec[j] = temp;
	}
}

int main() 
{
	vector<int> vec;
	for (int i=6;i>=0;i--) 
	{
		vec.push_back(i);
	}
	vector<int> vecRes=insertionSort(vec);
	for (int i:vecRes) 
	{
		cout << i << " ";
	}
	return 0;
}