//
// Created by GlokieYu on 25-4-3.
//
#include<string>
#include<iostream>
#include<unordered_map>//用这个来记录每个字符对应的数目
using namespace std;
bool isValid(string n,unordered_map<char,int> counter)
    //判断s在[left,right]之间是否包含n
{
    bool flag=true;
    for(int i=0;i<n.size();i++)
    {
        if(counter.find(n[i])==counter.end())
            flag=false;
        if (i!=n.size()-1) {
            if (counter[n[i]]>counter[n[i+1]]) {

                flag=false;
            }
        }
    }
    return flag;
}
int main()
{
    string s;
    string n;
    unordered_map<char,int>counter;
    cin>>s>>n;
    int left=0;
    int right=0;
    int length=0;
    string res;
    while(right<s.size())//滑动窗口
    {
        counter[s[right]]=right;
        counter[s[left]]=left;
        while(isValid(n,counter))//符合条件，移动左指针,来收缩范围
        {
            if (right-left+1<length||length==0) {
                length=right-left+1;
                res=s.substr(left,left+length);
            }
            left++;
        }
        //不符合条件，右移右指针增大范围
        right++;
    }
    cout<<counter['a']<<endl;
    cout<<res<<endl;//现在记录的是最右边的值
    return 0;
}