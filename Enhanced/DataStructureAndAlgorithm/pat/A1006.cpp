//
// Created by GlokieYu on 25-4-10.
//
#include<iostream>
#include<string>
using namespace std;

int main()
{
    //因为时间位数相同，所以比较时间大小直接比较字典序
    string id, in_time,out_time;
    string first_time, last_time;//最早进入和最晚出去的时间
    string first_id,last_id;
    int M;
    cin>>M;
    for(int i=0;i<M;i++)
    {
        cin>>id>>in_time>>out_time;
        if(first_time.empty()||first_time>in_time)
        {
            first_id=id;
            first_time=in_time;
        }
        if(last_time.empty()||last_time<out_time)
        {
            last_id=id;
            last_time=out_time;
        }
    }
    cout<<first_id<<" "<<last_id;
    return 0;
}