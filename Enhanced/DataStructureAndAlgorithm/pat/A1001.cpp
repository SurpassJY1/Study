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
    //��������������resǰ�棬ÿ��λ��һ������������һλ����ǰһλ�Ǹ��žͲ���
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