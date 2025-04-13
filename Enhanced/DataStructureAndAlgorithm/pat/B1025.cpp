/*
* ����һ������ K �Լ�һ�������� L�����д���� L ��ÿ K ����㷴ת�����磺���� L Ϊ 1��2��3��4��5��6��K Ϊ 3��
* �����Ӧ��Ϊ 3��2��1��6��5��4����� K Ϊ 4�������Ӧ��Ϊ 4��3��2��1��5��6������󲻵� K ��Ԫ�ز���ת��
�����ʽ��

ÿ��������� 1 ������������ÿ������������ 1 �и����� 1 �����ĵ�ַ������ܸ��������� N (��10
5
 )���Լ������� K (��N)����Ҫ��ת���������ĸ��������ĵ�ַ�� 5 λ�Ǹ�������NULL ��ַ�� ?1 ��ʾ��

�������� N �У�ÿ�и�ʽΪ��

Address Data Next
���� Address �ǽ���ַ��Data �Ǹý�㱣����������ݣ�Next ����һ���ĵ�ַ��

�����ʽ��

��ÿ������������˳�������ת�����������ÿ�����ռһ�У���ʽ��������ͬ��
 */
#include<iostream>
#include<list>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
/*
 * ��printf�������cout���ܳ�ʱ
 * ��ɢ�д洢���ڵ��Ӧ�����ݺ���һ���ڵ�ĵ�ַ��
 * list�����ǽڵ��Ӧ�ĵ�ַ
 */
string turnToValid(int address) {
 string str=to_string(address);
 if(address==-1||str.size()==5)
  return str;
 else
 {
  while (str.size()<5) {
   str.insert(0,"0");
  }
  return str;
 }
}
int main() {
 int data[100001]={-1};
 int next[100001]={-1};
 vector<int> list;
 int address,N,K;
 cin>>address>>N>>K;
 for (int i=0;i<N;i++) {
  int temp;
  cin>>temp;
  cin>>data[temp]>>next[temp];
 }
 //�������飬�洢�ڵ�ĵ�ַ
 //��Ϊ���ܻ����벻���ڸ������ϵĽڵ㣬����Ҫ��¼��Ч��ֵ
 int count=0;
 while (address!=-1) {
  list.push_back(address);
  address=next[address];
  count++;
 }
 //��ת
 auto it=list.begin();
 while(count-K>=0){
  reverse(it,it+K);
  it=it+K;
  count=count-K;
 }
 for (auto it=list.begin();it!=list.end();it++) {
  if (it==list.end()-1)
   cout<<turnToValid((*it))<<" "<<data[(*it)]<<" "<<-1<<endl;
  else cout<<turnToValid((*it))<<" "<<data[(*it)]<<" "<<turnToValid(*(it+1))<<endl;
 }
 return 0;
}