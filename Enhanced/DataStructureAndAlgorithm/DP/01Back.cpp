//
// Created by GlokieYu on 25-4-8.
//
#include<vector>
#include<iostream>
using namespace std;
//����д��
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * ����01��������Ľ��
     * @param V int���� ���������
     * @param n int���� ��Ʒ�ĸ���
     * @param vw int����vector<vector<>> ��һά��Ϊn,�ڶ�ά��Ϊ2�Ķ�ά����,vw[i][0],vw[i][1]�ֱ�����i+1����Ʒ��vi,wi
     * @return int����
     */
    int knapsack(int V, int n, vector<vector<int> >& vw) {
        // write code here
        if(V==0||n==0)//��������Ϊ�������Ʒ������
            return 0;
        if(vw[n-1][0]>V)
            return knapsack(V,n-1,vw);//�Ų��µ�ǰ��Ʒ
        int no=knapsack(V,n-1,vw);//���Ŷ���
        int yes=knapsack(V-vw[n-1][0],n-1,vw)+vw[n-1][1];
        return max(no,yes);
    }
};
class Solution2 {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * ����01��������Ľ��
     * @param V int���� ���������
     * @param n int���� ��Ʒ�ĸ���
     * @param vw int����vector<vector<>> ��һά��Ϊn,�ڶ�ά��Ϊ2�Ķ�ά����,vw[i][0],vw[i][1]�ֱ�����i+1����Ʒ��vi,wi
     * @return int����
     */

    int dfsMem(int V,int n,vector<vector<int>> &vw,vector<vector<int>>&mem)//�����mem��¼�˵ڼ�����Ʒ���������Ϊ��ͬ��Ʒ����������ͬ��Ӧ������Ҳ�ǲ�ͬ��
    {
        if(V<=0||n==0)
            return 0;
        //  ����м�¼��ֱ�ӷ���
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
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * ����01��������Ľ��
     * @param V int���� ���������
     * @param n int���� ��Ʒ�ĸ���
     * @param vw int����vector<vector<>> ��һά��Ϊn,�ڶ�ά��Ϊ2�Ķ�ά����,vw[i][0],vw[i][1]�ֱ�����i+1����Ʒ��vi,wi
     * @return int����
     */
    int knapsack(int V, int n, vector<vector<int> >& vw) {
        // write code here
        //�õ��ƹ�ϵ��䶯̬�滮��
        vector<vector<int>> dp(n+1,vector<int>(V+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=V;j++)
            {
                if(j<vw[i-1][0])
                    dp[i][j]=dp[i-1][j];//����
                else
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-vw[i-1][0]]+vw[i-1][1]);//��¼��һ��ûѡ��ѡ�˵ĵ���һ�ֵĵ��ƽ��
            }
        }
        return dp[n][V];
    }
};

class Solution4 {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * ����01��������Ľ��
     * @param V int���� ���������
     * @param n int���� ��Ʒ�ĸ���
     * @param vw int����vector<vector<>> ��һά��Ϊn,�ڶ�ά��Ϊ2�Ķ�ά����,vw[i][0],vw[i][1]�ֱ�����i+1����Ʒ��vi,wi
     * @return int����
     */
    int knapsack(int V, int n, vector<vector<int> >& vw) {
        // write code here
        vector<int> dp(V+1,0);//�ռ��Ż�
        for(int i=1;i<=n;i++)
        {
            //���������ֹ֮ǰ��ֵ������
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