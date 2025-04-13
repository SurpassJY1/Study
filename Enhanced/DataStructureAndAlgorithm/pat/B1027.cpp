#include<iostream>
#include<cmath>
using namespace std;
/*
每行输出奇数个符号，相邻差2，从大到小递减到1再递增，
*/
int main()
{
    int N;
    char sign;
    cin>>N>>sign;
    //因为除了中间那个1以外上下对称，所以肯定是个奇数
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
