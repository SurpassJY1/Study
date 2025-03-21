#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Student 
{
public:
	string m_Name;
	string m_Id;
	int m_Grade;
	Student(string name,string id,int grade):m_Name(name),m_Id(id),m_Grade(grade){}
};

class MyCompare
{
public:
	bool operator()(Student student, Student student2)
	{
		return student.m_Grade < student2.m_Grade;
	}
};

int main() 
{
	vector<Student> vec;
	int n;
	cin >> n;
	for (int i=0;i<n;i++) 
	{
		string name;
		string id;
		int grade;
		cin >> name >> id >> grade;
		Student stu(name,id,grade);
		vec.push_back(stu);
	}
	sort(vec.begin(),vec.end(),MyCompare());
	cout << vec[vec.size() - 1].m_Name << " " << vec[vec.size() - 1].m_Id << endl;
	cout << vec[0].m_Name << " " << vec[0].m_Id << endl;
	return 0;
}