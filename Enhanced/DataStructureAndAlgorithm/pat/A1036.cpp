//
// Created by GlokieYu on 25-4-9.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Girl
{
public:
    int score;
    string name;
    string id;
    string gender;
    Girl(string in_Name,string in_id,int in_score):name(in_Name),id(in_id),score(in_score)
    {
        gender='F';
    }
};
class Boy
{
public:
    int score;
    string name;
    string id;
    string gender;
    Boy(string in_Name,string in_id,int in_score):name(in_Name),id(in_id),score(in_score)
    {
        gender='M';
    }
};
bool myCompare(Girl g1,Girl g2)
{
    return g1.score>g2.score;
}
bool boyCompare(Boy b1,Boy b2)
{
    return b1.score>b2.score;
}
int main()
{
    int n;
    cin>>n;
    vector<Girl>girls;
    vector<Boy>boys;
    for(int i=0;i<n;i++)
    {
        string name,gender,id;
        int score;
        cin>>name>>gender>>id>>score;
        if(gender=="F")
        {
            girls.push_back(Girl(name,id,score));
        }else boys.push_back(Boy(name,id,score));
    }
    sort(boys.begin(),boys.end(),boyCompare);
    sort(girls.begin(),girls.end(),myCompare);
    bool has=true;
    if(girls.size()==0)
    {cout<<"absent"<<endl;
        has=false;
    }
    else cout<<girls[0].name<<" "<<girls[0].id<<endl;
    if(boys.size()==0)
    {
        cout<<"absent"<<endl;

        has=false;
    }else cout<<boys.back().name<<" "<<boys.back().id<<endl;
    if(!has) cout<<"NA"<<endl;
    else cout<<abs(girls[0].score-boys.back().score)<<endl
}