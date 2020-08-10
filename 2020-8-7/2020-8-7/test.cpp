#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

#if 0
class Data
{
public:
	Data(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//拷贝构造函数
	//特殊的构造函数，一定是单参的，参数必须是类类型对象的引用（一般情况下加const）
	//在使用已存在的对象创建新对象时，由编译器自动调用
	//一般拷贝不需要通过外部的形参改变外部的实参，最好用const进行修饰
	Data(const Data& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << this << ":" << &d << endl;
	}

	~Data()
	{
		//对于Data类析构函数写不写都无所谓，一般情况下我们都不写
		//因为析构函数一般清理当前对象中的资源，而Data类中没有涉及到资源管理
		//该析构函数看用户是否需要，用默认的或者自己给出
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Data d1(2020, 8, 7);
	
	//d1初识化d2
	//d2是新创建的对象，既然新创建了对象就需要调用构造函数 
	//因为是用已经存在的d1创建新对象d2，所以要调用拷贝构造函数
	Data d2(d1);
	return 0;
}
#endif

#if 0
class Data
{
public:
	Data(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Data d1(2020, 8, 7);

	//Data类没有显示提供拷贝构造函数，但是d2对象创建成功后，d2对象中的内容和d1对象中的内容相同
	//用已经存在对象d1拷贝构造新对象d2---调用的就是编译器生成的默认的拷贝构造函数
	//编译器给data类生成的默认的拷贝构造函数已经能够完成拷贝的构造
	//编译器生成拷贝构造函数：值得拷贝：将一个对象中的内容原封不动的拷贝到新对象中
	
	//对于Data类：使用编译器生成的默认构造函数没有问题
	//Data的拷贝构造函数写不写都可以
	Data d2(d1);
	return 0;
}
#endif

#if 0
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = (char*)malloc(strlen(str)+1);
		strcpy(_str, str);
	}

	~String()
	{
		if (_str)
			free(_str);
	}
	 
private:
	char* _str; 
};

int main()
{
	//用s1拷贝构造s2，肯定要调用拷贝构造函数
	//因为String类没有显示提供拷贝构造函数，则使用的是编译器生成的默认的拷贝构造函数
	//而默认的拷贝构造函数是按照值得方式进行拷贝，即：将s1对象中的内容原封不动的拷贝新对象中
	String s1("hello");
	String s2(s1);
	return 0;
}
#endif

#if 0
class Data
{
public:
	Data(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//isLess是一个成员函数，需要Data类型的对象进行调用
	//注意：isLess函数参数也可以是值的方式，只不过按照值的方式传参，在传参时按照值的方式进行，在传参时会创建一个临时对象，会影响运行效率
	//一般情况下：类类型作为函数的参数时，一般都是按照引用的方式进行传参，如果不需要通过形参改变外部实参，需要加上const
	bool isLess(const Data& d)
	{
		if ((_year < d._year) || (_year == d._year && _month < d._month)
			|| (_year == d._year && _month == d._month && _day < d._day))
		{
			return true;
		}
		return false;
	}

	//< 运算符的重载
	bool operator<(const Data& d)
	{
		if ((_year < d._year) || (_year == d._year && _month < d._month)
			|| (_year == d._year && _month == d._month && _day < d._day))
		{
			return true;
		}
		return false;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Data d1(2020, 8, 7);
	Data d2(2020, 8, 8);

	//Data是用户自定义的类型，自定义类型包含多个成员变量，编译器不知道按照什么规则进行比较
	//1.告诉编译器如何对日期类型的对象进行比较，对<进行运算符重载
	if (d1 < d2)
		cout << "d1 < d2" << endl;

	//2. 提供了一个公有的函数来进行比较
	if (d1.isLess(d2))
	{
		cout << "d1 < d2" << endl;
	}
	return 0;
}
#endif

#if 0
class Data
{
public:
	Data(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//==重载
	bool operator==(const Data& d)
	{
		return _year == d._year &&
			   _month == d._month &&
			   _day == d._day;
	}

	//!=重载
	bool operator!=(const Data& d)
	{
		return !(*this == d);
	}
private:
	int _year;
	int _month;
	int _day;
};

//全局变量中的操作数
//+：有两个操作数，函数必须要提供两个操作数
//+左右两侧如果都是int类型的数据，编译器本来就支持，再进行重载就多此一举，而且还形成了无限的递归
//因此在进行运算符重载时，必须有一个类类型或者枚举类型的参数
//int operator+(int left, int right)
//{
//	return left + right;
//}

enum DATA {ONE, TOW, THREE};

int opertaor + (DATA op1, int op2)
{
	return op1 + op2;
}

int main()
{
	Data d1(2020, 8, 7);
	Data d2(d1);

	if (d1 == d2)
		cout << "d1 == d2" << endl;
	else
		cout << "d1 != d2" << endl;
}
#endif
class Data
{
public:
	Data(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Data d1(2020, 8, 7);
	Data d2(2020, 8, 8);

	d2 = d1;
	return 0;
}