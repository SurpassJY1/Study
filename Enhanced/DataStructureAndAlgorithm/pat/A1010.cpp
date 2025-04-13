//
// Created by GlokieYu on 25-4-12.
//
#include<iostream>
#include<string>

using namespace std;

typedef long long LL;
/*
N2�ǲ��ڡ�2��36��
N1������ʮ��36��С��36��ʮһ�η���36��11�η���18λ��С��long long ��19λ��������long long�洢
*/
LL get(char c)
{
    if(c<='9')
        return c-'0';
    else return c-'a'+10;
}

LL cacl(string n,LL radix)
{
    //�ؾų��㷨
    LL r=0ll;
    for(int i=0;i<n.size();i++)
    {
        if ((double)r * radix + get(n[i]) > 1e16) return 1e18;//n��r��˽��longlong���ܴ治�£���Ϊn1��С��36��11�η��ģ�
        //���Դ�ʱһ���޽⣬����һ���Ƚϴ��������
        r=r*radix+get(n[i]);
    }
    return r;
}

int main()
{
    string n1,n2;//������Ҫ����ת��������string
    int tag,radix;
    cin>>n1>>n2>>tag>>radix;
    if(tag==2)//n1ʼ������֪���Ƶ��Ǹ�
        swap(n1,n2);

    LL deci_n1=cacl(n1,radix);

    //N2�Ľ�����С��n1�е�������ּ�һ����Ȼû��������֣������n1�Ĵ�С����n2Ϊ1ʱ

    LL l=2ll;
    for(char c:n2)
    {
        l=max(l,get(c)+1);
    }

    LL r=max(deci_n1,36ll);//�����һ���ַ���ʱ��ȡ��r��n2С������n2ǡ�þ���n1תΪ10������ô�ͻ����
    //��Ϊ�����ǵ��������ģ����Կ��Զ��ֽ���ʱ�临�Ӷȣ�����ҿ��Ķ��ֲ����ҵľ�����С�ķ���Ҫ���ֵ

    while(l<r){
        LL mid=l+(r-l)/2;
        if(cacl(n2,mid)<deci_n1)l=mid+1;//mid̫С��
        else r=mid;
    }

    if(cacl(n2,r)!=cacl(n1,radix))
        cout<<"Impossible"<<endl;
    else cout<<r<<endl;
    return 0;
}