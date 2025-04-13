//
// Created by GlokieYu on 25-4-12.
//
//��stringstream����һֱ���뵽���һ��Ԫ��
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

        //�пո���getline
        string line;
        getline(cin,line);
        stringstream sstr(line);
        if(line[0]<='9')
        {//�����������
            //stringstream����ֱ��ת����
            int v;
            sstr>>v;
            if(v<13)
                cout<<map[v]<<endl;
            else if(v%13==0)//�պ���13�ĸ�λ
                cout<<map[v/13%13+12]<<endl;
            else cout<<map[v/13%13+12]<<" "<<map[v%13]<<endl;
        }else
        {
            int res=0;
            string word;
            //������ǻ�����
            while(sstr>>word){res+=get(word);}
            cout<<res<<endl;
        }
    }

    return 0;
}