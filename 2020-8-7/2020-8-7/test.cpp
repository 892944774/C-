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
	Data(const Data& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		cout << "Data(const Data& d):" << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

//以值的方式传递类类型的对象，在传参期间编译器会调用拷贝构造函数，构造一个临时对象
//缺陷：代码的运行效率低
void TestData1(Data dd)
{}

//一般情况下很少使用以值的方式传递类类型的参数，一般都是使用引用的方式作为参数类型
//优点：少了一次拷贝构造的调用，参数效率高
//缺点：修改形参就是改变外部实参
void TestData2(const Data& dd)
{}

Data TestData3()
{
	Data d;
	return d;
}

//在返回值期间，调用构造函数创建了一个匿名对象，因为该匿名对象没有名字，也拿不到该对象的地址，
//因此无法对其进行修改，因此编译器将匿名对象当成一个临时对象用来进行返回
Data TestData4()
{
	return Data(2020,8,8);//创建了一个没有名字的对象---匿名对象
}

int main()
{
	Data d(2020, 8, 8);
	TestData1(d);
	TestData3();
	TestData4();
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
	Data(const Data& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		cout << "Data(const Data& d):" << this << endl;
	}

	//执行的是前置++操作
	Data& operator++()
	{
		_day += 1;
		return *this;
	}

	//后置++
	//注意：temp是函数栈上的对象，当函数退出时，temp就要被销毁掉
	//因此后置++的函数返回值不能使用引用的方式进行返回，只能按照值的方式进行返回
	//语法为了区分后置++和前置++运算符重载的区别
	//最终在后置++的参数列表中增加了一个int类型的参数,在实际函数调用中int类型参数不会使用
	Data operator++(int)
	{
		Data temp(*this);
		_day += 1;
		return temp;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Data d1(2020, 8, 8);
	Data d2;

	d2 = ++d1;//d2 = d1.operator++();

	d2 = d1++;//相当于d2 = d1.operator++(0);
	return 0;
}
#endif

#if 0
//必须要有返回值：目的是为了支持连续赋值
Date& operator=(const Date& d)
{
	//避免自己给自己赋值--区分this和d是否是同一个对象
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return &*this;
}
#endif

//const修饰的变量
/*
在C语言中，被const修饰的是一个不能被修改的变量
测试：const int a = 10;  int array[a];//编译报错
在C++中，被const修饰的已经是一个常量，而且具有宏替换的属性
void TestConst()
{
	const int a = 10;
	int* pa = (int*)&a;

	*pa = 100;
	cout << a << endl;//10 但是a的值已经是100，原因是在编译阶段，编译器已经将a用10替换了
	cout << *pa << endl;//100
}
const修饰常量的替换发生在编译阶段，会参与参数类型的检测，代码的安全性更高。
在C++中建议使用const修饰的常量代替宏常量
*/

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//被const修饰的成员函数称为const类型的成员函数
	//const成员函数中不能修改类的“成员函数”
	//const本质上修饰的是成员函数隐藏的this指针
	//表示：this指针指向的空间中的内容不能被修改，即：this指向当前对象不能修改
	void PrintDate()const
	{
		
		cout << _year << "-" << _month << "-" << _day << endl;
		//_day++;//被const修饰，不能被修改
		cout << typeid(this).name() << endl;
	}

	//const在返回值类型之前，修饰的是该函数的返回值
	//普通成员函数中，可以修改this指向的当前对象的属性信息
	const Date& GetDate()
	{
		_day++;
		cout << typeid(this).name() << endl;
		return *this;
	}
	/*
	C++的人性化：
	理论上，被const修饰的成员函数中不能修改任何的"成员变量"，但有些情况下，可能需要在const成员函数中修改个别成员变量
	*/

private:
	int _year;
	int _month;
	int _day;
	//mutable int _day;
};

int main()
{
	Date d(2020,8,8);
	d.PrintDate();
	d.GetDate();
	return 0;
}
#endif

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	//Date* const this
	Date* operator&()
	{
		cout << this << endl;
		return this;
	}

	//const修饰成员函数，本质在修饰this指针
	//this指针类型：const Date* const this
	const Date* operator&()const
	{
		return this;
	}

	void SetDay(int day)
	{
		_day = day;
	}

	int GetDay()const
	{
		return _day;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	const Date d1(2020, 8, 8);
	d1.PrintDate();

	//d1是const类型的对象，即d1对象的成员不能被修改，假若调用了普通类型的成员函数，有可能被修改
	//因此const类型的对象只能调用const类型的成员函数，不能调用普通类型的成员函数
	//d1.SetDay(9);
	
	Date d2(2020,8,9);
	d2.GetDay(9);
	return 0;
}