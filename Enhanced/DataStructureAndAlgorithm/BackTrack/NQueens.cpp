//
// Created by GlokieYu on 25-4-1.
//
#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
逐行放置策略
利用column的bool类型数组来判断同一列是否有皇后存在
利用diags1的bool类型数组判断左向右的对角线是否有皇后存在
利用diag2的bool类型数组判断右向左的对角线是否有皇后存在
左向右的每条对角线上每一个空位row-column是恒定值，范围是【1-n，n-1】
右向左每条对角线上每个空位的row+column是恒定值，范围是【0，2n-2】
所以这个diags1和diags的容量都是2n-1，我们把row-column都加上n-1，这里n-1是个恒定值，为索引最大值防止它小于0
* */
void backtrack(vector<vector<string>> &state,int row,int n,
               vector<vector<vector<string>>>&res,vector<bool>&column,vector<bool>&diags1,vector<bool>&diags2)
{
if(row==n)//到最后一行了
  {
     res.push_back(state);
     return;
  }
  for(int i=0;i<n;i++)//0-column,遍历一行里面的每个元素
  {
    int diag1=row-i+n-1;
    int diag2=row+i;
    if(!column[i]&&!diags1[diag1]&&!diags2[diag2])
    {
      state[row][i]='Q';
      column[i]=true;
      diags1[diag1]=true;
      diags2[diag2]=true;
      backtrack(state,row+1,n,res,column,diags1,diags2);
      state[row][i]='#';//恢复
      column[i]=diags1[diag1]=diags2[diag2]=false;
    }
  }
}
vector<vector<vector<string>>> nQueens(int n)
{
  vector<vector<string>> state(n, vector<string>(n, "#"));
  vector<bool> column(n,false);
  vector<bool> diags1(2*n-1,false);
  vector<bool> diags2(2*n-1,false);
  vector<vector<vector<string>>> res;
  for (vector<string> row:state) {
    for (string elem:row) {
      cout<<elem<<" ";
    }
    cout<<endl;
  }
  backtrack(state,0,n,res,column,diags1,diags2);
  return res;
}
int main()
{
  vector<vector<vector<string>>> res;
  res=nQueens(5);
  for(vector<vector<string>> solution:res)
  {cout<<endl;
    for(vector<string> row:solution)
      {
      for(string element:row)
      {
        cout<<element<<" ";
      }
      cout<<endl;
      }
    cout<<endl;
  }
  return 0;
}