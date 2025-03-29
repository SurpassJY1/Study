//
// Created by GlokieYu on 25-3-29.
//
#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

bool isSolution(vector<int> &state,vector<int> &choices){
  return state.size()==choices.size();
}
void recordSolution(vector<int> &state,vector<vector<int>> &res)
{
  res.push_back(state);
}
bool isValid(unordered_map<int,bool>selected,unordered_set<int> duplicated ,int choice,int i)
{
  //当相同元素被插入在这个位子过或者这个元素被选过的时候就选择剪枝
  return !selected[i]&&duplicated.find(choice)==duplicated.end();
}
void makeChoice(vector<int> &state,unordered_set<int>&duplicated,unordered_map<int,bool>&selected,int choice,int i)
{
  selected[i]=true;//在有重复元素的情况下，每个元素唯一的身份标识就是他在choices中的索引，所以要利用索引判断他是否已经插入
  //记录下来相同元素被插入在这个位子了
  duplicated.emplace(choice);
  state.push_back(choice);
}
void undoChoice(vector<int> &state,unordered_map<int,bool>&selected,int i)
{
  state.pop_back();//删除最后一个元素
  selected[i]=false;//设置最后的元素的状态为没插过的
}
void backtrack(vector<int>&state,vector<int>&choices,vector<vector<int>>&res,unordered_map<int,bool>&selected)
{
  if(isSolution(state,choices))
    {
    recordSolution(state,res);
    return;
    }
    unordered_set<int> duplicated;//用这个来在循环中记录相同元素是否已经在state的相同位子插入过了
  for(int i=0;i<choices.size();i++)
    {
    if(isValid(selected,duplicated,choices[i],i))
    {
      makeChoice(state,duplicated,selected,choices[i],i);
      backtrack(state,choices,res,selected);
      undoChoice(state,selected,i);
    }
    }
}
vector<vector<int>> getAllPermutation(vector<int>choices)
{
  vector<int> state={};
  unordered_map<int,bool>selected;
  for(int i=0;i<choices.size();i++)
  {
    selected[i]=false;
  }
  vector<vector<int>> res;
  backtrack(state,choices,res,selected);
  return res;
}
int main()
{
  vector<int> choices={1,1,2};
  vector<vector<int>> res;
  res=getAllPermutation(choices);
  for(vector<int> solution:res)
  {
    cout<<"{";
    for(int num:solution){
      cout<<" "<<num;
    }
    cout<<"}";
  }
  return 0;
}