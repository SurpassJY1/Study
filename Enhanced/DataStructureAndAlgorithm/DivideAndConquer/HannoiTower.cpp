//
// Created by GlokieYu on 25-3-27.
//
#include<iostream>
#include<vector>
using namespace std;
void printState(vector<int>&src,vector<int>&buff,vector<int>&tar)
{
cout<<"Src: "<<endl;
  for (int var:src)cout<<var<<" ";
  cout<<endl;
  cout<<"Buff"<<endl;
  for (int var:buff)cout<<var<<" ";
  cout<<endl;
  cout<<"Tar"<<endl;
  for (int var:tar)cout<<var<<" ";
  cout<<endl;
}
void move(vector<int> &src,vector<int> &tar)
{
  int temp=src.back();
  src.pop_back();
  tar.push_back(temp);
}
void hannoTower(int n,vector<int> &src,vector<int> &buff,vector<int> &tar)
{
  if(n==1)
    {move(src,tar);
    printState(src,buff,tar);
  return;}
  hannoTower(n-1,src,tar,buff);
  printState(src,buff,tar);
  move(src,tar);
  hannoTower(n-1,buff,src,tar);
}
void solution(vector<int> &src,vector<int>& buff,vector<int> &tar)
{
  hannoTower(src.size(),src,buff,tar);
}
int main()
{
  vector<int> src;
  for (int i=64;i>0;i--) {
    src.push_back(i);
  }
  vector<int> tar;
  vector<int> buff;
  solution(src,buff,tar);
  return 0;
}