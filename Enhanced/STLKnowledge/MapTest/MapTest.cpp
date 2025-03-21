#include<map>
#include<iostream>
#include<vector>
#include<string>
#include<ctime>
using namespace std;
class Staff
{
public:
	string m_Name;
	int m_Salary;
};

void createWorker(vector<Staff>& workers)
{
	string nameseed = "ABCDEFGHIJ";
	for (size_t i = 0; i < 10; i++)
	{
		Staff s;
		s.m_Name = "Staff: ";
		s.m_Name += nameseed[i];
		s.m_Salary = rand() % 10000 + 10000;//10000 19999
		workers.push_back(s);
	}
}
void setGroup(multimap<string,Staff> &m,vector<Staff> &workers) 
{
	vector<string> dep = {"策划","美术","研发"};
	for (vector<Staff>::iterator it = workers.begin();it != workers.end();it++) 
	{
		int depId = rand() % 3; //0,1,2
		m.insert(make_pair(dep[depId],(*it)));
	}
}
void showWorkers(multimap<string,Staff> &m )
{
	//策划：ABC 美术DEF 研发GHIJ
	int count = m.count("策划");
	cout << "策划部门:" << endl;
	multimap<string, Staff>::iterator pos = m.find("策划");
	for (int index = 0;pos != m.end(),index<count;pos++,index++) 
	{
		cout << (*pos).first << " " << (*pos).second.m_Name << " Salary: " << (*pos).second.m_Salary << endl;
	}
	cout << "美术部门:" << endl;
	multimap<string, Staff>::iterator pos2 = m.find("美术");
	int count2 = m.count("美术");
	for (int index = 0;pos2 != m.end(), index < count2;pos2++,index++) {
		cout << (*pos2).first << " " << (*pos2).second.m_Name << " Salary: " << (*pos2).second.m_Salary << endl;
	}
	multimap<string, Staff>::iterator pos3 = m.find("研发");
	int count3 = m.count("研发");
	cout << "研发部门: " << endl;
	for (int index=0;pos3!=m.end(),index<count3;index++,pos3++) 
	{
		cout << (*pos3).first << " " << (*pos3).second.m_Name << " Salary: " << (*pos3).second.m_Salary << endl;
	}
}

int main()
{
	vector<Staff> workers;
	createWorker(workers);
	for (vector<Staff>::const_iterator it = workers.begin();it != workers.end();it++) 
	{
		cout << (*it).m_Name << " Salary: " << (*it).m_Salary << endl;
	}
	multimap<string, Staff> m;
	setGroup(m,workers);
	showWorkers(m);
	system("pause");
	return 0;
}