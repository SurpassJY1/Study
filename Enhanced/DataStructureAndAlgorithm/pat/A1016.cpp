//
// Created by GlokieYu on 25-4-9.
//
/*
用map存人名和通话列表
对列表排序，如果是符合要求的就输出
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
        //算出离一号0时0分的时间
        minutes=(day-1)*1440+hour*60+minute;//因为是从一号开始的所以day-1
        sprintf(format_time,"%02d:%02d:%02d",day,hour,minute);//格式化输入可以用sprintf
    }
};
bool myCompare(Person p1,Person p2)
{
    return p1.minutes<p2.minutes;/*
    format_time是char数组，直接使用p1.format_time < p2.format_time比较的是数组的内存地址
    ，而非字符串内容。这种比较方式没有意义，会导致错误的排序结果。
    */
}
//利用前缀和预处理每一分钟要花的钱
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

    //预处理算前缀和
    for(int i=1;i<24*60*31+10;i++)
    {
        sum[i]=sum[i-1]+(double)cost[(i-1)%1440/60]/100;//i-1因为0点到1点算得是0点的钱，如果i没减1,就变成算1点的钱了
                                                        //这里可能整型转换造成精度丢失
    }
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        //录入数据，存在persons当中
       char name[25],state[10];
       int mouth,day,hour,minute;
       scanf("%s %d:%d:%d:%d %s",name,&mouth,&day,&hour,&minute,state);
       persons[name].push_back(Person(mouth,day,hour,minute,state));
    }
    //对map中的所有人排序输出
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