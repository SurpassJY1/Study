//
// Created by GlokieYu on 25-4-10.
//
#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;
/*
思路；
遍历字符串2，将2中有的字母存在hash表当中，在遍历字符串1时检查字符串2，如果有的话就不添加到res中
*/
int main()
{
    unordered_set<char> hash;
    string len1;
    string len2;
    getline(cin,len1);//因为有空格，所以用getline
    getline(cin,len2);
    for(char c:len2)
    {
        hash.insert(c);
    }
    string res;
    for(char c:len1)
    {
        if(!hash.count(c))
        {
            res+=c;
        }
    }
    cout<<res;
    return 0;
}