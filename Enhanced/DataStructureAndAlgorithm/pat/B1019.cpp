//
// Created by GlokieYu on 25-4-1.
//
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool myCompare(int a,int b) {
    return a>b;
}
int main()
{
    string N;//(0,10000)
    cin>>N;
    vector<int> numN;
    for(int i=0;i<4;i++)
    {
        if (i<=N.size()-1)
        numN.push_back(N[i]-'0');
        else//��0
            numN.push_back(0);
    }
    //����Ƿ�ȫ���
    int a=numN[0];
    bool notSame=false;
    for(int i=1;i<numN.size();i++)
    {
        if(numN[i]!=a)
        {
            notSame=true;
            break;
        }
    }
    if(!notSame)
    {
        cout<<N<<" - "<<N<<"= 0000";
    }
    //����ͬ
    else {
        bool flag=true;
        while (flag) {
            vector<int> first;
            sort(numN.begin(),numN.end(),myCompare);
            first=numN;
            vector<int> second;
            sort(numN.begin(),numN.end());
            second=numN;
            for (int i=0;i<first.size();i++)
                cout<<first[i];
            cout<<" - ";
            for (int i=0;i<second.size();i++)
                cout<<second[i];
            cout<<" = ";
            //���ƴ����ּ��㣬�ӵ�λ��������С��0��λ
            for (int i=3;i>=0;i--) {
                if (first[i]>=second[i]) {
                    numN[i]=first[i]-second[i];
                }else {//��λ
                    first[i-1]--;
                    first[i]+=10;
                    numN[i]=first[i]-second[i];
                }
            }
            //���
            for (int i=0;i<numN.size();i++) {
                cout<<numN[i];
            }
            if (numN[0]==6&&numN[1]==1&&numN[2]==7&&numN[3]==4)
                flag=false;
            cout<<endl;
        }
    }
    return 0;
}