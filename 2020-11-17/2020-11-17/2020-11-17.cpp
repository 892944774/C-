#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

#include <queue>

#if 0
int main()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	cout << q.front() << endl;//1
	cout << q.size() << endl;//5

	q.front() = 0;
	cout << q.front() << endl;//0
	cout << q.back() << endl;//5
	return 0;
}
#endif

#if 0
int main()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	cout << q.front() << endl;//1
	cout << q.size() << endl;//5

	q.front() = 0;
	cout << q.front() << endl;//0
	cout << q.back() << endl;//5
	return 0;
}
#endif

#include <vector>
#include <functional>
#if 0
int main()
{
	//默认是按照小于less的方式进行比较,创建的是大堆
	priority_queue<int> q1;

	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	q1.push(5);
	q1.push(6);
	cout << q1.top() << endl;
	cout << q1.size() << endl;

	q1.pop();
	cout << q1.top() << endl;
	cout << q1.size() << endl;

	vector<int> v{1,2,3,4,5};
	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());

	cout << q2.top() << endl;
	return 0;
}
#endif

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	bool operator<(const Date& d)const
	{
		return _day < d._day;
	}

	bool operator>(const Date& d)const
	{
		return _day > d._day;
	}


	int _year;
	int _month;
	int _day;
};

//仿函数/函数对象--可以像函数一样使用的对象
//原理：只需要在类中将（）重载一下
//（）称为函数调用运算符
//作用：定制算法功能
class Greater
{
public:
	bool operator()(const Date* left, const Date* right)
	{
		return left->_day > right->_day;
	}
};

bool gg(const Date* left, const Date* right)
{
	return left->_day < right->_day;
}

#if 0
int main()
{
	Date* p1 = new Date(2020, 1, 1);
	Date* p2 = new Date(2020, 1, 2);
	Date* p3 = new Date(2020, 1, 3);
	
	gg(p1, p2);//gg是一个函数名，函数调用
	Greater g;
	g(p1, p2);//g是一个对象，也是函数调用
	return 0;
}
#endif 

#include <algorithm>
struct Goods
{
	Goods(const string& name, double price)
		: _name(name)
		, _price(price)
	{}

	bool operator<(const Goods& g)const
	{
		return _price < g._price;
	}

	bool operator>(const Goods& g)const
	{
		return _price > g._price;
	}

	string _name;
	double _price;
};

struct Greater
{
	bool operator()(const Goods& g1, const Goods& g2)
	{
		return g1._price > g2._price;
	}
};

int main()
{
	//默认的是按照小于的方式比较--》升序
	vector<int> v{2,3,4,5,1,6,7,8,9};
	sort(v.begin(), v.end());

	//按照greater进行比较--》降序
	//greater<int>()，创建一个greater<int>类型的匿名对象
	sort(v.begin(), v.end(), greater<int>());

	Goods gs[] = { { "apple", 2.5 },{ "banana", 1.8 },{ "orange", 3.2 } };

	sort(gs, gs+sizeof(gs)/sizeof(gs[0]));
	sort(gs, gs + sizeof(gs) / sizeof(gs[0]), greater<Goods>());
	return 0;
}


#include "priority_queue.h"
int main()
{
	vector<int> v{3,2,4,5,1};
	bite::priority_queue<int> q{ v.begin(), v.end() };
	q.push(0);

	return 0;
}