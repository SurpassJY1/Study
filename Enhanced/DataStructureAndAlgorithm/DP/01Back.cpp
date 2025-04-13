//
// Created by GlokieYu on 25-4-8.
//
#include<vector>
#include<iostream>
using namespace std;
//暴力写法
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算01背包问题的结果
     * @param V int整型 背包的体积
     * @param n int整型 物品的个数
     * @param vw int整型vector<vector<>> 第一维度为n,第二维度为2的二维数组,vw[i][0],vw[i][1]分别描述i+1个物品的vi,wi
     * @return int整型
     */
    int knapsack(int V, int n, vector<vector<int> >& vw) {
        // write code here
        if(V==0||n==0)//背包容量为零或者物品放完了
            return 0;
        if(vw[n-1][0]>V)
            return knapsack(V,n-1,vw);//放不下当前物品
        int no=knapsack(V,n-1,vw);//不放东西
        int yes=knapsack(V-vw[n-1][0],n-1,vw)+vw[n-1][1];
        return max(no,yes);
    }
};
class Solution2 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算01背包问题的结果
     * @param V int整型 背包的体积
     * @param n int整型 物品的个数
     * @param vw int整型vector<vector<>> 第一维度为n,第二维度为2的二维数组,vw[i][0],vw[i][1]分别描述i+1个物品的vi,wi
     * @return int整型
     */

    int dfsMem(int V,int n,vector<vector<int>> &vw,vector<vector<int>>&mem)//这里的mem记录了第几个物品和体积，因为相同物品编号下体积不同对应的质量也是不同的
    {
        if(V<=0||n==0)
            return 0;
        //  如果有记录就直接返回
        if(mem[n-1][V]!=-1)
            return mem[n-1][V];
        if(vw[n-1][0]>V)
            return dfsMem(V,n-1,vw,mem);
        int no=dfsMem(V,n-1,vw,mem);
        int yes=dfsMem(V-vw[n-1][0],n-1,vw,mem)+vw[n-1][1];
        mem[n-1][V]=max(no,yes);
        return mem[n-1][V];
    }
    int knapsack(int V, int n, vector<vector<int> >& vw) {
        // write code here
        vector<vector<int>> mem(n,vector<int>(V+1,-1));
        return dfsMem(V,n,vw,mem);
    }
};
class Solution3 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算01背包问题的结果
     * @param V int整型 背包的体积
     * @param n int整型 物品的个数
     * @param vw int整型vector<vector<>> 第一维度为n,第二维度为2的二维数组,vw[i][0],vw[i][1]分别描述i+1个物品的vi,wi
     * @return int整型
     */
    int knapsack(int V, int n, vector<vector<int> >& vw) {
        // write code here
        //用递推关系填充动态规划表
        vector<vector<int>> dp(n+1,vector<int>(V+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=V;j++)
            {
                if(j<vw[i-1][0])
                    dp[i][j]=dp[i-1][j];//跳过
                else
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-vw[i-1][0]]+vw[i-1][1]);//记录上一轮没选和选了的到下一轮的递推结果
            }
        }
        return dp[n][V];
    }
};

class Solution4 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算01背包问题的结果
     * @param V int整型 背包的体积
     * @param n int整型 物品的个数
     * @param vw int整型vector<vector<>> 第一维度为n,第二维度为2的二维数组,vw[i][0],vw[i][1]分别描述i+1个物品的vi,wi
     * @return int整型
     */
    int knapsack(int V, int n, vector<vector<int> >& vw) {
        // write code here
        vector<int> dp(V+1,0);//空间优化
        for(int i=1;i<=n;i++)
        {
            //倒序遍历防止之前的值被覆盖
            for(int j=V;j>=1;j--)
            {
                if(j>=vw[i-1][0])
                {
                    dp[j]=max(dp[j],dp[j-vw[i-1][0]]+vw[i-1][1]);
                }
            }
        }
        return dp[V];
    }
};