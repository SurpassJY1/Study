//
// Created by GlokieYu on 25-4-9.
//
/*
��map��������ͨ���б�
���б���������Ƿ���Ҫ��ľ����
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<map>
using namespace std;

class Person
{
  public:
    int minutes;
    int mouth,day,hour,minute;
    char format_time[25];
    string state;
    Person(int mouth,int day,int hour,int minute,string state)
    {

        this->mouth=mouth;
        this->day=day;
        this->hour=hour;
        this->minute=minute;
        this->state=state;
        //�����һ��0ʱ0�ֵ�ʱ��
        minutes=(day-1)*1440+hour*60+minute;//��Ϊ�Ǵ�һ�ſ�ʼ������day-1
        sprintf(format_time,"%02d:%02d:%02d",day,hour,minute);//��ʽ�����������sprintf
    }
};
bool myCompare(Person p1,Person p2)
{
    return p1.minutes<p2.minutes;/*
    format_time��char���飬ֱ��ʹ��p1.format_time < p2.format_time�Ƚϵ���������ڴ��ַ
    �������ַ������ݡ����ֱȽϷ�ʽû�����壬�ᵼ�´������������
    */
}
//����ǰ׺��Ԥ����ÿһ����Ҫ����Ǯ
int cost[24];
double sum[24*60*31+10];
map<string,vector<Person>> persons;
int main()
{
    for(int i=0;i<24;i++)
    {
        int hourCost;
        cin>>hourCost;
        cost[i]=hourCost;
    }

    //Ԥ������ǰ׺��
    for(int i=1;i<24*60*31+10;i++)
    {
        sum[i]=sum[i-1]+(double)cost[(i-1)%1440/60]/100;//i-1��Ϊ0�㵽1�������0���Ǯ�����iû��1,�ͱ����1���Ǯ��
                                                        //�����������ת����ɾ��ȶ�ʧ
    }
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        //¼�����ݣ�����persons����
       char name[25],state[10];
       int mouth,day,hour,minute;
       scanf("%s %d:%d:%d:%d %s",name,&mouth,&day,&hour,&minute,state);
       persons[name].push_back(Person(mouth,day,hour,minute,state));
    }
    //��map�е��������������
    for(auto person:persons)
    {
        sort(person.second.begin(),person.second.end(),myCompare);
        vector<Person> list=person.second;
        double total=0;
        bool flag=false;
        for(int i=0;i+1<person.second.size();i++)
        {
            if(list[i].state=="on-line"&&list[i+1].state=="off-line")
            {
                if(!total)
                {
                    printf("%s %02d\n",person.first.c_str(),list[i].mouth);
                    double money=sum[list[i+1].minutes]-sum[list[i].minutes];
                    cout<<list[i].format_time<<" "<<list[i+1].format_time<<" "<<list[i+1].minutes-list[i].minutes<<" $"<<fixed<<setprecision(2)<<money<<endl;
                    total+=money;
                    flag=true;
                }else
                {
                    double money=sum[list[i+1].minutes]-sum[list[i].minutes];
                    cout<<list[i].format_time<<" "<<list[i+1].format_time<<" "<<list[i+1].minutes-list[i].minutes<<" $"<<fixed<<setprecision(2)<<money<<endl;
                    total+=money;
                }
            }

        }
        if(flag) cout<<"Total amount: $"<<fixed<<setprecision(2)<<total<<endl;
    }
    return 0;
}