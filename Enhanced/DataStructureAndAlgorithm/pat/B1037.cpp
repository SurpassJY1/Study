//
// Created by GlokieYu on 25-4-9.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
/*
思路：
全都转换成西克
转化成应找的西可
再把西可转换成对应的钱
注意：全都转换成西可可能会超范围

*/
vector<int> change(string input) {
    int galleon;
    int sickle;
    int knut;
    cin>>input;
    int dotPos=0;
    dotPos=input.find('.');
    galleon=stoi(input.substr(0,dotPos));
    dotPos=input.find('.',input.find('.')+1);
    sickle=stoi(input.substr(input.find('.')+1,dotPos));
    knut=stoi(input.substr(dotPos+1));
    vector<int> res={galleon,sickle,knut};
    return res;
}
bool isSame(vector<int>p,vector<int> a) {
    if (p[0]!=a[0])
    return false;
    if (p[1]!=a[1])
        return false;
    if (p[2]!=a[2])
        return false;
    return true;
}
int main()
{

    string input;
    vector<int> p=change(input);
    string astr;
    vector<int> a=change(astr);
    string res;
    //设置a永远大
    if (p[0]>a[0]) {
        vector<int> temp=p;
        p=a;
        a=temp;
        res+='-';
    }else if(p[0]==a[0]&&p[1]>a[1]) {
        vector<int> temp=p;
        p=a;
        a=temp;
        res+='-';
    }else if (p[0]==a[0]&&p[1]==a[1]&&p[2]>a[2]) {
        vector<int> temp=p;
        p=a;
        a=temp;
        res+='-';
    }
    long long gap=0;
    //将a逐渐加到p的值
    while (!isSame(p,a)) {
        p[2]++;
        gap++;

        // 处理 Knut 进位
        if (p[2] >= 29) {
            p[2] = 0;
            p[1]++;

        }

        // 处理 Sickle 进位
        if (p[1] >= 17) {
            p[1] = 0;
            p[0]++;

        }
    }
    //将gap转化为对应格式
    int galleon;
    int sickle;
    int knut;
   galleon=gap/493;
    sickle=gap%493/29;
    knut=gap%493%29;
    res+=to_string(galleon);
    res+='.';
    res+=to_string(sickle);
    res+='.';
    res+=to_string(knut);
    cout<<res;
    return 0;
}