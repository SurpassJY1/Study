//
// Created by GlokieYu on 25-4-3.
//
/*
在b中遍历字符串1的所有元素，如果没找到了，那就坏了
*/
#include<string>
#include<iostream>
#include<vector>
#include<cctype>//toupper和toloweer
#include<unordered_set>
using namespace std;
char myToUpper(char c)
{
    if(c>='a'&c<='z')
    {
        return toupper(c);
    }else
    {
        return c;
    }
}
int main()
{
    string len1;
    string len2;
    string res;
    cin>>len1>>len2;
    for (int i=0;i<len1.size();i++) {
        len1[i]=(myToUpper(len1[i]));
    }
    for (int i=0;i<len2.size();i++) {
        len2[i]=(myToUpper(len2[i]));
    }
    unordered_set<char>inserted;
    for(int i=0;i<len1.size();i++)
    {
        //大小写都不应写出来
        if(len2.find(len1[i])==string::npos)//string里的find函数如果没找到返回string下一个常量npos
        {if(!inserted.count(len1[i])){
            res+=len1[i];
            inserted.emplace(len1[i]);
        }
        }
    }
    cout<<res;
}