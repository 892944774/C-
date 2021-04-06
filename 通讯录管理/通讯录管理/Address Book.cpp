#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
#include <string>

#define MAX 1000

//菜单显示
void showMenu()
{
	cout << "************************" << endl;
	cout << "***** 1.添加联系人 *****" << endl;
	cout << "***** 2.显示联系人 *****" << endl;
	cout << "***** 3.删除联系人 *****" << endl;
	cout << "***** 4.查找联系人 *****" << endl;
	cout << "***** 5.修改联系人 *****" << endl;
	cout << "***** 6.清空联系人 *****" << endl;
	cout << "***** 0.退出联系人 *****" << endl;
	cout << "************************" << endl;
}

//联系人
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Number;
	string m_Addr;
};

//通讯录
struct AddrBooks
{
	struct Person personArray[MAX];//联系人数组
	int m_Size = 0;//联系人个数
};

//添加联系人
void AddPerson(AddrBooks * abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "联系人已满！" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名：";
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		cout << "请输入性别：" << endl;
		cout << "1---男生" << endl;
		cout << "2---女生 " << endl;
		int sex = 0;
		
		while (true)
		{
			int m_size = 0;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入错误，请重新输入！" << endl;
		}

		//年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//电话
		string number;
		cout << "请输入电话：" << endl;
		cin >> number;
		abs->personArray[abs->m_Size].m_Number = number;

		//住址
		string addr;
		cout << "请输入地址：" << endl;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;

		abs->m_Size++;
		cout << "注册完毕！" << endl;
	}
}

//显示联系人
void ShowPerson(AddrBooks * abs)
{
	if (abs->m_Size == 0)
		return;

	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << endl;
			cout << "性别：" << abs->personArray[i].m_Sex << endl;
			cout << "电话：" << abs->personArray[i].m_Number << endl;
			cout << "年龄：" << abs->personArray[i].m_Age << endl;
			cout << "住址：" << abs->personArray[i].m_Addr << endl;
		}
	}
}

//查找联系人是否存在
int isExistPerson(AddrBooks * abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			cout << "联系人存在。" << endl;
			return i;
		}
	}
	cout << "联系人不存在。" << endl;
	return -1;
}

void DeletePerson(AddrBooks * abs)
{
		cout << "请输入需要删除的联系人姓名：" << endl;
		string name;
		cin >> name;

		int ret = isExistPerson(abs, name);

		if (ret == 1)
		{
			for (int i = 0; i < abs->m_Size; i++)
			{
				abs->personArray[i] = abs->personArray[i + 1];
			}
			abs->m_Size--;
		}
		else
			return;
}

void FindPerson(AddrBooks * abs)
{
	cout << "请输入需要查找的人名：" << endl;
	string name;
	cin >> name;
	int ret = isExistPerson(abs, name);

	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << endl;
	}
	else
	{
		cout << "未找到此人" << endl;
		return;
	}
}
void ModifyPerson(AddrBooks * abs)
{
	cout << "请输入需要修改联系人的姓名：" << endl;
	string name;
	cin >> name;

	int ret = isExistPerson(abs, name);
	if (ret != -1)
	{
		string newname;
		cout << "请输入姓名：";
		cin >> name;
		abs->personArray[ret].m_Name = newname;

		//性别
		cout << "请输入性别：" << endl;
		cout << "1---男生" << endl;
		cout << "2---女生 " << endl;
		int sex = 0;

		while (true)
		{
			int m_size = 0;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入错误，请重新输入！" << endl;
		}

		//年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//电话
		string number;
		cout << "请输入电话：" << endl;
		cin >> number;
		abs->personArray[ret].m_Number = number;

		//住址
		string addr;
		cout << "请输入地址：" << endl;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;

		cout << "修改完毕！" << endl;
	}
}

void ClearPerson(AddrBooks * abs)
{
	abs->m_Size = 0;
}

int main()
{
	//创建一个通讯录变量
	AddrBooks abs;

	int select = 0;
	while(true)
	{
		showMenu();

		cin >> select;
		switch(select)
		{
		case 1:
			AddPerson(&abs);
			break;
		case 2:
			ShowPerson(&abs);
			break;
		case 3:
			DeletePerson(&abs);
			break;
		case 4:
			FindPerson(&abs);
			break;
		case 5:
			ModifyPerson(&abs);
			break;
		case 6:
			ClearPerson(&abs);
			break;
		case 0:
			cout << "欢迎下次输入！" << endl;
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}