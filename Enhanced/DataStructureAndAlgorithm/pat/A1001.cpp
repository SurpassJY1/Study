//
// Created by GlokieYu on 25-4-10.
//
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int sum=a+b;
    string sstr=to_string(sum);
    string res;
    //倒序遍历，添加在res前面，每三位加一个，如果是最后一位或者前一位是负号就不加
    for(int i=sstr.size()-1,j=0;i>=0;i--)
    {
        res=sstr[i]+res;
        j++;
        if(i!=0&&j%3==0&&sstr[i-1]!='-')
        {res=','+res;
        }
    }
    cout<<res<<endl;
    return 0;
}