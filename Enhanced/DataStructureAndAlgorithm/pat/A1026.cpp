//
// Created by GlokieYu on 25-4-10.
//
/*
һ��ƹ������ֲ����� K ��ƹ����̨�����Ϊ 1?K��

��������һ����Ա�������ǵ���ʱ����ж����̨���ã���ô���Ǿͻᱻ���ŵ���Ž�С���Ǹ���̨�ϴ���

���������̨����ռ���ˣ����Ǿ�ֻ���Ŷӵȴ��ˡ�

����ÿ����Ա���ֻ�������Сʱ��

����Ҫ����ÿ���ŶӵȺ���˵ĵȴ�ʱ���Լ�ÿ����̨�����ж��ٶ���Ա���������

���⣬����������ø��ӵ��ǣ����ֲ�Ϊ VIP ��Ա������һЩ��̨��

��һ�� VIP ��̨�ճ�ʱ���ȴ������еĵ�һ�� VIP ��Ա������ʹ�������̨��

�����ʱ�ȴ�������û�� VIP�������ڵȴ�����ĵ�һ����Ա����ʹ�������̨��

��һ���棬���ֵ�һ�� VIP ��Ա����ʱ�����û�� VIP ��̨���ã���ô���ǽ���������ͨ��Ա����

���䣺

1�����ȴ��������� VIP ��Ա�����п��� VIP ��̨ʱ���������ȷ��� VIP ��Ա�����ұ���������� VIP ��̨�����ȷ����Ž�С�ģ���ֱ�� VIP �û��� VIP ��̨������Ϊֹ��
2����������ʱ�䳬����Сʱ�ģ�ֻ���������Сʱ��
3���������Ա�Ŀ�ʼ����ʱ����ͬʱ�����������ʱ�������Ա����Ϣ��
4�����ȴ���Ա��û�� VIP ʱ��VIP ��̨������ͨ��̨������������̨��û�� VIP ��̨ʱ��VIP ��Ա������ͨ��Ա����

�����ʽ

��һ�а������� N����ʾ���� N ����Ա��

������ N �У�ÿ�а�������ʱ���Լ�һ�� VIP ��ʶ��HH:MM:SS----����ʱ�䣬p----����ʱ�䣨��λ�����ӣ���tag----����� 1��˵������һ�� VIP������� 0��˵������ VIP��

��֤����ʱ���� 08:00:00 �� 21:00:00 ֮�䣬���Ǿ��ֲ���Ӫҵʱ�䡣

��֤ÿ����Ա�ĵ���ʱ�䶼����ͬ��

��һ�а����������� K �� M����ʾ��̨�����Լ� VIP ��̨������

���һ�а��� M ����������ʾ VIP ��̨�ı�š�

�����ʽ

�������ÿ����Ա�ĵ���ʱ�䣬��ʼ����ʱ�䣬�ȴ�ʱ�䡣

ÿ����Ա����Ϣռһ�У�����ʼ����ʱ����絽���˳�����������

�ȴ�ʱ�������������Ϊ�������ӡ�

���һ����Ա�� 21:00:00 ֮ǰ(������ 21:00:00�����ܵõ�һ����̨����ô����������ǵ���Ϣ��

�����һ�У�K ����������ʾÿ����̨�������Ա������

���ݷ�Χ

1��N��10000,
1��K��100,
0��M��K

����������

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
���������

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
//˼·���ŶӵĻ���prioirity_queue�ҵ����ȿճ�����������������ϵ�����Աƥ�䣬
//����ճ�������vip�����ڶ�������vip�ڿճ���֮ǰ���ˣ���vip�����û�У������������󵽣�
//�����з��������Ա���vector�����������
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>//priority_queue
#include<algorithm>
using namespace std;
string get_time(int secs);
const int INF=1000000,M=110,N=10010;
bool isVip[M];//idӳ���ǲ���vip��hash��
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
    bool operator>(const Person t)const//����priority_queue,С�����ȶ˶��бȽ�Ҫ��д���ں�
    {
      return arrive_time>t.arrive_time;
    }
    bool operator<(const Person t)const//����sort��С�ں�
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
      //�����free_time������˵�֮ǰ���Ѿ����˻���ѭ����ı�Ϊ�˵��˵�ʱ��
      if(free_time!=t.free_time) return free_time>t.free_time;
      else return id>t.id;//���ȿ���
    }

};

vector<Person> serviced_persons;

void assign( priority_queue<Person,vector<Person>,greater<Person>> &persons,priority_queue<Table,vector<Table>,greater<Table>> &tables,vector<int>&service_cnt)
{
  Person p=persons.top();persons.pop();
  Table t=tables.top();tables.pop();
  //���˵�begin_time�ĳɿ�ʼ�����ʱ�䣬
  p.begin_time=t.free_time;
  p.wait_time=round((p.begin_time-p.arrive_time)/60.0);//����60.0��֤����������
  //�����ӿ���ʱ��ĳ�free_time+service_time;
  t.free_time+=p.service_time;
  service_cnt[t.id]++;
  tables.push(t);
  serviced_persons.push_back(p);
}
string get_time(int secs)
{
  char ans[10];
  //��ʽ��������sprintf()
  sprintf(ans,"%02d:%02d:%02d",secs/3600,secs%3600/60,secs%60);
  return ans;
}
int main()
{
  /*
  �����ʽ

��һ�а������� N����ʾ���� N ����Ա��

������ N �У�ÿ�а�������ʱ���Լ�һ�� VIP ��ʶ��HH:MM:SS----����ʱ�䣬p----����ʱ�䣨��λ�����ӣ���tag----����� 1��˵������һ�� VIP������� 0��˵������ VIP��

��֤����ʱ���� 08:00:00 �� 21:00:00 ֮�䣬���Ǿ��ֲ���Ӫҵʱ�䡣

��֤ÿ����Ա�ĵ���ʱ�䶼����ͬ��

��һ�а����������� K �� M����ʾ��̨�����Լ� VIP ��̨������

���һ�а��� M ����������ʾ VIP ��̨�ı�š�
* */
  int n;
  cin>>n;
  priority_queue<Person,vector<Person>,greater<Person>> normal_persons;//С����Ҫ��ʾָ��
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
//���ﲻʹ���ڱ��Ҳ��жϵĻ��ͻ᳢��ȡ���ն��е�top
  //��������ڱ��Ļ���Ҫ��ÿ�ζ��в�����ʱ������ж�
  while(normal_persons.size()!=1||vip_persons.size()!=1)
  {
    /*
���ִ������һ�����п�����û�п�����һ���п����ͷ�Ϊ�յ���vip������ͨ���ӣ����԰ѿ����ӵĿ�ʼʱ��ȫ���޸�Ϊ�˵ĵ���ʱ�䣬��������
* */
    Person np=normal_persons.top(),vp=vip_persons.top();
    int arrive_time=min(np.arrive_time,vp.arrive_time);//�ȵ���ʱ��



    //����ͨ���ѿ����ӵĿյ�ʱ��ĳ��ȵ����˵ĵ���ʱ�䣬��������
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
     //�жϣ�����˵ĵõ���̨�Ѿ�����21���˾�ֱ���˳�
    int end_time=min(vip_tables.top().free_time,normal_tables.top().free_time);
    if(end_time>=21*3600)
    break;
    //�ȿճ�������vip����vip��vip���ճ���֮ǰ���ڶ����VIPȥ
    //�ȿճ���������ͨ����������
    //�ȿճ�������vip��������vip���ڶ����������
    int final_time=min(vip_tables.top().free_time,normal_tables.top().free_time);
    if(final_time==vip_tables.top().free_time&&vip_persons.top().arrive_time<=final_time)
    {
      assign(vip_persons,vip_tables,service_cnt);
      //������Ҫô������ͨ���ȿգ�Ҫô����vip���գ�������vip����֮ǰû��vip����
    }else if(np.arrive_time<vp.arrive_time)//�������,��ͨ���ȵ����ҵ����ȿ���,vip�ȵ���Ҳ�����ȿ��ģ�������пգ��ұ����С��
    {
        Table vt=vip_tables.top();Table nt=normal_tables.top();
      //�����free_time������˵�֮ǰ���Ѿ����˻���ѭ����ı�Ϊ�˵��˵�ʱ�䣬�������ж������Ϊ�յ�����¾Ϳ����Ա��Ϊ�������Ƚ�
      if(vt>nt)
      {
        assign(normal_persons,normal_tables,service_cnt);
      }
      else assign(normal_persons,vip_tables,service_cnt);
    }else
    {//vip�ȵ�
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