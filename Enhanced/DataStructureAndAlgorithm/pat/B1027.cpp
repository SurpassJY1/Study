#include<iostream>
#include<cmath>
using namespace std;
/*
ÿ��������������ţ����ڲ�2���Ӵ�С�ݼ���1�ٵ�����
*/
int main()
{
    int N;
    char sign;
    cin>>N>>sign;
    //��Ϊ�����м��Ǹ�1�������¶Գƣ����Կ϶��Ǹ�����
    int extra=0;
    int height=sqrt(2*N+2)-1;
    int count=0;
    int width=height;
    int level=0;
    if (N<7) {
        cout<<N<<endl;
    }
    else {
        while(width>1)
        {
            for(int i=0;i<width;i++)
            {
                cout<<sign;
                count++;
            }
            cout<<endl;
            level++;
            for (int i=0;i<level;i++)
                cout<<" ";
            width-=2;
        }
        cout<<sign;
        count++;
        width+=2;
        level--;
        cout<<endl;
        while (width<=height) {
            for (int i=0;i<level;i++) {
                cout<<" ";
            }
            for (int i=0;i<width;i++) {
                cout<<sign;
                count++;
            }
            width+=2;
            level--;
            cout<<endl;
        }
        cout<<N-count<<endl;
    }
    return 0;
}//
// Created by GlokieYu on 25-4-2.
//
