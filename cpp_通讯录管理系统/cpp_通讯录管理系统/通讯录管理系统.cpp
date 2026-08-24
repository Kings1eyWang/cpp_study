#include<iostream>
#include<string>
#define MAX 1000

using namespace std;

//菜单界面
void showMenu()
{
	cout << "*****************************" << endl;
	cout << "*********1. 添加联系人*******" << endl;
	cout << "*********2. 显示联系人*******" << endl;
	cout << "*********3. 删除联系人*******" << endl;
	cout << "*********4. 查找联系人*******" << endl;
	cout << "*********5. 修改联系人*******" << endl;
	cout << "*********6. 清空联系人*******" << endl;
	cout << "*********0. 退出通讯录*******" << endl;
	cout << "*****************************" << endl;
}

//联系人的结构体信息
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Address;

};

//通讯录的结构体信息
struct AddressBooks
{
	struct Person personArray[MAX];//联系人信息
	int m_Size;//联系人的个数
};

//1.添加联系人
void addPerson(struct AddressBooks* abs)
{
	//如果通讯录已经满了则直接不再添加
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，不再添加" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (1)
		{
			cin >> sex;
			//如果输入的正确就跳出循环，否则一直输入
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//年龄
		cout << "请输入用户的年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//住址
		cout << "请输入家庭地址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Address = address;

		//更新通讯录中的人数
		abs->m_Size++;

		cout << "添加成功" << endl;

		system("pause");//按任意键继续
		system("cls");//清屏操作
	}
}

//2.显示联系人
void showPerson(struct AddressBooks* abs)
{
	//判断通讯录内人数是否为0，提示
	if (abs->m_Size == 0)
	{
		cout << "此通讯录为空" << endl;

	}
	else
	{
		for (int i = 0;i < abs->m_Size;i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex ==1?"男":"女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "地址：" << abs->personArray[i].m_Address<< endl;
		}
	}
	system("pause");//按任意键继续
	system("cls");//清屏操作
}


//检测联系人是否存在，如果存在，返回联系人所在的数组的具体位置，不存在则返回-1
//参数1 通讯录 参数2 对比的人名
int isExist(struct AddressBooks* abs, string name)
{
	for (int i = 0;i < abs->m_Size;i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}



//3.删除联系人
void delPerson(struct AddressBooks* abs)
{
	cout << "请输入要删除的联系人的姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if ( ret != -1)
	{
		//查到此人，进行删除操作，那么就是将后面的人一个一个前移
		for (int i = ret;i < abs->m_Size;i++)
		{
			//数据前移的操作
			abs->personArray[i] = abs->personArray[i + 1];
		}
		//更新通讯录中的人员数
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "你输入的名字并不存在" << endl;
	}

	system("pause");
	system("cls");
}

//4.查找联系人
void findPerson(struct AddressBooks* abs)
{
	cout << "请输入要查找的联系人的姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "地址：" << abs->personArray[ret].m_Address << endl;
	}
	else
	{
		cout << "你输入的名字并不存在" << endl;
	}

	system("pause");
	system("cls");
}

//5.修改联系人
void modifyPerson(struct AddressBooks* abs)
{
	cout << "请输入要修改的联系人的姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//修改姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//修改性别
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (1)
		{
			cin >> sex;
			//如果输入的正确就跳出循环，否则一直输入
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//年龄
		cout << "请输入用户的年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//住址
		cout << "请输入家庭地址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Address = address;

		cout << "修改成功！" << endl;

	}
	else
	{
		cout << "你输入的名字并不存在" << endl;
	}

	system("pause");
	system("cls");
}

//6.清空联系人
void clearPerson(struct AddressBooks* abs)
{
	string str;
	while (1)
	{
		cout << "你确定要清空所有联系人吗？请输入[yes/no]" << endl;
		cin >> str;
		if (str == "yes")
		{
			//将通讯录的联系人数量置为0，做逻辑清空即可
			abs->m_Size = 0;
			cout << "通讯录已为空" << endl;
			break;
		}
		else if (str == "no")
		{
			cout << "你已经放弃清空联系人操作！" << endl;
			break;
		}
		else
		{
			cout << "请输入有效字符！" << endl;
			continue;
		}
	}
	
	system("pause");
	system("cls");
}

int main()
{
	//创建通讯录结构体变量
	AddressBooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;


	int select = 0;//创建用户选择输入的变量
	
	
	while (1)
	{
		//菜单调用
		showMenu();
		cout << "请输入您的选择：" << endl;
		cin >> select;

		switch (select)
		{
		case 1: //1. 添加联系人
			addPerson(&abs);//利用地址传递可以修饰实参
			break;
		case 2: //2. 显示联系人
			showPerson(&abs);
			break;
		case 3: //3. 删除联系人
			delPerson(&abs);
			break;
		case 4: //4. 查找联系人
			findPerson(&abs);
			break;
		case 5: //5. 修改联系人
			modifyPerson(&abs);
			break;
		case 6: //6. 清空联系人
			clearPerson(&abs);
			break;
		case 0: //0.退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default: 
			cout << "请输入正确的选项" << endl;
			break;
		}
	}


	system("pause");
	return 0;

}