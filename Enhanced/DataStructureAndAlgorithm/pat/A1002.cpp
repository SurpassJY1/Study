//
// Created by GlokieYu on 25-3-28.
//
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
  int exp;
  double coe;
  int K,K2;
  cin>>K;
  vector<double> vec;
  vec.resize(1001,0);
  for(int i=0;i<K;i++)
  {
    cin>>exp>>coe;
    vec[exp]+=coe;
  }
  cin>>K2;
  for(int i=0;i<K2;i++)
  {
    cin>>exp>>coe;
    vec[exp]+=coe;
  }
  int count=0;
  int maxExp=-1;
  for (int i=0;i<vec.size();i++) {
    if (vec[i]!=0) {
      count++;
      maxExp=i;
    }
  }
  if (count==0) {
    cout<<count;
  }else cout<<count<<" ";
  int num=0;
  for(int i=maxExp;i>=0;i--)//从maxExp开始往下，降低时间复杂度
  {
    if (vec[i]!=0) {
      if (num+1==count) {
        cout<<i<<" "<<fixed<<setprecision(1)<<vec[i];
        break;
      }
      cout<<i<<" "<<fixed<<setprecision(1)<<vec[i]<<" ";
      num++;
    }
  }
  return 0;
}