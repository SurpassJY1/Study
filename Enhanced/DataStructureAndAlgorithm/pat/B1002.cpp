#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	string n;
	cin >> n;
	map<int, string> map;
	map.insert(make_pair(0, "ling"));
	map.insert(make_pair(1, "yi"));
	map.insert(make_pair(2, "er"));
	map.insert(make_pair(3, "san"));
	map.insert(make_pair(4, "si"));
	map.insert(make_pair(5, "wu"));
	map.insert(make_pair(6, "liu"));
	map.insert(make_pair(7, "qi"));
	map.insert(make_pair(8, "ba"));
	map.insert(make_pair(9, "jiu"));
	int sum = 0;
	for (int i = 0;i < n.size();i++)
	{
		sum =sum+(int)n[i]-(int)'0';//get the correct number
	}
	string sSum = to_string(sum);
	for (int i = 0;i < sSum.size();i++)
	{
		if (i == sSum.size() - 1)
		{
			cout << map[(int)sSum[i]-(int)'0'];
			break;
		}
		cout << map[(int)sSum[i]-(int)'0'] << " ";
	}
	return 0;
}