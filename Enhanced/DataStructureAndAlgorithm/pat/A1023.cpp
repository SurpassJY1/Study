//
// Created by GlokieYu on 25-3-31.
//
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>//����map���洢ÿ�����ֳ��ֵĴ���
using namespace std;
//�����������ͬ������������1 �����ֵ�ÿ�����ֶ�������������ֹ� 2 �����ֵ�ÿ�����ֳ��ֵĴ�������������ͬ
int main()
{
  string  s1;
  cin>>s1;
  vector<int> num(21,0);
  vector<int>count(10,0);
  int findNew=false;
  for(int i=0;i<s1.size();i++)//�������
  {
    num[s1.size()-1-i]=s1[i]-'0';//��Ҫ���Ǽ�ȥ0
  }
  for (int i=0;i<s1.size();i++) {//��ÿһλ���ֲ���
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
  //�������ɵĽ���ĳ��ִ�������
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