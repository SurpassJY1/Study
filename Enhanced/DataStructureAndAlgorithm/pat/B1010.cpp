#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

int main()
{
	string input;
	getline(cin, input);
	istringstream iss(input);
	int num;
	vector<int> numQue;
	while (iss >> num)
	{
		numQue.push_back(num);
	}
	for (int i = 0;i < numQue.size();i += 2)
	{
		if (numQue[i] * numQue[i + 1] == 0)
		{
			continue;
		}
		
			if (i != numQue.size() - 2) {
				cout << numQue[i] * numQue[i + 1] << " ";
				cout << numQue[i + 1] - 1 << " ";
			}
			else {
				cout << numQue[i] * numQue[i + 1] << " ";
				cout << numQue[i + 1] - 1;
			}
		
	}
	return 0;
}