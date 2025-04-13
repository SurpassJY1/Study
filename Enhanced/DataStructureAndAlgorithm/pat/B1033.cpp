//
// Created by GlokieYu on 25-4-3.
//
#include<iostream>
#include<string>
#include<unordered_set>
#include<cctype>//大小写转换的
using namespace std;

void store(char c,unordered_set<char>&badKey)
{

    if(c=='+')
    {
        for(char a='A';a<='Z';a++)
        {
            badKey.emplace(a);
        }
    }else if(c=='_')
    {
        badKey.emplace(' ');
    }else if(c==','||c=='.')
    {
        badKey.emplace(c);
    }else if(c>='0'&&c<='9')
    {
        badKey.emplace(c);
    }
    else
    {
        badKey.emplace(c);
        badKey.emplace(tolower(c));
    }
}
bool isFound(unordered_set<char> badKey,char c)
{
    return badKey.find(c)!=badKey.end();
}
int main()
{
    string broken;
    string input;
    string real;
    getline(cin,broken);
    getline(cin,input);//有可能有空格，所以用getline
    /*
    英文字母坏键用大写给：大写小写都该屏蔽
    +键坏了不能出现大些字母
    _坏了就要把空字符屏蔽
    可能没有坏键
    */
    if(broken.size()==0)
        cout<<input<<endl;
    else
    {
        unordered_set<char> badKey;
        //把所有坏键存到哈希表，如果这个字符在哈希表中存在就屏蔽
        for(int i=0;i<broken.size();i++)
        {
            store(broken[i],badKey);
        }
        for(int i=0;i<input.size();i++)
        {
            if(isFound(badKey,input[i]))
                continue;
            else
            {
                real+=input[i];
            }
        }
        cout<<real;
    }
    return 0;
}