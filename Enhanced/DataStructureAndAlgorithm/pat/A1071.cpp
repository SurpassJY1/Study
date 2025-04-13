//
// Created by GlokieYu on 25-4-9.
//
/*
思路；
双指针，定位到第一个字母或数字，然后让第二根指针移到非字母和数字的地方，然后让第一根指针移到第二根指针的下一个位子
*/
#include<unordered_map>
#include<iostream>
#include<string>
#include<cctype>
using namespace std;
bool isWord(char c)
{
    if(!isdigit(c)&&!isalpha(c))
        return false;
    return true;
}
int main()
{
    unordered_map<string,int> counter;
    //因为有空格，所以用getline
    string str;
    getline(cin,str);
    for(int i=0;i<str.size();i++)
    {
        if (isWord(str[i])) {
            string word;
            int j=i;
            while(j<str.size()&&isWord(j))
            {
                word+=tolower(str[j]);//题目要小写的
                j++;
            }
            counter[word]++;
            //更新i
            i=j;
        }
    }
    string max_word;
    int max=-1;
    for(auto pair:counter)
    {
       if (max<pair.second||max==pair.second&&max_word<pair.first) {
           max=pair.second;
           max_word=pair.first;
       }
    }
    cout<<max<<" "<<max_word<<endl;
    return 0;
}