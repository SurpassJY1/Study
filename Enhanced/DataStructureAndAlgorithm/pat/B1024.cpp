//
// Created by GlokieYu on 25-4-1.
//
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
/*
�ҵ�һλȷ������
��Ϊָ����ֵ������9999������Ҫ���ַ������ϵ��
�ҵ�E������������ϵ��
�ҵ��ڶ����ַ���E֮ǰ���Ǹ�ת����������
�����ż��������������ϵ��
ע��ָ������0��9999֮���
*/
int main()
{
    string input;
    cin>>input;
    string res;
    if (input[0]=='-')
        res+=input[0];//�ҵ�������
    int n=input.find('E')+1;
    //ȷ��ϵ���Ǵ���һ����С��һ
    if (input[n]=='-') {
        //ȷ����С��
        int zeroCount=0;
        //ָ���������������֮��Ϊ0��������֮��һ��0��������֮��һ������������֮��0��һ������������֮��������Ϊ0����
        // if (input[n+1]=='0'&&n+1!=input.size()-1) {//���������00
        //     zeroCount=input[n+2]-'0';
        // }else if (input[n+1]=='0'&&n+1==input.size()-1) {//����һ��0
        //     zeroCount=0;
        // }
        // else if(input[n+1]!='0'&&n+1==input.size()-1)//һ����
        // {
        //     zeroCount=input[n+1]-'0';
        // }
        // else {
        //     zeroCount=(input[n+1]-'0')*10+input[n+2]-'0';
        // }
        zeroCount=stoi(input.substr(n+1));
        //����10��ϵ��С��0��������ǰ0����ĿΪ10��ϵ�����෴��
        if(zeroCount!=0)
        {res+="0.";
        for (int i=0;i<zeroCount-1;i++) {//�Ѿ�����һ��0��
            res+='0';
        }
        //�������ԭ���ַ���1λ�õ�E֮ǰ�ģ���ҪҪȥ��2λ�õ�С����
        for (int i=1;i<input.find('E');i++) {
            if (i==2)
                continue;//����С����
            res+=input[i];
        }}else//���ԭ��������
        {
            for (int i=1;i<input.find('E');i++) {
            res+=input[i];
        }
        }
    }else {
        //Ҫ����һ������
        //С������Ʒ���ʮ��n�η��ͽ�С�������nλ���������ĩβɾȥС���㣬����n��ȥ���ָ�����0
        int count=0;//���Ʋ���
        // if (input[n+1]=='0') {
        //     count=input[n+2]-'0';
        // }else if (input[n+1]!='0'&&n+1==(input.size()-1)) {
        //     count=input[n+1]-'0';
        // }
        // else {
        //     count=(input[n+1]-'0')*10+input[n+2]-'0';
        // }
        count=stoi(input.substr(n+1));
        //ͨ���Ƚ����ֳ����ж��Ƿ�Ҫ��0��ע��������ֳ���Ҫȥ��С�����1��
        int length=input.find('E')-1-1;
        if (count>=length-1) {
            //����0
            for (int i=1;i<input.find('E');i++) {
                if (i==2)
                    continue;//����С����
                res+=input[i];
            }
            for (int i=0;i<count-length+1;i++) {
                res+='0';
            }
        }else {
            //С�������
            //ֱ���������������С����
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