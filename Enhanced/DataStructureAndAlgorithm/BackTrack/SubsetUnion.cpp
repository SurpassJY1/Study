//
// Created by GlokieYu on 25-3-29.
//
/*
*
 * */
#include<iostream>
#include<vector>
using namespace std;

bool isSolution(int total,int target)
{
return total==target;
}
void recordSolution(vector<int>&state,vector<vector<int>>&res)
{
  res.push_back(state);
}
bool isValid(int total,int choice,int target)
{
  //当当前元素加上已经有的total之后如果大于target，剪枝
  int totalNext=choice+total;
  return totalNext<=target;
}
void makeChoice(vector<int>&state,int &total,int choice)
{
  state.push_back(choice);
  //增加total值
  total+=choice;
}
void undoChoice(vector<int>&state,int &total)
{
  int rear=state.back();
  total-=rear;
  state.pop_back();
}
void traceback(vector<int>&state,vector<int>&choices,int target,int total,vector<vector<int>>&res)
{
  if(isSolution(total,target))
    {
    res.push_back(state);
    return;
    }
    for(int choice:choices)
    {
      if(isValid(total,choice,target))
      {
        makeChoice(state,total,choice);
        traceback(state,choices,target,total,res);
        undoChoice(state,total);
      }
    }
}
vector<vector<int>> getSubset(vector<int> vec,int tar)
{
  vector<vector<int>> res;
  vector<int> state;
  int total=0;
  traceback(state,vec,tar,total,res);
  return res;
}
int main()
{
  vector<int> vec={3,4,5};
  vector<vector<int>> res=getSubset(vec,9);
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