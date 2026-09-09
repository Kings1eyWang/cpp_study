#pragma once
#include<iostream>
#include<vector>
#include<map>
#include"speaker.h"
#include <algorithm>
#include <random>
#include<deque>
#include<functional>
#include<numeric>
#include<fstream>
#include<ctime>

using namespace std;

class SpeechManager
{
public:
	//构造函数
	SpeechManager();
	//展示菜单
	void showMenu();
	//退出系统
	void exitSystem();
	//初始化容器
	void initSpeech();
	//创建12名选手
	void createSpeaker();
	//开始比赛 比赛整个流程控制函数
	void startSpeech();
	//抽签
	void speechDraw();
	//比赛
	void speechContest();
	//显示得分
	void showScore();
	//保存得分
	void saveRecord();
	//读取记录
	void loadRecord();
	//显示往届得分
	void showRecord();
	//清空比赛记录
	void cleanRecord();


	//判断文件是否为空的标志
	bool fileIsEmpty;

	//存放往届记录的容器
	map<int, vector<string>>m_Record;



	//成员属性
	//保存第一轮比赛选手编号容器
	vector<int>v1;
	//第一轮选手编号容器
	vector<int>v2;
	//胜出前三名选手的编号容器
	vector<int>vVictory;
	//存放编号以及对应具体选手的容器
	map<int, Speaker>m_Speaker;
	//比赛轮数
	int m_Index = 1;


	//析构函数
	~SpeechManager();
};