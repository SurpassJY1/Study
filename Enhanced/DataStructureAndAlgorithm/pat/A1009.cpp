//
// Created by GlokieYu on 25-4-11.
//
#include<iostream>

using namespace std;

const int N=1010;

double a[N],b[N],c[2*N];

int main()
{

    int k;
    cin>>k;

    while(k--)
    {
        int n;
        double val;
        cin>>n>>val;
        a[n]=val;
    }

    k=0;
    cin>>k;

    while(k--)
    {
        int n;
        double val;
        cin>>n>>val;
        b[n]=val;
    }

    //将a的每一项和b的每一项相乘，指数相加，系数相乘

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            c[i+j]+=a[i]*b[j];//这里要加等于，如果直接用等于会被后面的值覆盖
        }
    }

    k=0;

    for(int i=0;i<2*N;i++)
    {
        if(c[i])
            k++;
    }

    cout<<k;

    for(int i=2*N-1;i>=0;i--)
    {
        if(c[i])
            printf(" %d %.1lf",i,c[i]);
    }
    return 0;
}