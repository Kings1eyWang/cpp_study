#pragma once
#include"Worker.h"
#include<iostream>
#include<string>
using namespace std;

class Manager :public Worker
{
public:
	//构造函数
	Manager(int id, string name, int did);
	//虚拟展示信息
	virtual void showInfo();
	//虚拟得到部门编号
	virtual string getDeptName();
};