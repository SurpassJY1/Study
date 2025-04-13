//
// Created by GlokieYu on 25-4-4.
//
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
//注意分子分亩都为负数的时候
long long gcd(long long num1,long long num2)
{
  if(num2==0)
    return num1;
  return gcd(num2,num1%num2);
}
vector<long long> getNums(string num) {

    vector<long long>nums;
    long long pos=num.find('/');
    string s=num.substr(0,pos);
    nums.push_back(stoll(s));
    nums.push_back(stoll(num.substr(pos+1,num.size()-pos-1)));
    return nums;
}
string simplify(string num) {
    string res;
    long long pos=num.find('/');
    string num1;
    if (num[0]=='-'&&num[pos+1]!='-') {
        num1=num.substr(1,pos);
        res+="(-";
    }else
        num1=num.substr(0,pos);
    string num2=num.substr(pos+1,num.size()-pos-1);
    long long dNum1=stoll(num1);
    long long dNum2=stoll(num2);
    /*
     * 整除
     * 分子大于分母
     * 分子小于分母
     */
    if (dNum1%dNum2==0) {
        res+=to_string(dNum1/dNum2);
    }else if (dNum1>dNum2&&dNum1%dNum2!=0) {
        res+=to_string(dNum1/dNum2);
        res+=' ';
        string mother;
        mother+=to_string(dNum1%dNum2);
        mother+='/';
        mother+=num2;
        res+=simplify(mother);
    }else {
        long long gNum=gcd(dNum1,dNum2);
        res+=to_string(dNum1/gNum);
        res+='/';
        res+=to_string(dNum2/gNum);
    }
    //最后判断
    if (res[0]=='(')
        res+=')';
    return res;
}

int main()
{
    //注意点：题目说了整型范围，用longlong
    string num1;
    string num2;
    cin>>num1>>num2;
    string simNum1=simplify(num1);
    string simNum2=simplify(num2);
    cout<<simplify(num1)<<" + ";
    cout<<simplify(num2)<<" = ";
    string addAns;
    vector<long long> digiNum1=getNums(num1);
    vector<long long> digiNum2=getNums(num2);
    addAns+=to_string(digiNum1[0]*digiNum2[1]+digiNum2[0]*digiNum1[1]);
    addAns+='/';
    addAns+=to_string(digiNum1[1]*digiNum2[1]);
    cout<<simplify(addAns)<<endl;
    cout<<simNum1<<" - ";
    cout<<simNum2<<" = ";
    string deleteAns;
    deleteAns+=to_string(digiNum1[0]*digiNum2[1]-digiNum1[1]*digiNum2[0]);
    deleteAns+='/';
    deleteAns+=to_string(digiNum1[1]*digiNum2[1]);
    cout<<simplify(deleteAns)<<endl;
    string multiplyAns;
    cout<<simNum1<<" * ";
    cout<<simNum2<<" = ";
    multiplyAns+=to_string(digiNum1[0]*digiNum2[0]);
    multiplyAns+='/';
    multiplyAns+=to_string(digiNum1[1]*digiNum2[1]);
    cout<<simplify(multiplyAns)<<endl;
    cout<<simNum1<<" / ";
    cout<<simNum2<<" = ";
    //判断是否是除以0的
    if (simNum2=="0")
        cout<<"Inf";
    else {
        string divideAns=to_string(digiNum1[0]*digiNum2[1]);
        divideAns+='/';
        divideAns+=to_string(digiNum1[1]*digiNum2[0]);
        if (divideAns.find('-')!=string::npos) {
            divideAns.erase(divideAns.find('-'),1);
            divideAns.insert(0,"-");
        }
        cout<<simplify(divideAns);
    }
    return 0;
}