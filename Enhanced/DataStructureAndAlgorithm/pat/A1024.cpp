//
// Created by GlokieYu on 25-4-11.
//
#include<iostream>
#include<string>
#include<vector>

using namespace std;
//因为整数小于等于10次方，操作有100次，如果是999999999的100次操作后就是10^10*100等于10^12
//虽然不会超过longlong范围但是这个涉及反转操作还是用高精度计算更方便，因为vector反转很方便

bool isHuiwen(string s)
{
    for(int i=0,j=s.size()-1;i<j;i++,j--)
    {
        if(s[i]!=s[j])
            return false;
    }
    return true;
}

string reversePlus(string n)
{
    //倒序插入
    vector<int> n_vec;
    for(int i=n.size()-1;i>=0;i--)
    {
        n_vec.push_back(n[i]-'0');
    }
    //直接反转
    vector<int> reversed_vec(n_vec.rbegin(),n_vec.rend());
    //相加
    int t=0;
    string res;
    for(int i=0;i<n_vec.size()||i<reversed_vec.size()||t;i++)
    {
        int s=t;
        if(i<n_vec.size()) s+=n_vec[i];
        if(i<reversed_vec.size()) s+=reversed_vec[i];
        res=(char)(s%10+'0')+res;
        t=s/10;
    }
    return res;
}

int main()
{
    string n;
    int k;
    cin>>n>>k;
    if(isHuiwen(n))//直接就是回文数，不用操作
    {
        cout<<n<<endl;
        cout<<"0"<<endl;
    }else{
        int cnt=0;

        while(cnt<k)
        {
            n=reversePlus(n);
            cnt++;
            if(isHuiwen(n))
            {
                cout<<n<<endl;
                cout<<cnt<<endl;
                break;
            }
        }
        if(!isHuiwen(n))//这里要注意如果刚好是k出来回文数，所以不能直接cnt==k
        {
            cout<<n<<endl;
            cout<<k<<endl;
        }
    }
    return 0;
}