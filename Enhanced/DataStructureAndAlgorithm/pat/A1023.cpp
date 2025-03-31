//
// Created by GlokieYu on 25-3-31.
//
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>//利用map来存储每个数字出现的次数
using namespace std;
//满足仅有排序不同的两个条件：1 新数字的每个数字都在老数字里出现过 2 新数字的每个数字出现的次数和老数字相同
int main()
{
  string  s1;
  cin>>s1;
  vector<int> num(21,0);
  vector<int>count(10,0);
  int findNew=false;
  for(int i=0;i<s1.size();i++)//倒序存入
  {
    num[s1.size()-1-i]=s1[i]-'0';//不要忘记减去0
  }
  for (int i=0;i<s1.size();i++) {//将每一位数字插入
    count[num[i]]++;
  }
  for(int i=0;i<s1.size();i++)
  {
    num[i]*=2;
  }
  for(int i=0;i<s1.size();i++)
  {
  if(num[i]>=10)
   {
    num[i+1]+=num[i]/10;
    num[i]=num[i]%10;
  }
  }
  int index=s1.size()-1;
  vector<int> newCount(10,0);
  if(num[index+1]!=0)
  {
    index++;
  }
  //将新生成的结果的出现次数插入
  for (int i=index;i>=0;i--) {
    newCount[num[i]]++;
  }
  for (int i=0;i<count.size();i++) {
    if (count[i]!=newCount[i]) {
      findNew=true;
      break;
    }
  }
  if (findNew)
    cout<<"No"<<endl;
  else
    cout<<"Yes"<<endl;
  for (int i=index;i>=0;i--) {
    cout<<num[i];
  }
  return 0;
}