//
// Created by GlokieYu on 25-4-11.
//
#include<iostream>
#include<string>
#include<vector>

using namespace std;
//��Ϊ����С�ڵ���10�η���������100�Σ������999999999��100�β��������10^10*100����10^12
//��Ȼ���ᳬ��longlong��Χ��������漰��ת���������ø߾��ȼ�������㣬��Ϊvector��ת�ܷ���

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
    //�������
    vector<int> n_vec;
    for(int i=n.size()-1;i>=0;i--)
    {
        n_vec.push_back(n[i]-'0');
    }
    //ֱ�ӷ�ת
    vector<int> reversed_vec(n_vec.rbegin(),n_vec.rend());
    //���
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
    if(isHuiwen(n))//ֱ�Ӿ��ǻ����������ò���
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
        if(!isHuiwen(n))//����Ҫע������պ���k���������������Բ���ֱ��cnt==k
        {
            cout<<n<<endl;
            cout<<k<<endl;
        }
    }
    return 0;
}