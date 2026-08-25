#pragma once
#include<iostream>
#include "point.h"
using namespace std;

class Circle
{
public:
	//设置半径
	void setR(int r);
	
	//读取半径
	int getR();
	
	//设置圆心
	void setCenter(Point center);
	
	//读取圆心
	Point getCenter();
	


private:
	int m_R;//圆的半径
	Point m_Center;//圆的圆心位置
};