//
// Created by GlokieYu on 25-4-10.
//
#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;
/*
˼·��
�����ַ���2����2���е���ĸ����hash���У��ڱ����ַ���1ʱ����ַ���2������еĻ��Ͳ���ӵ�res��
*/
int main()
{
    unordered_set<char> hash;
    string len1;
    string len2;
    getline(cin,len1);//��Ϊ�пո�������getline
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