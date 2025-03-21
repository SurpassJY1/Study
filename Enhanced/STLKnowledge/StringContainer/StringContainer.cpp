#include<iostream>
#include<string>
using namespace std;

/*
string�� char* ������
char*��һ��ָ��
string��һ�����࣬���ڲ���װ��char*����������ַ�������һ��char*����
�ص㣺
string�ڲ���װ�˺ܶ��Ա����
find
copy
delete
replace
insert

string�Ĺ��캯��
string()
string(const char* s)
string(const string& s)
string(int n,char c)
�ַ���ƴ��
+=��������
append(const string& s,int pos,int )
���Һ��滻
find(string s,int start);
rfind(string s,int start);
�ҵ��˷����±꣬û�ҵ�����-1��rfind��find��������rfind����������
�滻
replace(int pos,int n,const string& str)��pos��ʼn���ַ�Ϊstr
*/
//string�Ĺ��캯��
void test01()
{
	string s1;
	const char* str = "Hello world";
	string s2(str);
	cout << s2 << endl;
	string s3 (s2);
	cout << s3 << endl;
	string s4(10,'a');
	cout << s4 << endl;
}
//string�ĸ�ֵ����
void test02()
{
	string str1;
	str1 = "Hello world";
	cout << str1 << endl;
	string str2 = str1;
	cout <<"str2: "<< str2 << endl;
	string str3 ;
	str3 = 'a';
	cout << str3 << endl;
	string str4;
	str4.assign("Hello assign");
	cout << "str4 " << str4 << endl;
	string str5;
	//��ȡǰ����ַ�
	str5.assign("Hello c++",5);
	cout << "str5: " << str5 << endl;
	string str6;
	str6.assign(10,'p');
	cout << "str6 " << str6 << endl;
}
//�ַ���ƴ��
void test03()
{
	string str1 = "��";
	str1 += "��������";
	cout << str1 << endl;
	str1 += ':';
	cout << str1 << endl;
	string str2 = ",����������";
	str1 += str2;
	cout << str1;
}
//�ַ���ƴ�� append
void test04()
{
	string str1 = "I";
	str1.append(" Love ");
	str1.append("You are a SB",0,3);//����2�ǽ�ȡ���ַ�����ʼλ�ã�����3�ǽ�ȡ���ַ�����
	cout << str1;
}
//����
void test05()
{
	string str1 = "abcde";
	int pos = str1.find("bc");
	int pos2 = str1.find("n");//-1
	cout << pos<<endl;
	cout << pos2 << endl;
	pos = str1.rfind("bc");
	pos2 = str1.rfind("n");//-1
	cout << pos << endl;
	cout << pos2 << endl;
	//find��rfind������find�Ǵ��������ң�rfind�Ǵ���������
}
//�滻
void test06()
{
	string str1 = "abcdefg";
	//��1��λ����3���ַ��滻Ϊ1111
	str1.replace(1, 3, "1111");
	cout << str1 << endl;
}
int main()
{
	test02();
	return 0;
}