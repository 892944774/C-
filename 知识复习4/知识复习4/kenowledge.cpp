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
	//1. 自动类型推导
	Swap(a, b);
	//2. 指定显示类型
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

//普通函数
int Add(int a, int b)
{
	return a + b;
}

//函数模板
template<class T>
int ADD(int a, int b)
{
	return a + b;
}

int main()
{
	//1.普通函数会发生隐式类型转化
	/*int a = 1;
	int b = 2;
	char c = 'c';
	int ret = Add(a, c);
	cout << ret << endl;*/

	//2.在调用函数模板时，自动类型推导不会发生隐式类型转换
	//int a = 1;
	//int b = 2;
	//char c = 'c';
	//int ret = ADD(a, c);//err
	//cout << ret << endl;

	//3.显示调用会发生隐式类型转化
	int a = 1;
	int b = 2;
	char c = 'c';
	int ret = ADD<int>(a, c);
	cout << ret << endl;
	return 0;
}

void Swap(int a, int b)
{
	cout << "普通函数" << endl;
}

template<class T>
void Swap(T a, T b)
{
	cout << "函数模板" << endl;
}

int main()
{
	int a = 1;
	int b = 2;

	Swap(a, b);//普通函数
	Swap<>(a, b);//函数模板
	Swap('a', 'b');//函数模板匹配更优，不用发生隐式类型转化
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

//普通函数模板
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

//具体化，显示具体化的原型和定意思以template<>开头，并通过名称来指出类型
//具体化优先于常规模板
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
	Person p1("张三", 1);
	Person p2("李四", 2);
	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << "p1 == p2" << endl;
	}
	else
		cout << "p1 != p2" << endl;
	return 0;
}

//类模板
//类模板不能发生隐式类型转化，必须在调用的时候指定类型
//类模板在模板参数列表中可以指定默认参数
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
	Person<string, int> p1("张三", 1);

	p1.show();
	return 0;
}
#endif

//类模板对象做函数参数
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

//1.指定传入类型
void printPerson(Person<string, int>&p)
{
	p.showperson();
}

//2. 参数模板化
template<class T1, class T2>
void printPerson2(Person<T1, T2>&p)
{
	p.showperson();
}

//3.整个类模板化
template<class T>
void printPerson(T &p)
{
	p.showperson();
}

int main()
{
	Person<string, int>p("张森", 11);
	printPerson(p);
	return 0;
}



