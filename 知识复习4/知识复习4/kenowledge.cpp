#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
#include <string>

#if 0
template<typename T>
void Swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 1;
	int b = 2;
	//1. �Զ������Ƶ�
	Swap(a, b);
	//2. ָ����ʾ����
	Swap<int>(a, b);
	return 0;
}

template<class T>
void Swap(T &a, T &b)
{
	int temp = a;
	a = b;
	b = temp;
}

template<class T>
void Sort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] > arr[j])
				Swap(arr[max], arr[j]);
		}
	}
}

int main()
{
	/*int arr[] = {9,2,3,6,5,1};
	int len = sizeof(arr)/sizeof(arr[0]);
	Sort(arr, len);

	for (int i = 0; i < len; i++)
	{
		cout << arr[i];
	}*/

	char arr[] = {"avseeg"};
	int len = sizeof(arr) / sizeof(arr[0]);

	Sort(arr, len);
	for (int i = 0; i < len; i++)
	{
		cout << arr[i];
	}
	return 0;
}

//��ͨ����
int Add(int a, int b)
{
	return a + b;
}

//����ģ��
template<class T>
int ADD(int a, int b)
{
	return a + b;
}

int main()
{
	//1.��ͨ�����ᷢ����ʽ����ת��
	/*int a = 1;
	int b = 2;
	char c = 'c';
	int ret = Add(a, c);
	cout << ret << endl;*/

	//2.�ڵ��ú���ģ��ʱ���Զ������Ƶ����ᷢ����ʽ����ת��
	//int a = 1;
	//int b = 2;
	//char c = 'c';
	//int ret = ADD(a, c);//err
	//cout << ret << endl;

	//3.��ʾ���ûᷢ����ʽ����ת��
	int a = 1;
	int b = 2;
	char c = 'c';
	int ret = ADD<int>(a, c);
	cout << ret << endl;
	return 0;
}

void Swap(int a, int b)
{
	cout << "��ͨ����" << endl;
}

template<class T>
void Swap(T a, T b)
{
	cout << "����ģ��" << endl;
}

int main()
{
	int a = 1;
	int b = 2;

	Swap(a, b);//��ͨ����
	Swap<>(a, b);//����ģ��
	Swap('a', 'b');//����ģ��ƥ����ţ����÷�����ʽ����ת��
	return 0;
}

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

//��ͨ����ģ��
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//���廯����ʾ���廯��ԭ�ͺͶ���˼��template<>��ͷ����ͨ��������ָ������
//���廯�����ڳ���ģ��
template<> bool myCompare(Person &p1, Person &p2)
{
	if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	Person p1("����", 1);
	Person p2("����", 2);
	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << "p1 == p2" << endl;
	}
	else
		cout << "p1 != p2" << endl;
	return 0;
}

//��ģ��
//��ģ�岻�ܷ�����ʽ����ת���������ڵ��õ�ʱ��ָ������
//��ģ����ģ������б��п���ָ��Ĭ�ϲ���
template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age)
	{
		_name = name;
		_age = age;
	}

	void show()
	{
		cout << _name << _age << endl;
	}

	T1 _name;
	T2 _age;
};

int main()
{
	Person<string, int> p1("����", 1);

	p1.show();
	return 0;
}
#endif

//��ģ���������������
template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age)
	{
		this->_name = name;
		this->_age = age;
	}

	void showperson()
	{
		cout << "showperson" << _name<<_age<<endl;
	}

	T1 _name;
	T2 _age;
};

//1.ָ����������
void printPerson(Person<string, int>&p)
{
	p.showperson();
}

//2. ����ģ�廯
template<class T1, class T2>
void printPerson2(Person<T1, T2>&p)
{
	p.showperson();
}

//3.������ģ�廯
template<class T>
void printPerson(T &p)
{
	p.showperson();
}

int main()
{
	Person<string, int>p("��ɭ", 11);
	printPerson(p);
	return 0;
}



