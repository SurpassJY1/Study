//
// Created by GlokieYu on 25-4-3.
//
#include<iostream>
#include<string>
#include<unordered_set>
#include<cctype>//��Сдת����
using namespace std;

void store(char c,unordered_set<char>&badKey)
{

    if(c=='+')
    {
        for(char a='A';a<='Z';a++)
        {
            badKey.emplace(a);
        }
    }else if(c=='_')
    {
        badKey.emplace(' ');
    }else if(c==','||c=='.')
    {
        badKey.emplace(c);
    }else if(c>='0'&&c<='9')
    {
        badKey.emplace(c);
    }
    else
    {
        badKey.emplace(c);
        badKey.emplace(tolower(c));
    }
}
bool isFound(unordered_set<char> badKey,char c)
{
    return badKey.find(c)!=badKey.end();
}
int main()
{
    string broken;
    string input;
    string real;
    getline(cin,broken);
    getline(cin,input);//�п����пո�������getline
    /*
    Ӣ����ĸ�����ô�д������дСд��������
    +�����˲��ܳ��ִ�Щ��ĸ
    _���˾�Ҫ�ѿ��ַ�����
    ����û�л���
    */
    if(broken.size()==0)
        cout<<input<<endl;
    else
    {
        unordered_set<char> badKey;
        //�����л����浽��ϣ���������ַ��ڹ�ϣ���д��ھ�����
        for(int i=0;i<broken.size();i++)
        {
            store(broken[i],badKey);
        }
        for(int i=0;i<input.size();i++)
        {
            if(isFound(badKey,input[i]))
                continue;
            else
            {
                real+=input[i];
            }
        }
        cout<<real;
    }
    return 0;
}