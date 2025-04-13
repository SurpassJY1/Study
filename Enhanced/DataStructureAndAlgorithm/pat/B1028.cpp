#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
using namespace std;
/*
这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过 200 岁的老人，
而今天是 2014 年 9 月 6 日，所以超过 200 岁的生日和未出生的生日都是不合理的，应该被过滤掉。
* */
bool isValid(int year,int mouth,int date)
{
  if(year>2014)
    return false;
  if (year==2014&&mouth>9)
    return false;
  if (year==2014&&mouth==9&&date>6)
    return false;
  if(year<1814)
    return false;
  if (year==1814&&mouth<9)
    return false;
  if (year==1814&&mouth==9&&date<6)
    return false;
  return true;
}
class Person
{
public:
  string name;
  string birth;
  int year;
  int mouth;
  int date;
  int age;
  Person(string inName,string inBirth):name(inName),birth(inBirth)
  {
    year=stoi(birth.substr(0,4));
    mouth=stoi(birth.substr(5,2));
    date=stoi(birth.substr(8,2));
  }
};
bool myCompare(Person p1,Person p2)
{
  if(p1.year!=p2.year)
    return p1.year>p2.year;
  if(p1.mouth!=p2.mouth)
    return p1.mouth>p2.mouth;
  if(p1.date!=p2.date)
    return p1.date>p2.date;
  return false;
}
int main()
{
  int n;
  cin>>n;
  vector<Person> persons;
  for(int i=0;i<n;i++)
  {
    string name,birth;
    cin>>name>>birth;
    Person p(name,birth);
    if(isValid(p.year,p.mouth,p.date))
    {
      persons.push_back(p);
    }
  }
  if(persons.size()>=1)
  {sort(persons.begin(),persons.end(),myCompare);
    cout<<persons.size()<<" "<<persons.back().name<<" "<<persons[0].name;
  }//村里没有符合条件的
  else {
    cout<<0;
  }
  return 0;
}