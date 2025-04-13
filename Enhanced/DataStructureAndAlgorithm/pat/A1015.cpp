//
// Created by GlokieYu on 25-4-12.
//
#include<iostream>
#include<algorithm>
#include<vector>
 using namespace std;

typedef long long LL;

bool isPrim(LL n)
{
    if(n<2)
        return false;
    if(n==2)
        return true;
    if(n%2==0)
        return false;
    for(int i=3;i*i<=n;i+=2)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

LL toD(int n,int d)
{
    vector<int>res;
    while(n)//这里就已经是反向插入了
    {
        res.push_back(n%d);
        n/=d;
    }
    LL t=0;
    for(int i=0;i<res.size();i++)
    {
        t=t*d+res[i];
    }
    return t;
}

int main()
{
    int n;

    while(cin>>n,n>0)
    {
        int d;
        cin>>d;
        if(!isPrim((LL)n))
            cout<<"No"<<endl;
        else
        {

            if(isPrim(toD(n,d)))
                cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}