//
// Created by GlokieYu on 25-3-30.
//
/*
* ����һ������������ nums ��һ��Ŀ�������� target �����ҳ����п��ܵ���ϣ�ʹ������е�Ԫ�غ͵��� target ��
* ����������ܰ����ظ�Ԫ�أ�ÿ��Ԫ��ֻ�ɱ�ѡ��һ�Ρ������б���ʽ������Щ��ϣ��б��в�Ӧ�����ظ���ϡ�
 * */
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
//˼·����unordered_set����¼���룬�������ͬԪ�أ����ͬһλ������ͬԪ�صĻ���֦
//��û���ظ�Ԫ�ص�һ���ø���start������˳��һ��
void backtrack(vector<int>&state,vector<int>choices,vector<vector<int>>&res,int tar,int start)
{
  if(tar==0)
  {
    res.push_back(state);
    return;
  }
  //����duplicated��¼�ڵ�ǰλ�Ӳ������Ԫ��
  unordered_set<int> duplicated;
  for(int i=start;i<choices.size();i++)
  {
    if(tar-choices[i]<0)
      break;//�����Ԫ�ض����ÿ���
    if(duplicated.find(choices[i])!=duplicated.end())
      continue;//�ҵ���ͬԪ���Ѿ�������˾�������ͬԪ��
    state.push_back(choices[i]);
    duplicated.emplace(choices[i]);
    backtrack(state,choices,res,tar-choices[i],i);
    state.pop_back();
  }
}
vector<vector<int>> getSubset(vector<int> nums,int tar)
{
  vector<int> state;
  vector<vector<int>> res;
  sort(nums.begin(),nums.end());
  backtrack(state,nums,res,tar,0);
  return res;
}
int main()
{
  vector<vector<int>>res;
  res=getSubset({4,5,4},9);
  for(vector<int> solution:res)
  {
    cout<<"{";
  for(int var:solution)
    {
    cout<<var<<" ";
    }
    cout<<"}";
  }
  return 0;
}