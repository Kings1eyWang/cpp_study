#include <iostream>
#include "WorkerManager.h"
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
using namespace std;


int main()
{
	////测试代码
	//Worker* worker = NULL;
	//worker = new Employee(1, "张三", 1);
	//worker->showInfo();
	//delete worker;

	//worker = new Manager(2, "李四", 2);
	//worker->showInfo();
	//delete worker;

	//worker = new Boss(3, "王五", 3);
	//worker->showInfo();
	//delete worker;



	//实例化管理者对象
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		//显示菜单
		wm.Show_Menu();
		cout << "请输入你的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			//增加职工
			wm.Add_Emp();
			break;
		case 2:
			//显示职工
			wm.Show_Emp();
			break;
		case 3:
			//删除职工
			wm.Del_Emp();
			break;
		case 4:
			//修改职工
			wm.Mod_Emp();
			break;
		case 5:
			//查找职工
			wm.Find_Emp();
			break;
		case 6:
			//按照编号排序
			wm.Sort_Emp();
			break;
		case 7:
			//清空所有档案
			wm.Clean_File();
			break;
		case 0:
			//退出系统
			wm.ExitSystem();
			break;
		default:
			system("cls");
			break;
		}
	}
	
	system("pause");
	return 0;
}