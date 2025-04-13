#include<cmath>
#include<climits>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int dfs(vector<vector<int>>&grid,int i,int j)
    {
        //��������
        if(i==0&&j==0)
            return grid[0][0];
        if(i<0||j<0)//Խ�磬��������,֮�������жϼ�֦
            return INT_MAX;
        int left=dfs(grid,i,j-1);
        int up=dfs(grid,i-1,j);
        return min(left,up)!=INT_MAX? min(left,up)+grid[i][j]:INT_MAX;
    }
    int minPathSum(vector<vector<int>>& grid) {
        return dfs(grid,grid.size()-1,grid[grid.size()-1].size()-1);
    }
};

class Solution2 {
public:
    //���ü��仯���������Ч��
    int dfs(vector<vector<int>>&grid,vector<vector<int>>&mem,int i,int j)
    {
        if(i==0&&j==0)
        {
            mem[i][j]=grid[i][j];
            return mem[i][j];
        }
        if(i<0||j<0)
        {
            return INT_MAX;
        }
        //����Ѿ��д洢�ˣ���ô��ֱ��ȡ����,��ǰ��֦
        if(mem[i][j]!=-1)
            return mem[i][j];
        int left=dfs(grid,mem,i,j-1);
        int right=dfs(grid,mem,i-1,j);
        //�ҵ���ǰ�ڵ��Ӧ���ۻ�ֵ���Ҽ�¼
        int minNum=min(left,right)!=INT_MAX?min(left,right)+grid[i][j]:INT_MAX;
        mem[i][j]=minNum;
        return minNum;
    }
    int minPathSum(vector<vector<int>>& grid) {

        vector<vector<int>> mem(grid.size());
        for(int i=0;i<grid.size();i++)
        {
            mem[i].resize(grid[i].size(),-1);
        }
        return dfs(grid,mem,grid.size()-1,grid[grid.size()-1].size()-1);
    }
};
class Solution3 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //��̬�滮
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        dp[0][0]=grid[0][0];
        //��ʼ����һ��
        for(int i=1;i<n;i++)
        {
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        //��ʼ����һ��
        for(int i=1;i<m;i++)
        {
            dp[0][i]=grid[0][i]+dp[0][i-1];
        }
        //��ʼ��ʣ�ಿ��
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[n-1][m-1];
    }
};
class Solution4 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> dp(m);
        //��һ�е���ֵ
        dp[0]=grid[0][0];
        for(int i=1;i<m;i++)
        {
            dp[i]=grid[0][i]+dp[i-1];
        }
        for(int i=1;i<n;i++)//������
        {
            //����dp��Ӧ���е���ʼֵ
            dp[0]=dp[0]+grid[i][0];
            for(int j=1;j<m;j++)
            {
                dp[j]=min(dp[j-1],dp[j])+grid[i][j];//dp���¼������һ�е�j-1��ֵ����һ��j֮���ֵ
            }
        }
        //������dp���Ѿ�ȫ��Ϊ���һ�е�ֵ
        return dp[m-1];
    }
};
int main() {
    vector<vector<int>> grid={{1,2},{5,6},{1,1}};
    Solution3 s;
    cout<<s.minPathSum(grid);
    return 0;
}