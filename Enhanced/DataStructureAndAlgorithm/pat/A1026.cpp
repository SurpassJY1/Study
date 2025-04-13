//
// Created by GlokieYu on 25-4-10.
//
/*
一个乒乓球俱乐部共有 K 张乒乓球台，编号为 1?K。

对于任意一对球员，当他们到达时如果有多个球台可用，那么他们就会被安排到编号较小的那个球台上打球。

如果所有球台都被占用了，他们就只能排队等待了。

假设每对球员最多只允许打两小时球。

你需要计算每个排队等候的人的等待时间以及每个球台当天有多少对球员在上面打球。

另外，让这个事情变得复杂的是，俱乐部为 VIP 球员保留了一些球台。

当一个 VIP 球台空出时，等待队伍中的第一对 VIP 球员将优先使用这个球台。

如果此时等待队伍中没有 VIP，则排在等待队伍的第一对球员可以使用这个球台。

另一方面，当轮到一对 VIP 球员打球时，如果没有 VIP 球台可用，那么他们将被视作普通球员处理。

补充：

1、当等待队伍中有 VIP 球员并且有空闲 VIP 球台时，必须优先分配 VIP 球员，并且必须分配他们 VIP 球台（优先分配编号较小的），直至 VIP 用户或 VIP 球台分配完为止。
2、期望打球时间超过两小时的，只能允许打两小时。
3、当多对球员的开始打球时间相同时，先输出到达时间早的球员的信息。
4、当等待球员中没有 VIP 时，VIP 球台视作普通球台处理，当可用球台中没有 VIP 球台时，VIP 球员视作普通球员处理。

输入格式

第一行包含整数 N，表示共有 N 对球员。

接下来 N 行，每行包含两个时间以及一个 VIP 标识，HH:MM:SS----到达时间，p----打球时间（单位：分钟），tag----如果是 1，说明这是一对 VIP，如果是 0，说明不是 VIP。

保证到达时间在 08:00:00 至 21:00:00 之间，这是俱乐部的营业时间。

保证每对球员的到达时间都不相同。

再一行包含两个整数 K 和 M，表示球台数量以及 VIP 球台数量。

最后一行包含 M 个整数，表示 VIP 球台的编号。

输出格式

首先输出每对球员的到达时间，开始打球时间，等待时间。

每对球员的信息占一行，按开始打球时间从早到晚的顺序依次输出。

等待时间必须四舍五入为整数分钟。

如果一对球员在 21:00:00 之前(不包括 21:00:00）不能得到一张球台，那么无需输出他们的信息。

再输出一行，K 个整数，表示每个球台服务的球员对数。

数据范围

1≤N≤10000,
1≤K≤100,
0≤M≤K

输入样例：

9
20:52:00 10 0
08:00:00 20 0
08:02:00 30 0
20:51:00 10 0
08:10:00 5 0
08:12:00 10 1
20:50:00 10 0
08:01:30 15 1
20:53:00 10 1
3 1
2
输出样例：

08:00:00 08:00:00 0
08:01:30 08:01:30 0
08:02:00 08:02:00 0
08:12:00 08:16:30 5
08:10:00 08:20:00 10
20:50:00 20:50:00 0
20:51:00 20:51:00 0
20:52:00 20:52:00 0
3 3 2
* */
//思路，排队的话用prioirity_queue找到最先空出来的球桌，和最近赶到的球员匹配，
//如果空出来的是vip，且在队列里有vip在空出来之前到了，给vip，如果没有，就正常先来后到，
//把所有服务过的球员搞进vector，遍历输出答案
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>//priority_queue
#include<algorithm>
using namespace std;
string get_time(int secs);
const int INF=1000000,M=110,N=10010;
bool isVip[M];//id映射是不是vip的hash表
class Person
{
  public:
    int arrive_time;
    int service_time;
    int wait_time;
    int begin_time;
    Person(int h,int m,int s,int play_time)
    {
      arrive_time=h*3600+m*60+s;
      this->service_time=play_time*60;
      begin_time=-1;
      wait_time=0;
    }
    bool operator>(const Person t)const//用于priority_queue,小顶堆先端队列比较要重写大于号
    {
      return arrive_time>t.arrive_time;
    }
    bool operator<(const Person t)const//用于sort的小于号
    {
      if(begin_time!=t.begin_time)return begin_time<t.begin_time;
      else return arrive_time<t.arrive_time;
    }
};
class Table
{
  public:
    int free_time;
    int id;

    Table(int id,int free_time)
    {
      this->id=id;
      this->free_time=free_time;

    }
    bool operator>(const Table t)const
    {
      //这里的free_time如果在人到之前就已经空了回在循环里改变为人到了的时间
      if(free_time!=t.free_time) return free_time>t.free_time;
      else return id>t.id;//优先靠左
    }

};

vector<Person> serviced_persons;

