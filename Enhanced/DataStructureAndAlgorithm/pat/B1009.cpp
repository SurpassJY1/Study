#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    string input;
    getline(cin,input);
    vector<string> words;
    string word;
    istringstream iss(input);
    while (iss >> word)
    {
        words.push_back(word);
    }
  
    reverse(words.begin(), words.end());
    for (int i = 0;i < words.size();i++)
    {
        if (i == words.size()-1)
        {
            cout << words[i];
            break;
        }
        cout << words[i] << " ";
    }
    return 0;
}