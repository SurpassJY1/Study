#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;
/*
五名选手，选手ABCDE，是个评委对每一名选手打分，去除最高分与最低分，取平均分
*/

class Person
{
public:
	string m_name;
	int m_score;
	Person() {}
	Person(string name) :m_name(name){}
	Person(string name,int score):m_name(name),m_score(score) {}
};
void createPlayers(vector<Person> &v)
{
	string nameSeed = "ABCDE";
	for (size_t i = 0; i < 5; i++)
	{
		string name = "Player ";
		name += nameSeed[i];
		Person p(name,0);
		v.push_back(p);
	}
}

void show(vector<Person> &v)
{
	for (vector<Person>::const_iterator it=v.begin();it!=v.end();it++)
	{
		cout << (*it).m_name << " " << "Score: " << (*it).m_score << endl;
	}
}

void setScore(vector<Person> &v)
{
	//将分数放入deque容器
	deque<int> scores;
	for  (vector<Person>::iterator it=v.begin();it!=v.end();it++)
	{
		for (size_t i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;//a random number between 60 and 100
			scores.push_back(score);
			cout << score << " ";
		}
		sort(scores.begin(),scores.end());
		//remove the highest and the lowest scores
		scores.pop_back();
		scores.pop_front();
		//get the average number
		int sum = 0;
		for (deque<int>::const_iterator it = scores.begin(); it !=scores.end(); it++)
		{
			sum += *it;
		}
		int avg = sum / scores.size();
		(*it).m_score = avg;
		cout << endl;
	}
}
void test()
{
	//create 5 people
	vector<Person> v;
	createPlayers(v);
	setScore(v);
	show(v);
}

int main()
{
	test();
	system("pause");
	return 0;
}