#include<string>
#include<iostream>
#include<vector>
using namespace std;

//第一行和第二行第一对相同大写字母代表日期
//第二对相同字符代表钟头，数字或者大写字母
//三四行第一对相同的英文字母的位置代表分钟

int main() {
    vector<string> days={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    string str1,str2,str3,str4;
    cin>>str1>>str2>>str3>>str4;
    int size=str1.size()<str2.size()?str1.size():str2.size();
    int i=0;
    while(i<size) {
        if (str1[i]==str2[i]&&isupper(str1[i])&&'A'<=str1[i]&&str1[i]<='G')//因为一周只有七天，所以第一个相同的字符应该在A-G
        {
            cout<<days[(int)str1[i]-(int)'A']<<" ";//结束循环，不然会接着往下找
            break;
        }
        i++;
    }
    i++;
    //这里要注意要让i+1，不然会记录到和第一个相同字符一样的
    while (i<size) {
    if (isdigit(str1[i])&&str1[i]==str2[i]) {
        cout<<"0"<<str1[i];
        break;
    }
    else if (isupper(str1[i])&&'A'<=str1[i]&&str1[i]<='N'&&str1[i]==str2[i]) {
            cout<<(int)str1[i]-(int)'A'+10;
            break;
        }
        //处理匹配但不是数字或者大写字母的情况
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