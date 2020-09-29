#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

#if 0
class Time
{
public:
	Time()
	{
		cout << "Time()" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	} 

	//将私有的类成员变量变换成共有的，可以访问
	void setday(int day)
	{
		_day = day;
	}

	//静态成员函数
	//核心本质：静态成员函数没有this指针
	//不需要通过对象访问
	//不能访问非静态的成员变量
	//不能访问非静态的成员函数
	//不能使用const来修饰--》因为const本质在修饰this指针，静态成员函数没有this指针
	static int Getcount()
	{
		return _count;
	}

	bool operator>(const Date& d)const
	{
		if ((_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day))
			return true;
		else
			return false;
	}

	void operator<<(ostream& _cout)
	{
		_cout << _year << "-" << _month << "-"<< _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
	static int _count;//在类中只是声明
};

//静态成员变量必须在类外全局作用域中定义
int Date::_count = 0;

int main()
{ 
	Date d1(2020, 9, 13);
	Date d2(d1);
	cout << Date::Getcount() << endl;

	d1.setday(1);

	Date d(2020, 9, 26);
	//cout << d;
	d << cout;
	return 0;
}
#endif 

#if 0
//演示输出运算符不能重载成类的成员函数，因为调用的逻辑不相符
class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	bool operator>(const Date& d)const
	{
		if ((_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day))
			return true;
		else
			return false;
	}

	void operator<<(ostream& _cout)
	{
		_cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d(2020, 9, 26);
	//cout << d;
	d << cout;
	return 0;
}
#endif

#if 0
//不能重载成类的成员函数，可以重载为普通的全局函数
class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day; 
	}

private:
public:
	int _year;
	int _month;
	int _day;
};

//输出运算符重载必须有返回值，否则无法连续打印
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day << endl;
	return _cout;
}

int main()
{
	Date d(2020, 9, 26);
	Date d1(2020, 9, 29);
	cout << d;
	cout << d << d1;
	//operator<<(operatpr<<(cout, d), d1)
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	int Getyear()const
	{
		return _year;
	}

	int Getmonth()const
	{
		return _month;
	}

	int Getday()const
	{
		return _day;
	}

private:
	int _year;
	int _month;
	int _day;
};

//输出运算符重载必须有返回值，否则无法连续打印
ostream& operator<<(ostream& _cout, const Date& d)
{
	//_cout << d._year << "-" << d._month << "-" << d._day << endl;
	_cout << d.Getyear() << "-" << d.Getmonth() << "-" << d.Getday();
	return _cout;
}

int main()
{
	Date d(2020, 9, 26);
	cout << d;

	return 0;
}
#endif

class Date
{
	//注意：友元函数不是类的成员函数
	friend ostream& operator<<(ostream& _cout, const Date& d);
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	int Getyear()const
	{
		return _year;
	}

	int Getmonth()const
	{
		return _month;
	}

	int Getday()const
	{
		return _day;
	}

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	//_cout << d._year << "-" << d._month << "-" << d._day << endl;
	_cout << d.Getyear() << "-" << d.Getmonth() << "-" << d.Getday();
	return _cout;
}

int main()
{
	Date d(2020, 9, 26);
	cout << d;

	return 0;
}