#include<iostream>
#include<vector>
using namespace std;
//以不断加1给C1，直到C2等于C2，算出时钟数差值，除以100就能算出来多少秒了，注意要四舍五入
int main()
{
    int c1,c2;
    cin>>c1>>c2;
    int clock=c2-c1;
    int seconds;
    //这里应该是50进1
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
