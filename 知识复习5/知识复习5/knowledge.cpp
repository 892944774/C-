#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
#include <string>
#include "MyArray.hpp"
#include <vector>

#if 0
template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age);

	void showPerson();

	string _name;
	int _age;
};

//构造函数类外实现
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	_name = name;
	_age = age;
}

//成员函数类外实现
template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "测试" << endl;
}

int main()
{
	Person<string, int>p1("张森", 11);
	p1.showPerson();
	cout << p1._name << p1._age << endl;
	return 0;
}

//通过全局函数  打印Person信息
template<class T1, class T2>
class Person
{
	//全局函数  类内实现
	friend void showPerson(Person<T1, T2> p)
	{
		cout << p._age << p._name << endl;
	}

public:
	Person(T1 name, T2 age)
	{
		_name = name;
		_age = age;
	}

private:
	string _name;
	int _age;
};

int main()
{
	Person<string, int> p("张森", 11);
	showPerson(p);
	return 0;
}

int main()
{
	MyArray<int>arr1(5);
	MyArray<int>arr2(arr1);

	MyArray<int>arr3(100);
	arr3 = arr1;
	return 0;
}

int main()
{
	//创建一个vector容器
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	//通过迭代器来访问容器中的数据
	vector<int>::iterator itbegin = v.begin();
	vector<int>::iterator itend = v.end();

	//1.通过循环访问容器中的数据
	while (itbegin != itend)
	{
		cout << *itbegin << endl;
		itbegin++;
	}

	//2.利用for循环遍历容器中数据
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}
#endif

int main()
{
	//大容器
	vector<vector<int>> v;
	//小容器
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i+1);
		v2.push_back(i+2);
		v3.push_back(i+3);
		v4.push_back(i+4);
	}

	//将容器元素插入到vector中
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	//循环打印
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
	}
	return 0;
}