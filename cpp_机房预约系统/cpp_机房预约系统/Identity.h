#pragma once
#include<iostream>

using namespace std;
//抽象出一个身份基类
class Identity
{
public:
	//操作菜单，纯虚函数实现，子类中必须实现
	virtual void operMenu() = 0;

	//用户名
	string m_Name;
	//密码
	string m_Pwd;
};