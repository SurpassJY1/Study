//
// Created by GlokieYu on 25-4-3.
//
#include<string>
#include<iostream>
#include<unordered_map>//���������¼ÿ���ַ���Ӧ����Ŀ
using namespace std;
bool isValid(string n,unordered_map<char,int> counter)
    //�ж�s��[left,right]֮���Ƿ����n
{
    bool flag=true;
    for(int i=0;i<n.size();i++)
    {
        if(counter.find(n[i])==counter.end())
            flag=false;
        if (i!=n.size()-1) {
            if (counter[n[i]]>counter[n[i+1]]) {

                flag=false;
            }
        }
    }
    return flag;
}
int main()
{
    string s;
    string n;
    unordered_map<char,int>counter;
    cin>>s>>n;
    int left=0;
    int right=0;
    int length=0;
    string res;
    while(right<s.size())//��������
    {
        counter[s[right]]=right;
        counter[s[left]]=left;
        while(isValid(n,counter))//�����������ƶ���ָ��,��������Χ
        {
            if (right-left+1<length||length==0) {
                length=right-left+1;
                res=s.substr(left,left+length);
            }
            left++;
        }
        //������������������ָ������Χ
        right++;
    }
    cout<<counter['a']<<endl;
    cout<<res<<endl;//���ڼ�¼�������ұߵ�ֵ
    return 0;
}