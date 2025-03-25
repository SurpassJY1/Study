#include<iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	char c;
	cin >> c;
	int row = 0, column = N;
	if (N % 2 == 0)
		row = column / 2;
	else row = column / 2 + 1;
	for (int i = 0;i < column;i++)
		cout << c;
	cout << endl;
	//row-2ÐÐ
	for (int i = 0;i < row - 2;i++)
	{
		cout << c;
		for (int j = 0;j < column - 2;j++)
		{
			cout << " ";
		}
		cout << c;
		cout << endl;
	}

	for (int i = 0;i < column;i++)
		cout << c;
	return 0;
}