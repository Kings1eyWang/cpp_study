#include<iostream>
#include<vector>
#include<ctime>
#include<string>
#include<map>

using namespace std;
#define design 0
#define art 1
#define tech 2

/*
- 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
- 员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
- 随机给10名员工分配部门和工资
- 通过multimap进行信息的插入  key(部门编号) value(员工)
- 分部门显示员工信息
*/

class Worker
{


public:
	string m_Name;
	int m_Salary;
};

void createWorker(vector<Worker>&v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0;i < 10;i++)
	{
		Worker worker;
		worker.m_Name = "员工";
		worker.m_Name += nameSeed[i];
		
		worker.m_Salary = rand() % 10000 + 10000;//10000-19999
		v.push_back(worker);
	}
}

void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin();it != v.end();it++)
	{
		//产生部门编号
		int depId = rand() % 3;
		//将员工插入分组中
		//key:部门id，value:员工信息
		m.insert(make_pair(depId, *it));
	}
}

void showWorkerByGroup(multimap<int, Worker>& m)
{
	cout << "策划部门：" << endl;
	multimap<int, Worker>::iterator pos = m.find(design);
	int count = m.count(design);//统计具体人数
	int index = 0;
	for (;pos != m.end() && index < count;pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << " 薪水：" << pos->second.m_Salary << endl;
	}

	cout << "--------------------" << endl;
	cout << "美术部门：" << endl;
	pos = m.find(art);
	count = m.count(art);//统计具体人数
	index = 0;
	for (;pos != m.end() && index < count;pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << " 薪水：" << pos->second.m_Salary << endl;
	}

	cout << "--------------------" << endl;
	cout << "技术部门：" << endl;
	pos = m.find(tech);
	count = m.count(tech);//统计具体人数
	index = 0;
	for (;pos != m.end() && index < count;pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << " 薪水：" << pos->second.m_Salary << endl;
	}
}


int main()
{
	srand((unsigned int)time(NULL));
	//1.创建员工
	vector<Worker>vWorker;
	createWorker(vWorker);
	//测试
	/*for (vector<Worker>::iterator it = vWorker.begin();it != vWorker.end();it++)
	{
		cout << "姓名："<<it->m_Name<<" 薪水："<<it->m_Salary << endl;

	}*/
	//2.员工分组
	multimap<int, Worker>mWorker;
	setGroup(vWorker,mWorker);

	//3.分组显示员工
	showWorkerByGroup(mWorker);


	system("pause");
	return 0;

}