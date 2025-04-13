//
// Created by GlokieYu on 25-4-2.
//
#include<iostream>
#include<vector>
using namespace std;
/*
* ：描述决策，定义状态，建立  表，推导状态转移方程，确定边界条件等。
 * */
class Solution {
public:
    //从第三级楼梯开始，每一级的都是从前两级跳上来或者前一级跳上来的，所以他的解就为前两集的解加上前一级的解
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
    //从第三级楼梯开始，每一级的都是从前两级跳上来或者前一级跳上来的，所以他的解就为前两集的解加上前一级的解
    int climbStairs(int n) {
        if(n==1||n==2)
            return n;
        //因为这里的解之和前面一个数还有前面两个数有关，所以可以将变量滚动
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