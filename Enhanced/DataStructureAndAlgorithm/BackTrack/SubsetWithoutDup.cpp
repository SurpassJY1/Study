//
// Created by GlokieYu on 25-3-30.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* 给定一个正整数数组 nums 和一个目标正整数 target ，请找出所有可能的组合，使得组合中的元素和等于 target 。
* 给定数组无重复元素，每个元素可以被选取多次。请以列表形式返回这些组合，列表中不应包含重复组合。
 * */

//成为解的条件：target减去当前choice等于0
//对数组去重就应该让子集中的元素从小到大排列，这样就不会出现前后顺序颠倒的重复子集
//优化：将输入的nums进行排列，使当前位子加入的choice大于target后的全部剪枝

void backtrack(vector<int> &state,vector<int>choices,vector<vector<int>>&res,int start,int target)
{
  if(target==0)
  {
    res.push_back(state);
    return;
  }
  for(int i=start;i<choices.size();i++)//从start开始遍历，防止加入之前的元素造成重复
  {
    if(target-choices[i]<0)
      break;//剪枝，因为数组已排序，后面的都是大于choices【i】的
    state.push_back(choices[i]);
    backtrack(state,choices,res,i,target-choices[i]);//下一轮从i开始往后遍历
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