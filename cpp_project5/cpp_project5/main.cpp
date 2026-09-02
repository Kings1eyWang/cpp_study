#include <iostream>
using namespace std;
#include"MyArray.hpp"

void printIntarray(MyArray<int>& arr)
{
	for (int i = 0;i < arr.getSize();i++)
	{
		cout << arr[i] << endl;
	}
}

void test01()
{
	MyArray<int>arr1(5);
	//MyArray<int>arr2(arr1);
	//MyArray<int>arr3(100);
	//arr3 = arr1;
	for (int i = 0;i < 5;i++)
	{
		//利用尾插法向数组中插入数据
		arr1.Push_Back(i);
	}
	printIntarray(arr1);
	cout << "arr1中的容量：" << arr1.getCapacity() << endl;
	cout << "arr1中的大小：" << arr1.getSize() << endl;

	MyArray<int>arr2(arr1);
	cout << "arrr2的打印输出为：" << endl;
	printIntarray(arr2);

	//尾删
	arr2.Pop_Back();
	cout << "arr2尾删后：" << endl;
	cout << "arr1中的容量：" << arr2.getCapacity() << endl;
	cout << "arr1中的大小：" << arr2.getSize() << endl;

}

//测试自定义数据类型
class Person
{
public:

	Person() {};
	Person(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}

	string m_Name;
	int m_Age;

};
void printPersonarray(MyArray<Person>& arr)
{
	for (int i = 0;i < arr.getSize();i++)
	{
		cout << "姓：" << arr[i].m_Name << " 年龄：" << arr[i].m_Age << endl;
	}
}


void test02()
{
	MyArray<Person> arr(10);
	Person p1("sun", 999);
	Person p2("li", 20);
	Person p3("wang", 19);
	Person p4("chen", 51);
	Person p5("zhang", 63);

	//将数据都插入到数组中
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);

	printPersonarray(arr);
	cout << "arr中的容量：" << arr.getCapacity() << endl;
	cout << "arr中的大小：" << arr.getSize() << endl;
}

int main()
{
	test01();
	test02();

	system("pause");
	return 0;
}