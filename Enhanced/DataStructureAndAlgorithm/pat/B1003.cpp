#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool checkWord(string str)
{
	for (char c : str)
	{
		if (c != 'P' && c != 'A' && c != 'T')
		{
			return false;
		}
	}
	return true;
}
bool checkRules(string str) 
{
	int posP = -1;
	int posT = -1;
	for (int i=0;i<str.size();i++) 
	{
		if (str[i]=='P')
		{
			if (posP == -1)
				posP = i;
			else return false;//multi P
		}
		else if (str[i]=='T')
		{
			if (posT == -1)
				posT = i;
			else return false;
		}
	}
	//check if P and T exist and the order is correct
	if (posP == -1 || posT == -1 ||posP>posT)return false;
	int a = posP;//before P
	int c = str.size() - posT-1;//after T
	int b = posT - posP-1;//between
	if (b >= 2)
	{
		return c == b * a;
	}
	else if (b == 1)
	{
		return a == c;
	}
	else return false;
	return true;
}
int main() {

	int n;
	cin >> n;
	vector<string> inputs;
	for (int i = 0;i < n;i++) {
		string str;
		cin >> str;
		inputs.push_back(str);
	}
	for (int i = 0;i < inputs.size();i++) {
		string str = inputs[i];
		if (checkWord(str) == false)
		{
			cout << "NO" << endl;
			continue;
		}
		if (checkRules(str)==false) 
		{
			cout << "NO" << endl;
			continue;
		}
		if (checkWord(str) && checkRules(str))
		{
			cout << "YES" << endl;
		}
	}
	return 0;
}
