#include<iostream>
#include"Identity.h"
#include<fstream>
#include"globalfile.h"
#include"manager.h"
#include"student.h"
#include"teacher.h"

using namespace std;

//进入管理员子菜单界面
void managerMenu(Identity* &manager)
{
	while (true)
	{
		//利用父类指针创建子类对象进而调用子类虚函数实现
		manager->operMenu();
		//将父类指针强转为子类指针，进而调用其他子类接口
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;
		if (select == 1) //添加账号
		{
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			man->showPerson();
		}
		else if (select == 3)//查看机房
		{
			man->showComputer();
		}
		else if (select == 4)//清空预约
		{
			man->clearFile();
		}
		else
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


//进入学生子菜单界面
void studentMenu(Identity*& student)
{
	while (true)
	{
		//利用父类指针创建子类对象进而调用子类虚函数实现
		student->operMenu();
		//将父类指针强转为子类指针，进而调用其他子类接口
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1) //申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2)//查看自身预约
		{
			stu->showOrder();
		}
		else if (select == 3)//查看所有预约
		{
			stu->showAllOrder();
		}
		else if (select == 4)//取消预约
		{
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入老师子菜单界面
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//利用父类指针创建子类对象进而调用子类虚函数实现
		teacher->operMenu();
		//将父类指针强转为子类指针，进而调用其他子类接口
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		if (select == 1) //查看所有预约
		{
			tea->showAllOrder();
		}
		else if (select == 2)//审核预约
		{
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}



//登录功能 参数1：打开的文件 参数2：操作身份类型
void LoginIn(string filename, int type)
{
	//首先创建一个父类指针可以指向子类对象
	Identity* person = NULL;
	//读文件
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//准备接收用户的信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1)
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入你的职工号：" << endl;
		cin >> id;
	}
	cout << "请输入你的姓名：" << endl;
	cin >> name;
	cout << "请输入你的密码：" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生身份登录验证
		int fid = 0;//从文件中获取id，name和密码，与输入的做对比
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "学生登录验证成功" << endl;
				system("pause");
				system("cls");

				person = new Student(id, name, pwd);
				//学生菜单子界面
				studentMenu(person);
				return;
			}
		}

	}
	else if (type == 2)
	{
		//教师登录验证
		int fid = 0;//从文件中获取id，name和密码，与输入的做对比
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "老师登录验证成功" << endl;
				system("pause");
				system("cls");

				person = new Teacher(id, name, pwd);
				//老师菜单子界面
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//审核员登录验证
		//从文件中获取name和密码，与输入的做对比
		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd)
		{
			if (fname == name && fpwd == pwd)
			{
				cout << "审核员登录验证成功" << endl;
				system("pause");
				system("cls");

				person = new Manager( name, pwd);
				//审核员菜单子界面
				managerMenu(person);
				return;
			}
		}

		cout << "你的验证登录失败" << endl;
		system("pause");
		system("cls");
		return;
	}
}

int main()
{
	int select = 0;//用户的输入选择
	while (true)
	{
		cout << "======================  欢迎来到小霸王机房预约系统  ====================="
			<< endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";
		cin >> select;
		switch (select)
		{
		case 1:
			//学生代表
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			//老师
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			//管理员
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			//退出系统
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "你的输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	


	system("pause");
	return 0;
}