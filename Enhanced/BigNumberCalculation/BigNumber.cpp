//
// Created by GlokieYu on 25-3-30.
//
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void bigNumberAdd() {
    string s1;
    string s2;
    cin >> s1 >> s2;
    //反方向写入数组
    vector<int> num1(1000, 0);
    vector<int> num2(1000, 0);
    for (int i = 0; i < s1.size(); i++) {
        num1[s1.size() - i - 1] = s1[i] - '0';
    }
    for (int i = 0; i < s2.size(); i++) {
        num2[s2.size() - i - 1] = s2[i] - '0';
    }
    vector<int> num3;
    int size = s1.size() > s2.size() ? s1.size() : s2.size(); //记录输入数字长度
    for (int i = 0; i < size; i++) {
        num3.push_back(num1[i] + num2[i]);
    }
    //模拟竖式计算进位
    //两数字相加的结果位数不会超过两个数字中最大的那个加一
    for (int i = 0; i < size + 1; i++) {
        if (num3[i] >= 10) {
            num3[i + 1] += num3[i] / 10;
            num3[i] = num3[i] % 10;
        }
    }
    //num1加num2的结果的位数不会超过num1和num2中位数最大的那个加1
    if (num3[size + 1] != 0)
        size++;
    for (int i = size - 1; i >= 0; i--) //这里必须是长度减1
    {
        cout << num3[i]; //反方向的输出
    }
}

void bigNumberDelete() {
    string s1, s2;
    cin >> s1 >> s2;
    char flag = '+';
    //字符串长度的大的大，保证s1始终是大的那个
    //如果输入的s1小于s2，改变符号
    if (s1.size() < s2.size()) {
        swap(s1, s2);
        flag = '-';
    } else if (s1.size() == s2.size()) {
        if (s1 < s2) //字符串长度一样则直接比较字典码
            swap(s1, s2);
        flag = '-';
    }
    vector<int> num1(1000, 0);
    vector<int> num2(1000, 0);
    for (int i = 0; i < s1.size(); i++) {
        num1[s1.size() - i - 1] = s1[i] - '0';
    }
    for (int i = 0; i < s2.size(); i++) {
        num2[s2.size() - i - 1] = s2[i] - '0';
    }
    //减完存储进新数组
    vector<int> num3(1000, 0);
    for (int i = 0; i < s1.size(); i++) {
        if (num1[i] < num2[i]) //借位
        {
            num1[i] += 10;
            num1[i + 1]--;
        }
        num3[i] = num1[i] - num2[i];
    }
    //两数相减位数肯定不会超过大的那个数的位数
    //s1记录的已经是大的那个了，所以从s1对应的位数往下找结果的开始位数
    int index = s1.size() - 1;
    while (num3[index] == 0) {
        index--;
    }
    //判断flag的正负
    if (flag == '-')
        cout << flag;
    for (int i = index; i >= 0; i--) {
        cout << num3[i];
    }
}

//大数成标准数
void bigNumberMultiply() {
    string s1;
    int num2;
    cin >> s1 >> num2;
    vector<int> num1(1000, 0);
    //倒着存进数列
    for (int i = 0; i < s1.size(); i++) {
        num1[s1.size()-i-1] = s1[i]-'0';
    }
    for (int i=s1.size()-1;i>=0;i--) {
        cout<<num1[i];
    }
    cout<<endl;
    for (int i = 0; i < s1.size(); i++) {
        num1[i] =num1[i]* num2;//不能在这个循环里判断是否进位，如果这里进位了之后乘法结果会变
    }
    //诸位相乘,位数不会超过num1+num2
    for (int i=0;i<s1.size()+8;i++) {
       if ( num1[i]>=10) {
           num1[i+1]+=num1[i]/10;
           num1[i]=num1[i]%10;
       }
    }
    int index=s1.size()+8;
    while (num1[index]==0) {
        index--;
    }
    for (int i = index; i >= 0; i--) {
        cout << num1[i];
    }
}
//bignumber multiply：大数乘大数
void bigNumberMultiBig() {
    string s1,s2;
    cin>>s1>>s2;
    vector<int> num1(1000,0);
    vector<int> num2(1000,0);
    for (int i=0;i<s1.size();i++) {
        num1[s1.size()-i-1]=s1[i]-'0';
    }
    for (int i=0;i<s2.size();i++) {
        num2[s2.size()-i-1]=s2[i]-'0';
    }
    vector<int> num3(2000,0);
    for (int i=0;i<s1.size();i++) {
        for (int j=0;j<s2.size();j++) {
            num3[j+i]+=num1[j]*num2[i];
            if (num3[i+j]>=10) {
                num3[i+j+1]+=num3[i+j]/10;
                num3[i+j]%=10;
            }
        }
    }
    int index=s1.size()+s2.size()-1;
    while (num3[index]==0)
        index--;
    for (int i=index;i>=0;i--) {
        cout<<num3[i];
    }
}
//Big number division
//正常数除以正常数，结果是大数
void bigNumberDivision() {
    int a,b,n;//n是保留位数
    cin>>a>>b>>n;
    cout<<a/b;
    cout<<".";
    int t=a%b;//用t保留余数
    for (int i=0;i<n;i++) {
        t*=10;
        cout<<t/b;
        t=t%b;
    }
}
//大数除以正常数，求商和余数
void bigNumberDiviSmall() {
    string s1;
    int num2;
    cin>>s1>>num2;
    vector<int> num1(1000,0);
    vector<int> res(1000,0);
    for (int i=0;i<s1.size();i++) {
        num1[i]=s1[i]-'0';
    }
    int t=0;
    for (int i=0;i<s1.size();i++) {
        t=t*10+num1[i];//这一步包含了从上一步进位
        if (t>num2) {
            res[i]=t/num2;
            t=t%num2;
        }else {
            res[i]=0;
        }
    }
    int index=0;
    while (res[index]==0) {
        index++;
    }
    for (int i=index;i<s1.size();i++) {
        cout<<res[i];
    }
    cout<<"......"<<t;
}
int main() {
    bigNumberDiviSmall();
    return 0;
}
