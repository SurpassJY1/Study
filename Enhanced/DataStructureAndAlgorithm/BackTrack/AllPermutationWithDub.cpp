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
  //����ͬԪ�ر����������λ�ӹ��������Ԫ�ر�ѡ����ʱ���ѡ���֦
  return !selected[i]&&duplicated.find(choice)==duplicated.end();
}
void makeChoice(vector<int> &state,unordered_set<int>&duplicated,unordered_map<int,bool>&selected,int choice,int i)
{
  selected[i]=true;//�����ظ�Ԫ�ص�����£�ÿ��Ԫ��Ψһ����ݱ�ʶ��������choices�е�����������Ҫ���������ж����Ƿ��Ѿ�����
  //��¼������ͬԪ�ر����������λ����
  duplicated.emplace(choice);
  state.push_back(choice);
}
void undoChoice(vector<int> &state,unordered_map<int,bool>&selected,int i)
{
  state.pop_back();//ɾ�����һ��Ԫ��
  selected[i]=false;//��������Ԫ�ص�״̬Ϊû�����
}
void backtrack(vector<int>&state,vector<int>&choices,vector<vector<int>>&res,unordered_map<int,bool>&selected)
{
  if(isSolution(state,choices))
    {
    recordSolution(state,res);
    return;
    }
    unordered_set<int> duplicated;//���������ѭ���м�¼��ͬԪ���Ƿ��Ѿ���state����ͬλ�Ӳ������
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