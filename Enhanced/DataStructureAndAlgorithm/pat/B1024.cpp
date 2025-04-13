//
// Created by GlokieYu on 25-4-1.
//
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
/*
找第一位确认正负
因为指数数值不超过9999，所以要用字符串算出系数
找到E后面的数字算出系数
找到第二个字符和E之前的那个转成数字主题
正负号加上数字主题乘以系数
注意指数是在0到9999之间的
*/
int main()
{
    string input;
    cin>>input;
    string res;
    if (input[0]=='-')
        res+=input[0];//找到正负号
    int n=input.find('E')+1;
    //确认系数是大于一还是小于一
    if (input[n]=='-') {
        //确认是小数
        int zeroCount=0;
        //指数的情况：正负号之后为0，正负号之后一个0，正负号之后一个数，正负号之后0加一个数，正负号之后两个不为0的数
        // if (input[n+1]=='0'&&n+1!=input.size()-1) {//这里包括了00
        //     zeroCount=input[n+2]-'0';
        // }else if (input[n+1]=='0'&&n+1==input.size()-1) {//单走一个0
        //     zeroCount=0;
        // }
        // else if(input[n+1]!='0'&&n+1==input.size()-1)//一个数
        // {
        //     zeroCount=input[n+1]-'0';
        // }
        // else {
        //     zeroCount=(input[n+1]-'0')*10+input[n+2]-'0';
        // }
        zeroCount=stoi(input.substr(n+1));
        //若是10的系数小于0，则数字前0的数目为10的系数的相反数
        if(zeroCount!=0)
        {res+="0.";
        for (int i=0;i<zeroCount-1;i++) {//已经补过一个0了
            res+='0';
        }
        //正常添加原本字符串1位置到E之前的，主要要去掉2位置的小数点
        for (int i=1;i<input.find('E');i++) {
            if (i==2)
                continue;//跳过小数点
            res+=input[i];
        }}else//输出原本的数字
        {
            for (int i=1;i<input.find('E');i++) {
            res+=input[i];
        }
        }
    }else {
        //要乘以一个整数
        //小数点后移法，十的n次方就将小数点后移n位，如果到了末尾删去小数点，补上n减去数字个数个0
        int count=0;//后移步数
        // if (input[n+1]=='0') {
        //     count=input[n+2]-'0';
        // }else if (input[n+1]!='0'&&n+1==(input.size()-1)) {
        //     count=input[n+1]-'0';
        // }
        // else {
        //     count=(input[n+1]-'0')*10+input[n+2]-'0';
        // }
        count=stoi(input.substr(n+1));
        //通过比较数字长度判断是否要补0，注意计算数字长度要去掉小数点的1个
        int length=input.find('E')-1-1;
        if (count>=length-1) {
            //补上0
            for (int i=1;i<input.find('E');i++) {
                if (i==2)
                    continue;//跳过小数点
                res+=input[i];
            }
            for (int i=0;i<count-length+1;i++) {
                res+='0';
            }
        }else {
            //小数点后移
            //直接添加所有数包括小数点
            for (int i=1;i<input.find('E');i++) {
                res+=input[i];
            }
            for (int i=0;i<count;i++) {
                swap(res[res.find('.')],res[res.find('.')+1]);
            }
        }
    }
    cout<<res<<endl;
    return 0;
}