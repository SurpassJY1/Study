//
// Created by GlokieYu on 25-3-30.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* ����һ������������ nums ��һ��Ŀ�������� target �����ҳ����п��ܵ���ϣ�ʹ������е�Ԫ�غ͵��� target ��
* �����������ظ�Ԫ�أ�ÿ��Ԫ�ؿ��Ա�ѡȡ��Ρ������б���ʽ������Щ��ϣ��б��в�Ӧ�����ظ���ϡ�
 * */

//��Ϊ���������target��ȥ��ǰchoice����0
//������ȥ�ؾ�Ӧ�����Ӽ��е�Ԫ�ش�С�������У������Ͳ������ǰ��˳��ߵ����ظ��Ӽ�
//�Ż����������nums�������У�ʹ��ǰλ�Ӽ����choice����target���ȫ����֦

void backtrack(vector<int> &state,vector<int>choices,vector<vector<int>>&res,int start,int target)
{
  if(target==0)
  {
    res.push_back(state);
    return;
  }
  for(int i=start;i<choices.size();i++)//��start��ʼ��������ֹ����֮ǰ��Ԫ������ظ�
  {
    if(target-choices[i]<0)
      break;//��֦����Ϊ���������򣬺���Ķ��Ǵ���choices��i����
    state.push_back(choices[i]);
    backtrack(state,choices,res,i,target-choices[i]);//��һ�ִ�i��ʼ�������
    state.pop_back();
  }
}
vector<vector<int>> getSubset(vector<int> nums,int tar)
{
  sort(nums.begin(),nums.end());
  vector<int> state;
  vector<vector<int>>res;
  backtrack(state,nums,res,0,tar);
  return res;
}
int main()
{
  vector<vector<int>> res=getSubset({3,4,5},9);
   for(vector<int> solution:res)
  {  cout<<"{";
     for(int var:solution)
     {
       cout<<var<<" ";
     }
     cout<<"}";
     cout<<endl;
  }
  return 0;
}