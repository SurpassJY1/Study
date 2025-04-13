//
// Created by GlokieYu on 25-4-1.
//
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//1����Ӯ�ˣ�2����ƽ�֣�0��������
int judge(char jiaAct,char yiAct)
{
    if(jiaAct=='C'&&yiAct=='J')
        return 1;
    else if(jiaAct=='J'&&yiAct=='B')
        return 1;
    else if(jiaAct=='B'&&yiAct=='C')
        return 1;
    else if(jiaAct==yiAct)
        return 2;
    else return 0;
}

int main()
{
    int N;//����
    cin>>N;
    vector<char> jia;
    vector<char> yi;
    unordered_map<char,int> jiaTimes;//��¼ÿ���ж����ִ���
    unordered_map<char,int> yiTimes;
    for(int i=0;i<N;i++)
    {
        char jiaAct;
        char yiAct;
        cin>>jiaAct>>yiAct;
        jia.push_back(jiaAct);
        yi.push_back(yiAct);
    }
    //�������
    int jiaWin=0,pin=0,jiaLose=0;
    for(int i=0;i<N;i++)
    {
        if(judge(jia[i],yi[i])==1)
        {
            jiaWin++;
            if(jiaTimes.find(jia[i])==jiaTimes.end())
            {
                jiaTimes.insert(make_pair(jia[i],1));
            }else
            {
                jiaTimes[jia[i]]++;
            }
        }
        else if(judge(jia[i],yi[i])==2)
            pin++;
        else {
            jiaLose++;
            if(yiTimes.find(yi[i])==yiTimes.end())
            {
                yiTimes.insert(make_pair(yi[i],1));
            }else
            {
                yiTimes[yi[i]]++;
            }
        }
    }
    cout<<jiaWin<<" "<<pin<<" "<<jiaLose<<endl;
    cout<<jiaLose<<" "<<pin<<" "<<jiaWin<<endl;
    //�ֵ���Ӵ�С���Ƚϣ����������ͬ����������Ҳ���ֵ���С���Ǹ�
    char maxJia='J';
    if (jiaTimes[maxJia]<=jiaTimes['C'])
        maxJia='C';
    if (jiaTimes[maxJia]<=jiaTimes['B'])
        maxJia='B';
    char maxYi='J';
    if (yiTimes[maxYi]<=yiTimes['C'])
        maxYi='C';
    if (yiTimes[maxYi]<=yiTimes['B'])
        maxYi='B';
    cout<<maxJia<<" "<<maxYi;
    return 0;
}