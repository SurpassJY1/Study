//
// Created by GlokieYu on 25-4-1.
//
#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
���з��ò���
����column��bool�����������ж�ͬһ���Ƿ��лʺ����
����diags1��bool���������ж������ҵĶԽ����Ƿ��лʺ����
����diag2��bool���������ж�������ĶԽ����Ƿ��лʺ����
�����ҵ�ÿ���Խ�����ÿһ����λrow-column�Ǻ㶨ֵ����Χ�ǡ�1-n��n-1��
������ÿ���Խ�����ÿ����λ��row+column�Ǻ㶨ֵ����Χ�ǡ�0��2n-2��
�������diags1��diags����������2n-1�����ǰ�row-column������n-1������n-1�Ǹ��㶨ֵ��Ϊ�������ֵ��ֹ��С��0
* */
void backtrack(vector<vector<string>> &state,int row,int n,
               vector<vector<vector<string>>>&res,vector<bool>&column,vector<bool>&diags1,vector<bool>&diags2)
{
if(row==n)//�����һ����
  {
     res.push_back(state);
     return;
  }
  for(int i=0;i<n;i++)//0-column,����һ�������ÿ��Ԫ��
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
      state[row][i]='#';//�ָ�
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