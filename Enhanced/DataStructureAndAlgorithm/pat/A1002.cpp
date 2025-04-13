#include<iostream>

using namespace std;

const int N=1010;

double a[N],b[N],c[N];

int main()
{
  int k;
  cin>>k;

  while(k--)
  {
    int n;
    double val;
    cin>>n>>val;
    a[n]=val;
  }

  k=0;
  cin>>k;

  while(k--)
  {
    int n;
    double val;
    cin>>n>>val;
    b[n]=val;
  }

  for(int i=0;i<N;i++)
  {
    c[i]+=a[i]+b[i];
  }

  k=0;

  for(int i=0;i<N;i++)
  {
    if(c[i])
      k++;
  }

  cout<<k;

  for(int i=N-1;i>=0;i--)
  {
    if(c[i])
      printf(" %d %.1lf",i,c[i]);
  }
}