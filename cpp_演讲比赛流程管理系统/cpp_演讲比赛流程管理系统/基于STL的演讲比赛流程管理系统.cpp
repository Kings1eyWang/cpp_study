#include"speechManager.h"


int main()
{
	//创建管理类对象
	SpeechManager sm;
	//用于存储用户输入
	int choice = 0;
	////测试12名选手的创建
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin();it != sm.m_Speaker.end();it++)
	//{
	//	cout << "编号：" << it->first << " 姓名：" << it->second.m_Name << " 分数：" << (*it).second.m_Score[0] << endl;
	//}

	srand((unsigned int)time(NULL));//随机数种子

	while (true)
	{
		//展示菜单
		sm.showMenu();
		cout << "选择你要进行的操作（0-3）：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			//1.开始演讲比赛
			sm.startSpeech();
			break;
		case 2:
			//2.查看往届记录
			sm.showRecord();
			break;
		case 3:
			//3.清空比赛记录
			sm.cleanRecord();
			break;
		case 0:
			//0.退出比赛程序
			sm.exitSystem();
			break;
		default:
			system("cls");
			break;

		}
		
	}

	system("pause");
	return 0;
}