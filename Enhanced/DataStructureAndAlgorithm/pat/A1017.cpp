//
// Created by GlokieYu on 25-4-10.
//
/*
假设一家银行有 K 个服务窗口。

窗户前面有一条黄线，将等候区分为两部分。

所有客户都必须在黄线后面排队等候，直到轮到他/她服务并且有可用的窗口为止。

假定一个窗口不能被单个客户占用超过 1 小时，即如果某位顾客的业务已经办理了一小时，则立即终止此项业务。

现在给定每个客户的到达时间 T 和业务办理时间 P，请计算所有客户的平均等待时间。

输入格式

第一行包含两个整数 N 和 K，分别表示客户数量以及窗口数量。

接下来 N 行，每行包含两个时间，分别是一个客户的到达时间，用 HH:MM:SS 表示，以及一个客户的业务办理时间 P（单位：分钟）。

HH 在 [00,23] 范围内，MM 和 SS 都在 [00,59] 范围内。

所有客户的到达时间均不相同。

请注意，银行的营业时间为 08:00 至 17:00。

任何人提前到达都必须排队等候至 08:00，而任何人来得太晚（在 17:00:01 或之后到达）都将不被服务也无需计入平均值。

注意只要客户在17:00之前排上队，则即使办理业务时超过17:00，也会被服务。

输出格式

输出平均等待时间（单位：分钟），结果保留一位小数。

注意，从到达银行至开始办理业务这一期间视为等待期间。

数据范围

1≤N≤104,
1≤K≤100

输入样例：

7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10
输出样例：

8.2
* */
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
#include<queue>//在找到最近的一个空窗口的时候用小顶堆
using namespace std;
class Person
{
  public:
    int arrive_time;
    int service_time;
    Person(int h,int minute,int second,int service_time)
    {
      arrive_time=h*3600+minute*60+second;//按照与0点的秒数差存入，在计算差值的时候更方便
      this->service_time=min(service_time*60,3600);//超过60分钟的按60分钟算
    }
};
bool myCompare(Person p1,Person p2)
{
  return p1.arrive_time<p2.arrive_time;
}
int main()
{
  int n,m;
  cin>>n>>m;
  vector<Person> persons;
  for(int i=0;i<n;i++)
  {
    //在格式化输入提取数值的时候用scanf更方便
    int h,min,s,service_time;
    scanf("%02d:%02d:%02d %d",&h,&min,&s,&service_time);
    persons.push_back(Person(h,min,s,service_time));
  }
  //对person进行排序，来找到谁应该最先去接受服务
  sort(persons.begin(),persons.end(),myCompare);

  //定义窗口，因为每次都要找的最先空闲的窗口，所以用priority_queue
  priority_queue<int,vector<int>,greater<int>> windows;
  for(int i=0;i<m;i++)
  {
    windows.push(8*3600);//银行8点开门
  }
  //对于每个人，找到最先空出来的窗口，进去接受服务，窗口的时间更新为开始的时间和服务停止的时间
  int cnt=0,sum=0;
  for(int i=0;i<n;i++)
  {
    Person p=persons[i];
    //如果人到达的时间在五点之后就直接让他滚
    if(p.arrive_time>=17*3600+1)
      break;
    int w=windows.top();
    //对人到达的时间和窗口开始的时间做比较，如果要等就加入sum
    int start_time=max(w,p.arrive_time);
    sum+=start_time-p.arrive_time;
    cnt++;
    windows.pop();
    //更新窗口
    windows.push(start_time+p.service_time);
  }
  double res=(double)sum/cnt/60;
  printf("%.1f",res);
}
