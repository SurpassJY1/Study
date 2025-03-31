//
// Created by GlokieYu on 25-3-28.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Student
{
    public:
    int m_De;
    int m_Cai;
    int m_Id;
    int total;
    Student(int id,int de,int cai):m_Id(id),m_De(de),m_Cai(cai){
        total=m_De+m_Cai;
    }
};

//排序规则
bool myCompare(Student stu1,Student stu2)
{
    if(stu1.total!=stu2.total)
    {
        return stu1.total>stu2.total;
    }else if(stu1.m_De!=stu2.m_De)
    {
        return stu1.m_De>stu2.m_De;
    }else
    {
        return stu1.m_Id<stu2.m_Id;
    }
}

void store(vector<Student> &first,vector<Student> &second,vector<Student>&third,vector<Student>&fourth,Student &stu,int H,int L)
{
    if(stu.m_De>=H&&stu.m_Cai>=H)
        first.push_back(stu);
    else if(stu.m_De>=L&&stu.m_Cai>=L&&stu.m_De>=H&&stu.m_Cai<H)
        second.push_back(stu);
    else if(stu.m_De>=L&&stu.m_Cai>=L&&stu.m_De<H&&stu.m_Cai<H&&stu.m_Cai<stu.m_De)
        third.push_back(stu);
    else if(stu.m_De>=L&&stu.m_Cai>=L)
        fourth.push_back(stu);
}
int main()
{
    //创建三个vector，分别存储德才兼备，德胜才，才德兼亡，都不行的
    vector<Student> first;
    vector<Student> second;
    vector<Student> third;
    vector<Student> fourth;
    int N,L,H;
    cin>>N>>L>>H;
    int id,de,cai;
    for(int i=0;i<N;i++)
    {
        cin>>id>>de>>cai;
        Student stu(id,de,cai);
        store(first,second,third,fourth,stu,H,L);
    }
    //计算出过线的总考生数
    int M=0;
    M+=first.size();
    M+=second.size();
    M+=third.size();
    M+=fourth.size();
    cout<<M<<endl;
    //分别对一二三四组排序并输出
    sort(first.begin(),first.end(),myCompare);
    for(int i=0;i<first.size();i++)
    {
        cout<<first[i].m_Id<<" "<<first[i].m_De<<" "<<first[i].m_Cai<<endl;
    }
    sort(second.begin(),second.end(),myCompare);
    for(int i=0;i<second.size();i++)
    {
        cout<<second[i].m_Id<<" "<<second[i].m_De<<" "<<second[i].m_Cai<<endl;
    }
    sort(third.begin(),third.end(),myCompare);
    for(int i=0;i<third.size();i++)
    {
        cout<<third[i].m_Id<<" "<<third[i].m_De<<" "<<third[i].m_Cai<<endl;
    }
    sort(fourth.begin(),fourth.end(),myCompare);
    for(int i=0;i<fourth.size();i++)
    {
        cout<<fourth[i].m_Id<<" "<<fourth[i].m_De<<" "<<fourth[i].m_Cai<<endl;
    }
    return 0;
}