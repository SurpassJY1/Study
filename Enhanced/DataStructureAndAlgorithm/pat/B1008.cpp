#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	M = M % N;
	vector<int> vec;
	for (int i = 0;i < N;i++)
	{
		int elem;
		cin >> elem;
		vec.push_back(elem);
	}
	/*for (int i:vec)//18分，因为当数组中有大于9的元素就用不了了，得用数组旋转法
	{
		cout << i << endl;
	}*/
	//get string
	//if (M != 0) {
	//	ostringstream oss;
	//	for (int i = 0;i < vec.size();i++)
	//	{
	//		oss << vec[i];
	//	}
	//	string vecStr = oss.str();
	//	string lastM = vecStr.substr(N - M, M);
	//	string first = vecStr.substr(0, N - M);
	//	string res;
	//	res += lastM;
	//	res += first;
	//	//change res to number and input it to vec
	//	for (int i = 0;i < res.size();i++)
	//	{
	//		vec[i] = (int)res[i] -(int) '0';
	//	}
	//	for (int i = 0;i < vec.size();i++)
	//	{
	//		if (i == vec.size() - 1)
	//		{
	//			cout << vec[i];
	//			break;
	//		}
	//		cout << vec[i] << " ";
	//	}
	//}else if(M==0)
	//{
	//	for (int i = 0;i < vec.size();i++)
	//	{
	//		if (i == vec.size() - 1)
	//		{
	//			cout << vec[i];
	//			break;
	//		}
	//		cout << vec[i] << " ";
	//	}
	//}
	reverse(vec.begin(),vec.end());
	reverse(vec.begin(),vec.begin()+M);
	reverse(vec.begin()+M,vec.end());
		for (int i = 0;i < vec.size();i++)
	{
		if (i == vec.size() - 1)
		{
			cout << vec[i];
			break;
		}
		cout << vec[i] << " ";
	}
}