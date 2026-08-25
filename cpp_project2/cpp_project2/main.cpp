#include<iostream>
#include<string>
#include "circle.h"
#include "point.h"

using namespace std;

//class Point
//{
//public:
//	//设置X
//	void setX(int x)
//	{
//		m_X = x;
//	}
//	//读取X
//	int getX()
//	{
//		return m_X;
//	}
//	//设置Y
//	void setY(int y)
//	{
//		m_Y = y;
//	}
//	//读取Y
//	int getY()
//	{
//		return m_Y;
//	}
//
//private:
//	int m_X;
//	int m_Y;
//};
//
//
//class Circle
//{
//public:
//	//设置半径
//	void setR(int r)
//	{
//		m_R = r;
//	}
//	//读取半径
//	int getR()
//	{
//		return m_R;
//	}
//	//设置圆心
//	void setCenter(Point center)
//	{
//		m_Center = center;
//	}
//	//读取圆心
//	Point getCenter()
//	{
//		return m_Center;
//	}
//
//
//private:
//	int m_R;//圆的半径
//	Point m_Center;//圆的圆心位置
//};

//判断点和圆的关系的函数
void isInCircle(Circle& c, Point& p)
{
	//计算两点之间的平方
	int dist1 =( (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY()));
	//计算半径的平方
	int dist2 = ((c.getR()) * (c.getR()));
	//判断关系
	if (dist1 < dist2)
	{
		cout << "点在圆内" << endl;
	}
	else if (dist1 == dist2)
	{
		cout << "点在圆上" << endl;
	}
	else
	{
		cout << "点在圆外" << endl;
	}
}

int main()
{
	//创建圆
	Circle c;
	c.setR(10);
	Point center;//因为setCenter需要这个中心
	center.setX(10);
	center.setY(0);
	c.setCenter(center);

	//创建点
	Point p;
	p.setX(10);
	p.setY(1);
	//判断关系
	isInCircle(c, p);
	


	system("pause");
	return 0;
}