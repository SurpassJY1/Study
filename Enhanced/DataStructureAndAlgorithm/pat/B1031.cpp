//
// Created by GlokieYu on 25-4-3.
//
#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool isValid(string id)
{
    vector<char> m={'1','0','X','9','8','7','6','5','4','3','2'};
    vector<int> power={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    int sum=0;
    for(int i=0;i<id.size()-1;i++)
    {
        if(id[i]<'0'||id[i]>'9')
            return false;
        sum+=power[i]*(id[i]-'0');
    }
    int z=sum%11;
    return id[id.size()-1]==m[z];
}
int main()
{
    vector<string> persons;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string id;
        cin>>id;
        persons.push_back(id);
    }
    bool flag=true;
    for(int i=0;i<n;i++)
    {
        if(!isValid(persons[i]))
        {
            cout<<persons[i]<<endl;
            flag=false;
        }
    }
    if(flag)
        cout<<"All passed"<<endl;
    return 0;
}