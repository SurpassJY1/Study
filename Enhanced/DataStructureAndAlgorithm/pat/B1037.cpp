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
˼·��
ȫ��ת��������
ת����Ӧ�ҵ�����
�ٰ�����ת���ɶ�Ӧ��Ǯ
ע�⣺ȫ��ת�������ɿ��ܻᳬ��Χ

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
    //����a��Զ��
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
    //��a�𽥼ӵ�p��ֵ
    while (!isSame(p,a)) {
        p[2]++;
        gap++;

        // ���� Knut ��λ
        if (p[2] >= 29) {
            p[2] = 0;
            p[1]++;

        }

        // ���� Sickle ��λ
        if (p[1] >= 17) {
            p[1] = 0;
            p[0]++;

        }
    }
    //��gapת��Ϊ��Ӧ��ʽ
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