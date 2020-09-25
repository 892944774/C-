#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <iostream>
using namespace std;

#if 0
//构造函数具有初始化列表的功能
//初始化列表作用就是完成类成员变量初始化工作
class Time
{
public:
	//注意：如果一个类没有显示定义任何构造函数，则编译器会生成一个默认的构造函数（无参的构造函数）
	//一旦用户定了，编译器就不会生成了
	//Time类不存在默认的构造函数
	Time(int hour, int minute, int second)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{
		cout << "Time(int,int,int)" << endl;
	}

private:
	int _hour;
	int _minute;
	int _second;
};

//如果一个类A中包含类B的对象，类B具有无参构造函数时，类A必须将其内部包含类B的对象
//在类A的初始化列表中进行初始化
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
		, ra(_day)
		，_t(0,0,0)//调用Time类的构造函数，对Time类中对象_t进行初始化
		
		//上面的都是初始化列表，下面的构造函数中函数体是赋值
	{
		//注意：构造函数本体是赋值而不是初始化
		/*_year = year;
		_month = month;
		_day = day;
		_day = 2020;*/
	}

	//成员列表在其中的声明次序就是其初始化次序
private:
	int _year;
	int _month;
	int _day;
	Time _t;

	int& ra;
};

int main()
{
	Date d(2020,9,25);
	return 0;
}
#endif

#if 0
class Time
{
public:
	Time(int hour, int minute, int second)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{
		cout << "Time(int,int,int)" << endl;
	}

private:
	int _hour; 
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year)
		: _year(year)
		, _month(1)
		, _day(1)
	{
		cout << "Date(int,int,int):" << this << endl;
	}

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}

	~Date()
	{
		cout << "~Date():" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d(2020);

	d = 2021;
	//问题：d是一个日期类的对象，2021只是一个整形类型的数据，如何进行赋值的
	/*
	1 使用2021调用单参类型的构造函数，构造一个匿名的对象（没有名字的对象）
	2 使用该匿名对象给d来进行赋值
	3 销毁匿名对象
	*/
	return 0;
}
#endif 

int count = 0;
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
		//, _count(0)
	{
		cout << "Date(int,int,int):" << this << endl;
		_count++;
	}

	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		_count++;
	}

	~Date()
	{
		--_count;
		cout << "~Date():" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
public:
	//静态成员变量在类中只是声明，必须要在类外进行定义
	static int _count;//静态成员变量
};

int Date::_count = 0;//静态成员变量
//静态成员变量和普通成员变量之间的区别
//静态成员变量必须要在类外进行初始化
//静态成员变量没有包含在对象中，每个对象都可以使用，所有类对象共享的，是类的属性
//静态成员变量不会影响一个类的大小
//静态成员变量通过对象.访问，也可以通过类名：：访问
//静态成员变量不能再构造函数初始化列表的位置初始化，因为构造函数列表位置初始化的都是包含在对象中的成员

void TestDate()
{
	Date d1(2020,9,25);
	Date d2(2020, 9, 25);
	Date d3(2020, 9, 25);
	Date d4(2020, 9, 25);

	Date d5(d1);
}

int main()
{
	TestDate();

	cout << Date::_count << endl;
	return 0;
}