//
// Created by GlokieYu on 25-4-12.
//
//用stringstream可以一直输入到最后一个元素
#include<iostream>
#include<sstream>//stringstream

using namespace std;

char map[][5]={
    "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec",
    "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"
};

int get(string word)
{
    for(int i=0;i<25;i++)
    {
        if(map[i]==word&&i<13)
            return i;
        else if(map[i]==word&&i>=13) return 13*(i-12);
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    getchar();
    for(int i=0;i<n;i++)
    {

        //有空格用getline
        string line;
        getline(cin,line);
        stringstream sstr(line);
        if(line[0]<='9')
        {//输入的是数字
            //stringstream可以直接转数字
            int v;
            sstr>>v;
            if(v<13)
                cout<<map[v]<<endl;
            else if(v%13==0)//刚好是13的高位
                cout<<map[v/13%13+12]<<endl;
            else cout<<map[v/13%13+12]<<" "<<map[v%13]<<endl;
        }else
        {
            int res=0;
            string word;
            //输入的是火星数
            while(sstr>>word){res+=get(word);}
            cout<<res<<endl;
        }
    }

    return 0;
}