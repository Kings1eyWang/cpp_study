#pragma once
#include<iostream>
#include<fstream>
#include"Worker.h"
#include"Boss.h"
#include"Manager.h"
#include"Employee.h"
using namespace std;

#define FILENAME "empfile.txt"


class WorkerManager
{
public:
	//构造函数
	WorkerManager();

	//展示菜单
	void Show_Menu();

	//退出程序
	void ExitSystem();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//添加职工
	void Add_Emp();

	// 标志文件是否为空
	bool m_FileIsEmpty;

	//统计文件中人数
	int get_EmpNum();

	//初始化成员
	void Init_Emp();

	//显示职工信息
	void Show_Emp();

	//删除职工
	void Del_Emp();

	//判断职工是否存在,存在返回在数组中的位置，不存在返回-1
	int IsExist(int id);

	//保存文件
	void save();

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//按照编号排序
	void Sort_Emp();

	//清空文档
	void Clean_File();


	//析构函数
	~WorkerManager();
};
