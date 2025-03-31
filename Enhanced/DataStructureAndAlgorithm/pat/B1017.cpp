#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    string A;
    int B;
    cin>>A>>B;
    vector<int> numA(1001,0);
    vector<int> res(1001,0);
    for(int i=0;i<A.size();i++)
    {
        numA[i]=A[i]-'0';
    }
    int t=0;
    for(int i=0;i<A.size();i++)
    {
        t=t*10+numA[i];
        if(t>=B)
        {
            res[i]=t/B;
            t=t%B;
        }else
        {
            res[i]=0;
        }
    }
    int index=0;
    while(index<A.size()&&res[index]==0)//防止商为0一直往后找导致越界
        index++;
    if(index==A.size())
    {cout<<"0";}
    else{
        for(int i=index;i<A.size();i++)
        {
                cout<<res[i];
        }
    }
    cout<<" "<<t;
    return 0;
}