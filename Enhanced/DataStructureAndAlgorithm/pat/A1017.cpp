//
// Created by GlokieYu on 25-4-10.
//
/*
����һ�������� K �����񴰿ڡ�

����ǰ����һ�����ߣ����Ⱥ�����Ϊ�����֡�

���пͻ��������ڻ��ߺ����ŶӵȺ�ֱ���ֵ���/���������п��õĴ���Ϊֹ��

�ٶ�һ�����ڲ��ܱ������ͻ�ռ�ó��� 1 Сʱ�������ĳλ�˿͵�ҵ���Ѿ�������һСʱ����������ֹ����ҵ��

���ڸ���ÿ���ͻ��ĵ���ʱ�� T ��ҵ�����ʱ�� P����������пͻ���ƽ���ȴ�ʱ�䡣

�����ʽ

��һ�а����������� N �� K���ֱ��ʾ�ͻ������Լ�����������

������ N �У�ÿ�а�������ʱ�䣬�ֱ���һ���ͻ��ĵ���ʱ�䣬�� HH:MM:SS ��ʾ���Լ�һ���ͻ���ҵ�����ʱ�� P����λ�����ӣ���

HH �� [00,23] ��Χ�ڣ�MM �� SS ���� [00,59] ��Χ�ڡ�

���пͻ��ĵ���ʱ�������ͬ��

��ע�⣬���е�Ӫҵʱ��Ϊ 08:00 �� 17:00��

�κ�����ǰ���ﶼ�����ŶӵȺ��� 08:00�����κ�������̫���� 17:00:01 ��֮�󵽴������������Ҳ�������ƽ��ֵ��

ע��ֻҪ�ͻ���17:00֮ǰ���϶ӣ���ʹ����ҵ��ʱ����17:00��Ҳ�ᱻ����

�����ʽ

���ƽ���ȴ�ʱ�䣨��λ�����ӣ����������һλС����

ע�⣬�ӵ�����������ʼ����ҵ����һ�ڼ���Ϊ�ȴ��ڼ䡣

���ݷ�Χ

1��N��104,
1��K��100

����������

7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10
���������

8.2
* */
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
#include<queue>//���ҵ������һ���մ��ڵ�ʱ����С����
using namespace std;
class Person
{
  public:
    int arrive_time;
    int service_time;
    Person(int h,int minute,int second,int service_time)
    {
      arrive_time=h*3600+minute*60+second;//������0�����������룬�ڼ����ֵ��ʱ�������
      this->service_time=min(service_time*60,3600);//����60���ӵİ�60������
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
    //�ڸ�ʽ��������ȡ��ֵ��ʱ����scanf������
    int h,min,s,service_time;
    scanf("%02d:%02d:%02d %d",&h,&min,&s,&service_time);
    persons.push_back(Person(h,min,s,service_time));
  }
  //��person�����������ҵ�˭Ӧ������ȥ���ܷ���
  sort(persons.begin(),persons.end(),myCompare);

  //���崰�ڣ���Ϊÿ�ζ�Ҫ�ҵ����ȿ��еĴ��ڣ�������priority_queue
  priority_queue<int,vector<int>,greater<int>> windows;
  for(int i=0;i<m;i++)
  {
    windows.push(8*3600);//����8�㿪��
  }
  //����ÿ���ˣ��ҵ����ȿճ����Ĵ��ڣ���ȥ���ܷ��񣬴��ڵ�ʱ�����Ϊ��ʼ��ʱ��ͷ���ֹͣ��ʱ��
  int cnt=0,sum=0;
  for(int i=0;i<n;i++)
  {
    Person p=persons[i];
    //����˵����ʱ�������֮���ֱ��������
    if(p.arrive_time>=17*3600+1)
      break;
    int w=windows.top();
    //���˵����ʱ��ʹ��ڿ�ʼ��ʱ�����Ƚϣ����Ҫ�Ⱦͼ���sum
    int start_time=max(w,p.arrive_time);
    sum+=start_time-p.arrive_time;
    cnt++;
    windows.pop();
    //���´���
    windows.push(start_time+p.service_time);
  }
  double res=(double)sum/cnt/60;
  printf("%.1f",res);
}
