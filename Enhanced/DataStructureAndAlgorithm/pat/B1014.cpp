#include<string>
#include<iostream>
#include<vector>
using namespace std;

//��һ�к͵ڶ��е�һ����ͬ��д��ĸ��������
//�ڶ�����ͬ�ַ�������ͷ�����ֻ��ߴ�д��ĸ
//�����е�һ����ͬ��Ӣ����ĸ��λ�ô������

int main() {
    vector<string> days={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    string str1,str2,str3,str4;
    cin>>str1>>str2>>str3>>str4;
    int size=str1.size()<str2.size()?str1.size():str2.size();
    int i=0;
    while(i<size) {
        if (str1[i]==str2[i]&&isupper(str1[i])&&'A'<=str1[i]&&str1[i]<='G')//��Ϊһ��ֻ�����죬���Ե�һ����ͬ���ַ�Ӧ����A-G
        {
            cout<<days[(int)str1[i]-(int)'A']<<" ";//����ѭ������Ȼ�����������
            break;
        }
        i++;
    }
    i++;
    //����Ҫע��Ҫ��i+1����Ȼ���¼���͵�һ����ͬ�ַ�һ����
    while (i<size) {
    if (isdigit(str1[i])&&str1[i]==str2[i]) {
        cout<<"0"<<str1[i];
        break;
    }
    else if (isupper(str1[i])&&'A'<=str1[i]&&str1[i]<='N'&&str1[i]==str2[i]) {
            cout<<(int)str1[i]-(int)'A'+10;
            break;
        }
        //����ƥ�䵫�������ֻ��ߴ�д��ĸ�����
        i++;
    }
    int size2=str3.size()<str4.size()?str3.size():str4.size();
    for (int j=0;j<size2;j++) {
    if (str3[j]==str4[j]&&isalpha(str3[j]))
        if (j<10) {
            {
                cout<<":"<<"0"<<j;
                break;
            }
        }
        else {
            cout<<":"<<j;
            break;
        }
    }
    return 0;
}