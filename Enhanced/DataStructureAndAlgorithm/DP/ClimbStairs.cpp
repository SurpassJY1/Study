//
// Created by GlokieYu on 25-4-2.
//
#include<iostream>
#include<vector>
using namespace std;
/*
* ���������ߣ�����״̬������  ���Ƶ�״̬ת�Ʒ��̣�ȷ���߽������ȡ�
 * */
class Solution {
public:
    //�ӵ�����¥�ݿ�ʼ��ÿһ���Ķ��Ǵ�ǰ��������������ǰһ���������ģ��������Ľ��Ϊǰ�����Ľ����ǰһ���Ľ�
    int climbStairs(int n) {
        if(n==1||n==2)
            return n;
        vector<int>dp(n+1);
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
class Solution2 {
public:
    //�ӵ�����¥�ݿ�ʼ��ÿһ���Ķ��Ǵ�ǰ��������������ǰһ���������ģ��������Ľ��Ϊǰ�����Ľ����ǰһ���Ľ�
    int climbStairs(int n) {
        if(n==1||n==2)
            return n;
        //��Ϊ����Ľ�֮��ǰ��һ��������ǰ���������йأ����Կ��Խ���������
        int a=1;
        int b=2;
        int res=0;
        for(int i=3;i<=n;i++)
        {
            res=a+b;
            a=b;
            b=res;
        }
        return res;
    }
};