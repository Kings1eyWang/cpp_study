#pragma once
#include<iostream>
#include"Identity.h"
#include"computerRoom.h"
#include<vector>
#include"globalfile.h"
#include<fstream>
#include"orderFile.h"

using namespace std;

class Student :public Identity
{
public:
	//构造函数
	Student();

	//有参构造 参数：学号，姓名，密码
	Student(int id,string name,string pwd);

	//菜单界面
	virtual void operMenu();

	//申请预约
	void applyOrder();

	//查看预约
	void showOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	//学生学号
	int m_Id;
	//机房容器
	vector<ComputerRoom>vCom;
};