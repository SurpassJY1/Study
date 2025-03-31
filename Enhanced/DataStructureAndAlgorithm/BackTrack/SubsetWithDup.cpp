//
// Created by GlokieYu on 25-3-30.
//
/*
* 给定一个正整数数组 nums 和一个目标正整数 target ，请找出所有可能的组合，使得组合中的元素和等于 target 。
* 给定数组可能包含重复元素，每个元素只可被选择一次。请以列表形式返回这些组合，列表中不应包含重复组合。
 * */
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
//思路：用unordered_set来记录插入，过后的相同元素，如果同一位置有相同元素的话剪枝
//和没有重复元素的一样用更新start来保持顺序一致
void backtrack(vector<int>&state,vector<int>choices,vector<vector<int>>&res,int tar,int start)
{
  if(tar==0)
  {
    res.push_back(state);
    return;
  }
  //利用duplicated记录在当前位子插入过的元素
  unordered_set<int> duplicated;
  for(int i=start;i<choices.size();i++)
  {
    if(tar-choices[i]<0)
      break;//后面的元素都不用看了
    if(duplicated.find(choices[i])!=duplicated.end())
      continue;//找到相同元素已经插入过了就跳过相同元素
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