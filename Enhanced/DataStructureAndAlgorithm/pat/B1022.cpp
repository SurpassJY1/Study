#include<iostream>
#include<vector>
using namespace std;
int main() 
{
	//³ý»ùÈ¡Óà·¨
	int A, B, D;
	cin >> A >> B >> D;
	long sum = A + B;
	vector<int> res;
	if (sum == 0) res.push_back(0);
	while (sum!=0) 
	{
		res.push_back(sum% D);
		sum=sum/ D;
	}
	for (int i=res.size()-1;i>=0;i--) 
	{
		cout << res[i];
	}
	return 0;
}