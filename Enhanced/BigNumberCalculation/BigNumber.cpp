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
    //������д������
    vector<int> num1(1000, 0);
    vector<int> num2(1000, 0);
    for (int i = 0; i < s1.size(); i++) {
        num1[s1.size() - i - 1] = s1[i] - '0';
    }
    for (int i = 0; i < s2.size(); i++) {
        num2[s2.size() - i - 1] = s2[i] - '0';
    }
    vector<int> num3;
    int size = s1.size() > s2.size() ? s1.size() : s2.size(); //��¼�������ֳ���
    for (int i = 0; i < size; i++) {
        num3.push_back(num1[i] + num2[i]);
    }
    //ģ����ʽ�����λ
    //��������ӵĽ��λ�����ᳬ�����������������Ǹ���һ
    for (int i = 0; i < size + 1; i++) {
        if (num3[i] >= 10) {
            num3[i + 1] += num3[i] / 10;
            num3[i] = num3[i] % 10;
        }
    }
    //num1��num2�Ľ����λ�����ᳬ��num1��num2��λ�������Ǹ���1
    if (num3[size + 1] != 0)
        size++;
    for (int i = size - 1; i >= 0; i--) //��������ǳ��ȼ�1
    {
        cout << num3[i]; //����������
    }
}

void bigNumberDelete() {
    string s1, s2;
    cin >> s1 >> s2;
    char flag = '+';
    //�ַ������ȵĴ�Ĵ󣬱�֤s1ʼ���Ǵ���Ǹ�
    //��������s1С��s2���ı����
    if (s1.size() < s2.size()) {
        swap(s1, s2);
        flag = '-';
    } else if (s1.size() == s2.size()) {
        if (s1 < s2) //�ַ�������һ����ֱ�ӱȽ��ֵ���
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
    //����洢��������
    vector<int> num3(1000, 0);
    for (int i = 0; i < s1.size(); i++) {
        if (num1[i] < num2[i]) //��λ
        {
            num1[i] += 10;
            num1[i + 1]--;
        }
        num3[i] = num1[i] - num2[i];
    }
    //�������λ���϶����ᳬ������Ǹ�����λ��
    //s1��¼���Ѿ��Ǵ���Ǹ��ˣ����Դ�s1��Ӧ��λ�������ҽ���Ŀ�ʼλ��
    int index = s1.size() - 1;
    while (num3[index] == 0) {
        index--;
    }
    //�ж�flag������
    if (flag == '-')
        cout << flag;
    for (int i = index; i >= 0; i--) {
        cout << num3[i];
    }
}

//�����ɱ�׼��
void bigNumberMultiply() {
    string s1;
    int num2;
    cin >> s1 >> num2;
    vector<int> num1(1000, 0);
    //���Ŵ������
    for (int i = 0; i < s1.size(); i++) {
        num1[s1.size()-i-1] = s1[i]-'0';
    }
    for (int i=s1.size()-1;i>=0;i--) {
        cout<<num1[i];
    }
    cout<<endl;
    for (int i = 0; i < s1.size(); i++) {
        num1[i] =num1[i]* num2;//���������ѭ�����ж��Ƿ��λ����������λ��֮��˷�������
    }
    //��λ���,λ�����ᳬ��num1+num2
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
//bignumber multiply�������˴���
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
//����������������������Ǵ���
void bigNumberDivision() {
    int a,b,n;//n�Ǳ���λ��
    cin>>a>>b>>n;
    cout<<a/b;
    cout<<".";
    int t=a%b;//��t��������
    for (int i=0;i<n;i++) {
        t*=10;
        cout<<t/b;
        t=t%b;
    }
}
//�������������������̺�����
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
        t=t*10+num1[i];//��һ�������˴���һ����λ
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
