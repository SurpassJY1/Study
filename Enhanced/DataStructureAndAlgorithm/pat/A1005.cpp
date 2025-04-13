//
// Created by GlokieYu on 25-4-10.
//
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    string N;//因为N是小于十的100次方，超过范围了，所以用string存储
    cin>>N;
    int sum=0;
    //遍历N，找到N的每一位数字加到sum里
    for(char c:N)
    {
        sum+=c-'0';
    }
    vector<string> words={"zero","one","two","three","four","five","six","seven","eight","nine"};
    string res=to_string(sum);
    for(int i=0;i<res.size();i++)//存入字符串正序遍历
    {
        if(i==res.size()-1)
            cout<<words[res[i]-'0'];
        else
            cout<<words[res[i]-'0']<<" ";
    }

    return 0;
}