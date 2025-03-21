#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool checkExist(int n, vector<int> vec)
{
	for (int i = 0;i < vec.size();i++)
	{
		if (n == vec[i])
		{
			return true;
		}
	}
	return false;
}
int main()
{
	int K;
	cin >> K;
	vector<int> inputs;
	for (int i = 0;i < K;i++)
	{
		int j;
		cin >> j;
		inputs.push_back(j);
	}
	vector<int> medium;
	//calculate the number and insert the medium number to vector
	for (int i = 0;i < inputs.size();i++)
	{
		int val = inputs[i];
		while (val != 1)
		{
			if (val % 2 == 1)//odd number
			{
				val = (val * 3 + 1) / 2;
				if (val!=1&&!checkExist(val, medium))
				{
					medium.push_back(val);
				}
			}
			else if (val % 2 == 0)
			{
				val = val / 2;
				if (val!=1&&!checkExist(val, medium)) {
					medium.push_back(val);
				}
			}
		}
	}
	
	vector<int> keys;
	for (int i = 0;i<inputs.size();i++)
	{
		if (!checkExist(inputs[i],medium))
		{
			keys.push_back(inputs[i]);
		}
	}
	sort(keys.begin(),keys.end());
	for (int i=keys.size()-1;i>=0;i--) 
	{
		if (i==0) 
		{
			cout << keys[i];
			continue;
		}
		cout << keys[i] << " ";
	}
	return 0;
}