#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() 
{
	int N;
	cin >> N;
	vector<int> vec(N+1);
	for (int i=0;i<N;i++) 
	{
		int id;
		int grade;
		cin >> id >> grade;
		vec[id] += grade;
	}
	int max = -1,k=0;
	for (int i=1;i<vec.size();i++) 
	{
		if (vec[i] > max)
		{
			max = vec[i];
			k = i;
		}
	}
	cout << k << " " << max;
	return 0;
}