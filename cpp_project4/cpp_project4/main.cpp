#include <iostream>
using namespace std;
#include<string>
#include"person.hpp"//原来的方式都是包含头文件，失败的原因：链接不到，为什么这里要.cpp才不会报错？

//1.第一种解决方法，一般不用
//编译器在先看到.h文件时找不到对应的函数实现，但是先去看.cpp的时候
// 就能先看到.cpp文件包含有.h的头文件，进而不会链接错误

//2.第二种解决方法，将.h和.cpp中的内容写到一起，将后缀名改为.hpp文件

//类模板分文件编写问题以及解决

//template<class T1,class T2>
//class Person
//{
//public:
//	Person(T1 name, T2 age);
//	
//	void showPerson();
//	
//	T1 m_Name;
//	T2 m_Age;
//};

////类外实现
//template<class T1,class T2>
//Person<T1,T2>::Person(T1 name, T2 age)
//{
//	this->m_Age = age;
//	this->m_Name = name;
//}
//
//template<class T1,class T2>
//void Person<T1, T2>::showPerson()
//{
//	cout << "姓名：" << this->m_Name << " 年龄：" << this->m_Age << endl;
//}


int main()
{
	Person<string, int>p("tim", 30);
	p.showPerson();

	system("pause");
	return 0;

}