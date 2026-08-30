#include<iostream>
#include<fstream>//包含文本操作的头文件
#include<string>
using namespace std;

void test01()
{
	//1.包含头文件 fstream
	//2.创建流对象
	ofstream ofs;
	//3.指定打开的方式
	ofs.open("test.txt", ios::out);
	//4.写内容
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：25" << endl;
	//5.关闭文件
	ofs.close();

}


void test02()
{
	//1.包含头文件，同上

	//2.创建流对象
	ifstream ifs;
	//3.打开文件并判断文件是否打开成功
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败！！" << endl;
		return;
	}
	//4.读数据
	//第一种

	//char buf[1024] = { 0 };
	//while (ifs>>buf)
	//{
	//	cout << buf << endl;
	//}

	//第二种
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf,sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}
	
	//第三种
	//string buf;
	//while (getline(ifs, buf))
	//{
	//	cout << buf << endl;
	//}

	//第四种,不建议这种方法
	char c;
	while ((c = ifs.get()) != EOF)//EOF = end of file
	{
		cout << c;
	}

	//5.关闭文件
	ifs.close();
}

//二进制文件，写文件
class Person
{
public:
	char m_Name[64];
	int m_Age;

};


void test03()
{
	//1.包含头文件 fstream
	//2.创建流对象
	ofstream ofs;
	//ofstream ofs("person.txt", ios::out|ios::binary);
	//3.打开文件
	ofs.open("person.txt", ios::out|ios::binary);
	
	//4.写内容
	Person p = { "李四",65 };
	ofs.write((const char*)&p,sizeof(Person));
	//5.关闭文件
	ofs.close();
}

//二进制方式读文件
void test04()
{
	//1.包含头文件 fstream
	//2.创建流对象
	ifstream ifs;
	//3.打开文件并判断文件是否打开成功
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！！！" << endl;
	}
	//4.写内容
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	cout << "姓名：" << p.m_Name << " 年龄：" << p.m_Age << endl;
	//5.关闭文件
	ifs.close();
}

int main()
{
	//test01();
	//test02();
	//test03();
	test04();

	system("pause");
	return 0;
}