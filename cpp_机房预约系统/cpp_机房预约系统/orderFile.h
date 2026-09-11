#pragma once
#include<iostream>
#include"globalfile.h"
#include<map>
#include<fstream>

using namespace std;

class OrderFile
{
public:
	//构造函数
	OrderFile();

	//更新预约记录
	void updateOrder();

	//记录预约条数
	int m_Size;

	//map容器，存放记录，key:记录的条数 value:具体记录的键值对，例如、date:1
	map<int, map<string, string>> m_orderData;

};