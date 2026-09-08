#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>

using namespace std;

class Person
{
public:

	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name;
	int m_Score;
};
void createPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0;i < 5;i++)
	{
		string name = "选手";
		name += nameSeed[i];

		int score = 0;

		Person p(name, score);
		v.push_back(p);

	}
}

void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin();it != v.end();it++)
	{

		//将评委的分数放到deque容器中
		deque<int>d;
		for (int i = 0;i < 10;i++)
		{

			int score = rand() % 41 + 60;//要60-100的分数
			d.push_back(score);
		}
		//排序
		sort(d.begin(), d.end());
		//去除最高分和最低分
		d.pop_back();
		d.pop_front();
		//去平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin();dit != d.end();dit++)
		{
			sum += (*dit);

		}
		int avg = sum / d.size();

		it->m_Score = avg;


	}
}

void showScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin();it != v.end();it++)
	{
		cout << "姓名：" << it->m_Name << " 分数：" << it->m_Score << endl;
	}
}


int main()
{

	srand(unsigned int(time(NULL)));

	//1.创建5名选手
	vector<Person> v;
	createPerson(v);

	//测试
	//for (vector<Person>::iterator it = v.begin();it != v.end();it++)
	//{
	//	cout << "姓名：" << (*it).m_Name << " 分数：" << (*it).m_Score << endl;
	//}

	//2.给5名选手打分
	setScore(v);


	//3.显示最后得分
	showScore(v);
	system("pause");
	return 0;
}