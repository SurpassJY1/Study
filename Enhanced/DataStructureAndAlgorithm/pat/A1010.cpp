//
// Created by GlokieYu on 25-4-12.
//
#include<iostream>
#include<string>

using namespace std;

typedef long long LL;
/*
N2是不在【2，36】
N1最大就是十个36，小于36的十一次方，36的11次方是18位的小于long long 的19位，可以用long long存储
*/
LL get(char c)
{
    if(c<='9')
        return c-'0';
    else return c-'a'+10;
}

LL cacl(string n,LL radix)
{
    //秦九潮算法
    LL r=0ll;
    for(int i=0;i<n.size();i++)
    {
        if ((double)r * radix + get(n[i]) > 1e16) return 1e18;//n和r相乘结果longlong可能存不下，因为n1是小于36的11次方的，
        //所以此时一定无解，返回一个比较大的数就行
        r=r*radix+get(n[i]);
    }
    return r;
}

int main()
{
    string n1,n2;//接下来要进制转换所以用string
    int tag,radix;
    cin>>n1>>n2>>tag>>radix;
    if(tag==2)//n1始终是已知进制的那个
        swap(n1,n2);

    LL deci_n1=cacl(n1,radix);

    //N2的进制最小是n1中的最大数字加一，不然没有这个数字，最大是n1的大小，在n2为1时

    LL l=2ll;
    for(char c:n2)
    {
        l=max(l,get(c)+1);
    }

    LL r=max(deci_n1,36ll);//如果在一个字符的时候取的r比n2小，且在n2恰好就是n1转为10进制那么就会错误
    //因为进制是单调递增的，所以可以二分降低时间复杂度，左闭右开的二分查找找的就是最小的符合要求的值

    while(l<r){
        LL mid=l+(r-l)/2;
        if(cacl(n2,mid)<deci_n1)l=mid+1;//mid太小了
        else r=mid;
    }

    if(cacl(n2,r)!=cacl(n1,radix))
        cout<<"Impossible"<<endl;
    else cout<<r<<endl;
    return 0;
}