#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
#include <string>

#define MAX 1000

//�˵���ʾ
void showMenu()
{
	cout << "************************" << endl;
	cout << "***** 1.�����ϵ�� *****" << endl;
	cout << "***** 2.��ʾ��ϵ�� *****" << endl;
	cout << "***** 3.ɾ����ϵ�� *****" << endl;
	cout << "***** 4.������ϵ�� *****" << endl;
	cout << "***** 5.�޸���ϵ�� *****" << endl;
	cout << "***** 6.�����ϵ�� *****" << endl;
	cout << "***** 0.�˳���ϵ�� *****" << endl;
	cout << "************************" << endl;
}

//��ϵ��
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Number;
	string m_Addr;
};

//ͨѶ¼
struct AddrBooks
{
	struct Person personArray[MAX];//��ϵ������
	int m_Size = 0;//��ϵ�˸���
};

//�����ϵ��
void AddPerson(AddrBooks * abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "��ϵ��������" << endl;
		return;
	}
	else
	{
		//����
		string name;
		cout << "������������";
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1---����" << endl;
		cout << "2---Ů�� " << endl;
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
			cout << "����������������룡" << endl;
		}

		//����
		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//�绰
		string number;
		cout << "������绰��" << endl;
		cin >> number;
		abs->personArray[abs->m_Size].m_Number = number;

		//סַ
		string addr;
		cout << "�������ַ��" << endl;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;

		abs->m_Size++;
		cout << "ע����ϣ�" << endl;
	}
}

//��ʾ��ϵ��
void ShowPerson(AddrBooks * abs)
{
	if (abs->m_Size == 0)
		return;

	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << endl;
			cout << "�Ա�" << abs->personArray[i].m_Sex << endl;
			cout << "�绰��" << abs->personArray[i].m_Number << endl;
			cout << "���䣺" << abs->personArray[i].m_Age << endl;
			cout << "סַ��" << abs->personArray[i].m_Addr << endl;
		}
	}
}

//������ϵ���Ƿ����
int isExistPerson(AddrBooks * abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			cout << "��ϵ�˴��ڡ�" << endl;
			return i;
		}
	}
	cout << "��ϵ�˲����ڡ�" << endl;
	return -1;
}

void DeletePerson(AddrBooks * abs)
{
		cout << "��������Ҫɾ������ϵ��������" << endl;
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
	cout << "��������Ҫ���ҵ�������" << endl;
	string name;
	cin >> name;
	int ret = isExistPerson(abs, name);

	if (ret != -1)
	{
		cout << "������" << abs->personArray[ret].m_Name << endl;
	}
	else
	{
		cout << "δ�ҵ�����" << endl;
		return;
	}
}
void ModifyPerson(AddrBooks * abs)
{
	cout << "��������Ҫ�޸���ϵ�˵�������" << endl;
	string name;
	cin >> name;

	int ret = isExistPerson(abs, name);
	if (ret != -1)
	{
		string newname;
		cout << "������������";
		cin >> name;
		abs->personArray[ret].m_Name = newname;

		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1---����" << endl;
		cout << "2---Ů�� " << endl;
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
			cout << "����������������룡" << endl;
		}

		//����
		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//�绰
		string number;
		cout << "������绰��" << endl;
		cin >> number;
		abs->personArray[ret].m_Number = number;

		//סַ
		string addr;
		cout << "�������ַ��" << endl;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;

		cout << "�޸���ϣ�" << endl;
	}
}

void ClearPerson(AddrBooks * abs)
{
	abs->m_Size = 0;
}

int main()
{
	//����һ��ͨѶ¼����
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
			cout << "��ӭ�´����룡" << endl;
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}