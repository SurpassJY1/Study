/*
* 给定一个常数 K 以及一个单链表 L，请编写程序将 L 中每 K 个结点反转。例如：给定 L 为 1→2→3→4→5→6，K 为 3，
* 则输出应该为 3→2→1→6→5→4；如果 K 为 4，则输出应该为 4→3→2→1→5→6，即最后不到 K 个元素不反转。
输入格式：

每个输入包含 1 个测试用例。每个测试用例第 1 行给出第 1 个结点的地址、结点总个数正整数 N (≤10
5
 )、以及正整数 K (≤N)，即要求反转的子链结点的个数。结点的地址是 5 位非负整数，NULL 地址用 ?1 表示。

接下来有 N 行，每行格式为：

Address Data Next
其中 Address 是结点地址，Data 是该结点保存的整数数据，Next 是下一结点的地址。

输出格式：

对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。
 */
#include<iostream>
#include<list>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
/*
 * 用printf输出，用cout可能超时
 * 用散列存储，节点对应的数据和下一个节点的地址，
 * list里存的是节点对应的地址
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
 //创建数组，存储节点的地址
 //因为可能会输入不存在该链表上的节点，所以要记录有效数值
 int count=0;
 while (address!=-1) {
  list.push_back(address);
  address=next[address];
  count++;
 }
 //反转
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