//
// Created by GlokieYu on 25-3-27.
//
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
全排列（无重复元素）
写出几个无重复元素的全排列
做法：回溯剪枝
* */
bool isSolution(vector<int> &state,vector<int> &choices)
{
  return state.size()==choices.size();
}
void recordSolution(vector<int> &state,vector<vector<int>> &res)
{
  res.push_back(state);
}
bool isValid(int choice,unordered_map<int,bool> &selected)
{
  return selected[choice]==false;
}
void makeChoice(vector<int> &state,int choice){
  state.push_back(choice);
}

void undoChoice(unordered_map<int,bool>&selected,vector<int> &state)
{
  selected[state.back()]=false;
  state.pop_back();
}
void backTrack(vector<int>&state,vector<int> &choices,unordered_map<int,bool>&selected,vector<vector<int>>&res)
{
  if(isSolution(state,choices)) {
    res.push_back(state);
  return;
  }
    for(int i=0;i<choices.size();i++)
  {
    if(isValid(choices[i],selected))
      {
      makeChoice(state,choices[i]);
      selected[choices[i]]=true;
      backTrack(state,choices,selected,res);
      undoChoice(selected,state);
      }
  }
}
void allPermutation(vector<int> &n)
{
  unordered_map<int,bool> selected;
  for(int var:n)
  {
    selected[var]=false;
  }
  vector<vector<int>> res;
  vector<int> state;
  backTrack(state,n,selected,res);
  cout<<res.size()<<endl;
  for(vector<int> vars:res)
  {
    cout<<"{";
    for(int var:vars)
    {
      if (var==vars.back()) {
        cout<<var;
        break;
      }
      cout<<var<<",";
    }
    cout<<"}"<<" ";
  }
}
int main()
{
  vector<int> n={1,1};
  allPermutation(n);
  return 0;
}