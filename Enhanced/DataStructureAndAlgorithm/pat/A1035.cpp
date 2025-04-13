//
// Created by GlokieYu on 25-4-10.
//
/*
想法：设置一个字符串，检查每一位，如果出现难以区分的字母就直接加入替换字母，其余正常插入
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool replace(string pwd,string& res)
{
    bool flag=false;
    for(char c:pwd){
        if(c=='1')
        { res+='@';
            flag=true;
        }
        else if(c=='0')
        {res+='%';
            flag=true;
        }
        else if(c=='l')
        {res+='L';
            flag=true;
        }
        else if(c=='O')
        {res+='o';
            flag=true;
        }
        else {res+=c;
        }
    }
    return flag;
}
int main()
{
    int N;
    cin>>N;
    string id,pwd;
    int M=0;
    vector<string> ans;
    for(int i=0;i<N;i++)
    {
        string res;
        cin>>id>>pwd;
        if(replace(pwd,res))
        {
            M++;
            string elem=id;
            elem+=' ';
            elem+=res;
            ans.push_back(elem);
            res.clear();
        }
    }
    if(M==0&&N==1)
        cout<<"There is 1 account and no account is modified"<<endl;
    else if(M==0&&N>1)
        cout<<"There are "<<N<<" accounts and no account is modified"<<endl;
    else
    {
        cout<<M<<endl;
        for(string elem:ans)
        {
            cout<<elem<<endl;
        }
    }
    return 0;
}