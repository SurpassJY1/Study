//
// Created by GlokieYu on 25-4-10.
//
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    string N;//��ΪN��С��ʮ��100�η���������Χ�ˣ�������string�洢
    cin>>N;
    int sum=0;
    //����N���ҵ�N��ÿһλ���ּӵ�sum��
    for(char c:N)
    {
        sum+=c-'0';
    }
    vector<string> words={"zero","one","two","three","four","five","six","seven","eight","nine"};
    string res=to_string(sum);
    for(int i=0;i<res.size();i++)//�����ַ����������
    {
        if(i==res.size()-1)
            cout<<words[res[i]-'0'];
        else
            cout<<words[res[i]-'0']<<" ";
    }

    return 0;
}