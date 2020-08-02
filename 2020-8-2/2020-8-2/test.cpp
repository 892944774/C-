#include <iostream>
using namespace std;

#if 0
class Data
{
public:
	//构造函数是一种特殊的成员函数，特殊有以下几点：
	//	1. 函数名和类名相同
	//  2. 无返回值，即使加void也不行
	//	3. 对象实例化时编译器自动调用对应的构造函数，并且在对象的生命周期内只调用一次
	//	4. 构造函数可以重载
	Data(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
		return; //return;该种写法表示，并没有返回值，函数直接从该位置退出
	}

	void SetData(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintData()
	{ 
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	//Data d1;
	//d1.SetData(2020, 8, 2);//实际调用Data::SetData(&d, 2020, 8, 2);
	//d1.PrintData();

	Data d2(2020, 8, 2);//定义对象并对其初始化--构造函数就是完成对其初始化
	d2.PrintData();
	return 0;
}
#endif

#if 0
//构造函数可以重载
class Data
{
public:
	//该构造函数只能创造带有三个参数的对象，不能创建无参的对象
	Data(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	Data()
	{
		_year = 1000;
		_month = 3;
		_day = 2;
	}

	void SetData(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintData()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Data d1(2020, 8, 2);
	d1.PrintData();

	Data d2(2020, 8, 3);
	
	Data d3;//该对象没有参数，所以应该创建无参的构造函数
	d3.PrintData();
	return 0;
}
#endif

#if 0
//全缺省的构造函数和无参的构造函数统称为默认的构造函数
//注意：全缺省的构造函数和无参的构造函数不能同时存在
class Data
{
public:
	Data(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	//无参的构造函数
	Data()
	{
		_year = 1000;
		_month = 3;
		_day = 2;
	}

	void SetData(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintData()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Data d1(2020, 8, 2);
	d1.PrintData();

	Data d2(2020, 8, 3);

	Data d3;//该对象没有参数，所以应该创建无参的构造函数
	d3.PrintData();
	return 0;
}
#endif

#if 0
class Time
{
public:
	Time(int hour = 0, int mintue = 0, int second = 0)
	{
		_hour = hour;
		_mintue = mintue;
		_second = second;
		cout << "Time(int,int,int)" << endl;
	}

private:
	int _hour;
	int _mintue;
	int _second;
};

class Data
{
public:
	void SetData(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	void PrintData()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;

	Time _t;
};

int main()
{
	Data d;//编译器最后会调用默认的构造函数，Time _t会调用自己内置类型的构造函数
}
#endif

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
private:
	// 基本类型(内置类型)
	int _year;
	int _month;
	int _day;
	// 自定义类型
	Time _t;
};
int main()
{
	Date d;
	return 0;
}