//
// Created by GlokieYu on 25-3-28.
//
#include<iostream>
#include<cmath>
using namespace std;
//pow���Լ���һ�������ݣ�double pow��double base��double exponent��
int main()
{
  int A,D_A,B,D_B;
  cin>>A>>D_A>>B>>D_B;
  int countDA=0;//��¼D_A���ִ���
  //����ȡ�࣬��ÿһλ��
  while(A>0)
  {
    if(A%10==D_A)
    {
      countDA++;
    }
    A=A/10;
  }
  //����PA
  int P_A=0;
  int product=1;
  for(int i=0;i<countDA;i++)
  {
    P_A+=D_A*product;//D_A*1+D_A*10^1+D_A*10^2+...+D_A*10^(count-1)�ĵ���,pow�ķ���ֵ��double���ͣ��ǵ�ǿת
    product*=10;
  }
  int P_B=0;
  int countDB=0;
  while(B>0)
  {
    if(B%10==D_B)
      countDB++;
    B=B/10;
  }
  for(int i=countDB;i>0;i--)
  {
    P_B+=D_B*(int)pow(10,i-1);//ͬ��
  }
  cout<<P_B+P_A<<endl;
  return 0;
}