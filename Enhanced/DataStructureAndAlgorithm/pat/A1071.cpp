//
// Created by GlokieYu on 25-4-9.
//
/*
˼·��
˫ָ�룬��λ����һ����ĸ�����֣�Ȼ���õڶ���ָ���Ƶ�����ĸ�����ֵĵط���Ȼ���õ�һ��ָ���Ƶ��ڶ���ָ�����һ��λ��
*/
#include<unordered_map>
#include<iostream>
#include<string>
#include<cctype>
using namespace std;
bool isWord(char c)
{
    if(!isdigit(c)&&!isalpha(c))
        return false;
    return true;
}
int main()
{
    unordered_map<string,int> counter;
    //��Ϊ�пո�������getline
    string str;
    getline(cin,str);
    for(int i=0;i<str.size();i++)
    {
        if (isWord(str[i])) {
            string word;
            int j=i;
            while(j<str.size()&&isWord(j))
            {
                word+=tolower(str[j]);//��ĿҪСд��
                j++;
            }
            counter[word]++;
            //����i
            i=j;
        }
    }
    string max_word;
    int max=-1;
    for(auto pair:counter)
    {
       if (max<pair.second||max==pair.second&&max_word<pair.first) {
           max=pair.second;
           max_word=pair.first;
       }
    }
    cout<<max<<" "<<max_word<<endl;
    return 0;
}