void assign( priority_queue<Person,vector<Person>,greater<Person>> &persons,priority_queue<Table,vector<Table>,greater<Table>> &tables,vector<int>&service_cnt)
{
  Person p=persons.top();persons.pop();
  Table t=tables.top();tables.pop();
  //将人的begin_time改成开始服务的时间，
  p.begin_time=t.free_time;
  p.wait_time=round((p.begin_time-p.arrive_time)/60.0);//除以60.0保证浮点数计算
  //将桌子空闲时间改成free_time+service_time;
  t.free_time+=p.service_time;
  service_cnt[t.id]++;
  tables.push(t);
  serviced_persons.push_back(p);
}
string get_time(int secs)
{
  char ans[10];
  //格式化输入用sprintf()
  sprintf(ans,"%02d:%02d:%02d",secs/3600,secs%3600/60,secs%60);
  return ans;
}
int main()
{
  /*
  输入格式

第一行包含整数 N，表示共有 N 对球员。

接下来 N 行，每行包含两个时间以及一个 VIP 标识，HH:MM:SS----到达时间，p----打球时间（单位：分钟），tag----如果是 1，说明这是一对 VIP，如果是 0，说明不是 VIP。

保证到达时间在 08:00:00 至 21:00:00 之间，这是俱乐部的营业时间。

保证每对球员的到达时间都不相同。

再一行包含两个整数 K 和 M，表示球台数量以及 VIP 球台数量。

最后一行包含 M 个整数，表示 VIP 球台的编号。
* */
  int n;
  cin>>n;
  priority_queue<Person,vector<Person>,greater<Person>> normal_persons;//小顶堆要显示指定
  normal_persons.push(Person(99,99,99,-1));
  priority_queue<Person,vector<Person>,greater<Person>> vip_persons;
vip_persons.push(Person(99,99,99,-1));
  for(int i=0;i<n;i++)
  {
  int h,m,s,p,tag;
  scanf("%02d:%02d:%02d %d %d",&h,&m,&s,&p,&tag);
  if(p>2*60)
    p=2*60;
  if(tag) vip_persons.push(Person(h,m,s,p));
  else normal_persons.push(Person(h,m,s,p));
  }

  priority_queue<Table,vector<Table>,greater<Table>> normal_tables;
  normal_tables.push(Table(-1,1000000));
  priority_queue<Table,vector<Table>,greater<Table>> vip_tables;
  vip_tables.push(Table(-1,1000000));
  int k,m;
  cin>>k>>m;
  vector<int> service_cnt(k+1,0);
  for(int i=0;i<m;i++)
  {
    int id;
    cin>>id;
    isVip[id]=true;
    vip_tables.push(Table(id,8*3600));
  }

  for(int i=1;i<=k;i++) if(!isVip[i])normal_tables.push(Table(i,8*3600));
//这里不使用哨兵且不判断的话就会尝试取出空队列的top
  //如果不用哨兵的话就要在每次队列操作的时候进行判断
  while(normal_persons.size()!=1||vip_persons.size()!=1)
  {
    /*
两种大情况，一来就有空桌，没有空桌，一来有空桌就分为空的是vip，和普通桌子，可以把空桌子的开始时间全都修改为人的到达时间，降低讨论
* */
    Person np=normal_persons.top(),vp=vip_persons.top();
    int arrive_time=min(np.arrive_time,vp.arrive_time);//先到的时间



    //可以通过把空桌子的空的时间改成先到的人的到达时间，降低讨论
    while(normal_tables.top().free_time<arrive_time)
    {
      Table t=normal_tables.top();
      t.free_time=arrive_time;
      normal_tables.pop();
      normal_tables.push(t);
    }
    while(vip_tables.top().free_time<arrive_time)
    {
      Table t=vip_tables.top();
      t.free_time=arrive_time;
      vip_tables.pop();
      vip_tables.push(t);
    }
     //判断，如果人的得到球台已经过了21点了就直接退出
    int end_time=min(vip_tables.top().free_time,normal_tables.top().free_time);
    if(end_time>=21*3600)
    break;
    //先空出来的是vip桌，vip在vip桌空出来之前有在队伍里，VIP去
    //先空出来的是普通桌，先来后到
    //先空出来的是vip桌，但是vip不在队伍里，先来后到
    int final_time=min(vip_tables.top().free_time,normal_tables.top().free_time);
    if(final_time==vip_tables.top().free_time&&vip_persons.top().arrive_time<=final_time)
    {
      assign(vip_persons,vip_tables,service_cnt);
      //接下来要么就是普通桌先空，要么就是vip桌空，但是在vip桌空之前没有vip到场
    }else if(np.arrive_time<vp.arrive_time)//两种情况,普通人先到，找到最先开的,vip先到，也找最先开的，如果都有空，找编号最小的
    {
        Table vt=vip_tables.top();Table nt=normal_tables.top();
      //这里的free_time如果在人到之前就已经空了回在循环里改变为人到了的时间，所以在有多个桌子为空的情况下就可以以编号为依据来比较
      if(vt>nt)
      {
        assign(normal_persons,normal_tables,service_cnt);
      }
      else assign(normal_persons,vip_tables,service_cnt);
    }else
    {//vip先到
    Table vt=vip_tables.top();Table nt=normal_tables.top();
    if(nt>vt)
      assign(vip_persons,vip_tables,service_cnt);
      else assign(vip_persons,normal_tables,service_cnt);
    }
  }

  sort(serviced_persons.begin(),serviced_persons.end());
  for(Person p:serviced_persons)
  {
    cout<<string(get_time(p.arrive_time))<<" "<<string(get_time(p.begin_time))<<" "<<p.wait_time<<endl;
  }

  cout << service_cnt[1];
  for (int i = 2; i <= k; i ++ ) cout << ' ' << service_cnt[i];
  cout << endl;
  return 0;
}