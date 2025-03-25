//
// Created by GlokieYu on 25-3-25.
//

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    string str1;
    string str2;
    string str3;
    string str4;
    cin>>str1>>str2>>str3>>str4;
    //check the size();
    int size1=str1.size();
    int size2=str2.size();
    int size3=str3.size();
    int size4=str4.size();
    int count1=size1>size2?size2:size1;
    int day=-1,hour=-1;
    for(int i=0;i<count1;i++){
        if(str1[i]==str2[i]&&std::isupper(str1[i])) {
            if(day==-1)
                day=i;
            break;
        }
    }
    for (int i=day+1;i<=count1;i++) {
        if (str1[i]==str2[i]&&hour==-1) {
            hour=i;
        }
    }
    int mm=-1;
    int count2=size3>size4?size4:size3;
    for(int i=0;i<count2;i++){
        if(str3[i]==str4[i]&&isalpha(str3[i])) {
            if(mm==-1)
                mm=i;
        }
    }
    vector<string> dayTime={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    vector<int> dayHour;
    for (int i=0;i<=23;i++) {
        dayHour.push_back(i);
    }
    cout<<dayTime[(int)str1[day]-'A'];
    if (isdigit(str1[hour])) {
        cout<<" "<<dayHour[hour];
    }else if (isupper(str1[hour]))
        cout<<" "<<dayHour[str1[hour]-(int)'A'+10];
    else cout<<" "<<dayHour[str1[hour]-(int)'a'];
    cout<<":";
    if (mm<10) {
        cout<<"0"<<mm;
    }else
        cout<<mm;
    return 0;
}