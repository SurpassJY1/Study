#include<iostream>
#include<vector>
using namespace std;
//�Բ��ϼ�1��C1��ֱ��C2����C2�����ʱ������ֵ������100����������������ˣ�ע��Ҫ��������
int main()
{
    int c1,c2;
    cin>>c1>>c2;
    int clock=c2-c1;
    int seconds;
    //����Ӧ����50��1
    if(clock%100>=50)
        seconds=clock/100+1;
    else seconds=clock/100;

    int h=0;
    int min=0;
    int s=0;
    h=seconds/3600;
    min=(seconds-h*3600)/60;
    s=seconds-h*3600-min*60;
    string hStr;
    if(h<10)
    {hStr+='0';
        hStr+=to_string(h);
    }else hStr+=to_string(h);
    string mStr;
    if(min<10)
    {mStr+='0';
        mStr+=to_string(min);
    }else mStr+=to_string(min);
    string sStr;
    if(s<10)
    {sStr+='0';
        sStr+=to_string(s);
    }else sStr+=to_string(s);
    cout<<hStr<<":"<<mStr<<":"<<sStr<<endl;
}//
// Created by GlokieYu on 25-4-2.
//
